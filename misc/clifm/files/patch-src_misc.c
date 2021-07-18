--- src/misc.c.orig	2021-05-29 06:04:35 UTC
+++ src/misc.c
@@ -31,6 +31,10 @@
 #include <stdio.h>
 #include <string.h>
 #include <sys/stat.h>
+#if defined(__FreeBSD__)
+#include <sys/mount.h>
+#include <sys/sysctl.h>
+#endif
 #include <time.h>
 #include <unistd.h>
 #include <readline/readline.h>
@@ -255,9 +259,16 @@ new_instance(char *dir, int sudo)
 	}
 
 	/* Get absolute path of executable name of itself */
+#if defined(__linux__)
 	char *self = realpath("/proc/self/exe", NULL);
 
 	if (!self) {
+#elif defined(__FreeBSD__)
+	const int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
+	char *self = malloc(PATH_MAX);
+	size_t len = PATH_MAX;
+	if (!self || sysctl(mib, 4, self, &len, NULL, 0) == -1) {
+#endif
 		fprintf(stderr, "%s: %s\n", PROGRAM_NAME, strerror(errno));
 		return EXIT_FAILURE;
 	}
@@ -812,6 +823,7 @@ set_shell(char *str)
 int
 list_mountpoints(void)
 {
+#if defined(__linux__)
 	FILE *mp_fp = fopen("/proc/mounts", "r");
 
 	if (!mp_fp) {
@@ -819,13 +831,15 @@ list_mountpoints(void)
 				PROGRAM_NAME, strerror(errno));
 		return EXIT_FAILURE;
 	}
+#endif
 
 	printf(_("%sMountpoints%s\n\n"), bold, df_c);
 
 	char **mountpoints = (char **)NULL;
 	size_t mp_n = 0;
-	int exit_status = EXIT_SUCCESS;
+	int i, j, exit_status = EXIT_SUCCESS;
 
+#if defined(__linux__)
 	size_t line_size = 0;
 	char *line = (char *)NULL;
 	ssize_t line_len = 0;
@@ -870,6 +884,10 @@ list_mountpoints(void)
 	free(line);
 	line = (char *)NULL;
 	fclose(mp_fp);
+#elif defined(__FreeBSD__)
+	struct statfs *fslist;
+	mp_n = getmntinfo(&fslist, MNT_NOWAIT);
+#endif
 
 	/* This should never happen: There should always be a mountpoint,
 	 * at least "/" */
@@ -877,6 +895,26 @@ list_mountpoints(void)
 		fputs(_("mp: There are no available mountpoints\n"), stdout);
 		return EXIT_SUCCESS;
 	}
+#if defined(__FreeBSD__)
+	for (i = j = 0; i < mp_n; i++) {
+		/* Do not list all mountpoints, but only those corresponding
+		 * to a block device (/dev) */
+		if (strncmp(fslist[i].f_mntfromname, "/dev/", 5) == 0) {
+			printf("%s%u%s %s%s%s (%s)\n", el_c, j + 1, df_c,
+			    (access(fslist[i].f_mntonname, R_OK | X_OK)
+			    == 0) ? di_c : nd_c, fslist[i].f_mntonname,
+			    df_c, fslist[i].f_mntfromname);
+			/* Store the mountpoint into an array */
+			mountpoints = (char **)xrealloc(mountpoints,
+			    (j + 1) * sizeof(char *));
+			mountpoints[j++] = savestring(fslist[i].f_mntonname,
+			    strlen(fslist[i].f_mntonname));
+		}
+	}
+	/* Update filesystem counter as it would be used to free() the
+	 * mountpoints entries later (below) */
+	mp_n = j;
+#endif
 
 	putchar('\n');
 	/* Ask the user and chdir into the selected mountpoint */
@@ -922,7 +960,7 @@ list_mountpoints(void)
 	/* Free stuff and exit */
 	free(input);
 
-	int i = (int)mp_n;
+	i = (int)mp_n;
 	while (--i >= 0)
 		free(mountpoints[i]);
 
