--- src/afuse.c.orig	2009-03-03 13:17:22.000000000 +0900
+++ src/afuse.c	2009-03-03 13:17:27.000000000 +0900
@@ -36,7 +36,6 @@
 #include <string.h>
 #include <stddef.h>
 #include <unistd.h>
-#include <alloca.h>
 #include <fcntl.h>
 #include <dirent.h>
 #include <errno.h>
@@ -280,14 +280,19 @@
 }
 
 
-// !!FIXME!! allow escaping of %'s
 // Note: this method strips out quotes and applies them itself as should be appropriate
-char *expand_template(const char *template, const char *mount_point, const char *root_name)
+bool run_template(const char *template, const char *mount_point, const char *root_name)
 {
 	int len = 0;
+	int nargs = 1;
 	int i;
-	char *expanded_name;
-	char *expanded_name_start;
+	char *buf;
+	char *p;
+	char **args;
+	char **arg;
+	bool quote = false;
+	pid_t pid;
+	int status;
 
 	// calculate length
 	for(i = 0; template[i]; i++)
@@ -295,53 +300,100 @@
 			switch(template[i + 1])
 			{
 				case 'm':
-					len += strlen(mount_point) + 2;
+					len += strlen(mount_point);
 					i++;
 					break;
 				case 'r':
-					len += strlen(root_name) + 2;
+					len += strlen(root_name);
+					i++;
+					break;
+				case '%':
+					len++;
 					i++;
 					break;
 			}
-		} else if(template[i] != '"')
+		} else if(template[i] == ' ' && !quote) {
+			len++;
+			nargs++;
+		} else if(template[i] == '"')
+			quote = !quote;
+		else if(template[i] == '\\' && template[i + 1])
+			len++, i++;
+		else
 			len++;
 
-	expanded_name_start = expanded_name = my_malloc(len + 1);
+	buf = my_malloc(len + 1);
+	args = my_malloc((nargs + 1) * sizeof(*args));
+
+	p = buf;
+	arg = args;
+	*arg++ = p;
 
 	for(i = 0; template[i]; i++)
 		if(template[i] == '%') {
-			int j = 0;
 			switch(template[i + 1])
 			{
 				case 'm':
-					*expanded_name++ = '"';
-					while(mount_point[j])
-						*expanded_name++ = mount_point[j++];
-					*expanded_name++ = '"';
+					strcpy(p, mount_point);
+					p += strlen(mount_point);
 					i++;
 					break;
 				case 'r':
-					*expanded_name++ = '"';
-					while(root_name[j])
-						*expanded_name++ = root_name[j++];
-					*expanded_name++ = '"';
+					strcpy(p, root_name);
+					p += strlen(root_name);
+					i++;
+					break;
+				case '%':
+					*p++ = '%';
 					i++;
 					break;
 			}
-		} else if(template[i] != '"')
-			*expanded_name++ = template[i];
-
-	*expanded_name = '\0';
-
-	return expanded_name_start;
+		} else if(template[i] == ' ' && !quote) {
+			*p++ = '\0';
+			*arg++ = p;
+		} else if(template[i] == '"')
+			quote = !quote;
+		else if(template[i] == '\\' && template[i + 1])
+			*p++ = template[++i];
+		else
+			*p++ = template[i];
+
+	*p = '\0';
+	*arg = NULL;
+
+	pid = fork();
+	if(pid == -1) {
+		fprintf(stderr, "Failed to fork (%s)\n", strerror(errno));
+		free(args);
+		free(buf);
+		return false;
+	}
+	if(pid == 0) {
+		execvp(args[0], args);
+		abort();
+	}
+	pid = waitpid(pid, &status, 0);
+	if(pid == -1) {
+		fprintf(stderr, "Failed to waitpid (%s)\n", strerror(errno));
+		free(args);
+		free(buf);
+		return false;
+	}
+	if(!WIFEXITED(status) || WEXITSTATUS(status) != 0) {
+		fprintf(stderr, "Failed to invoke command: %s\n", args[0]);
+		free(args);
+		free(buf);
+		return false;
+	}
+	free(args);
+	free(buf);
+	return true;
 }
 
 mount_list_t *do_mount(const char *root_name)
 {
 	char *mount_point;
-	char *mount_command;
 	mount_list_t *mount;
-	int sysret;
 
 	fprintf(stderr, "Mounting: %s\n", root_name);
 
@@ -351,57 +403,33 @@
 		return NULL;
 	}
 
-	mount_command = expand_template(user_options.mount_command_template,
-	                                mount_point, root_name);
-	sysret = system(mount_command);
-
-	fprintf(stderr, "sysret: %.8x\n", sysret);
-
-	if(sysret) {
-		fprintf(stderr, "Failed to invoke mount command: '%s' (%s)\n",
-			mount_command, sysret != -1 ?
-				"Error executing mount" :
-				strerror(errno));
-
+	if(!run_template(user_options.mount_command_template,
+			 mount_point, root_name)) {
 		// remove the now unused directory
 		if( rmdir(mount_point) == -1 )
 			fprintf(stderr, "Failed to remove mount point dir: %s (%s)",
 				mount_point, strerror(errno));
 
-		free(mount_command);
 		free(mount_point);
 		return NULL;
 	}
 
 	mount = add_mount(root_name, mount_point);
-
-	free(mount_command);
 	return mount;
 }
 
 int do_umount(mount_list_t *mount)
 {
-	char *unmount_command;
-	int sysret;
-
 	fprintf(stderr, "Unmounting: %s\n", mount->root_name);
 
-	unmount_command = expand_template(user_options.unmount_command_template,
-	                                  mount->mount_point, mount->root_name);
-	sysret = system(unmount_command);
-	if(sysret) {
-		fprintf(stderr, "Failed to invoke unmount command: '%s' (%s)\n",
-		        unmount_command, sysret != -1 ?
-			               "Error executing mount" :
-				       strerror(errno));
-		/* Still unmount anyway */
-	}
+	run_template(user_options.unmount_command_template,
+		     mount->mount_point, mount->root_name);
+	/* Still unmount anyway */
 
 	if( rmdir(mount->mount_point) == -1 )
 		fprintf(stderr, "Failed to remove mount point dir: %s (%s)",
 				mount->mount_point, strerror(errno));
 	remove_mount(mount);
-	free(unmount_command);
 	return 1;
 }
 
@@ -1504,7 +1504,8 @@
 	fuse_opt_add_arg(&args, "-s");
 
 	// Adjust user specified timeout from seconds to microseconds as required
-	user_options.auto_unmount_delay *= 1000000;
+	if(user_options.auto_unmount_delay != UINT64_MAX)
+	    user_options.auto_unmount_delay *= 1000000;
 
 	auto_unmount_ph_init(&auto_unmount_ph);
 
