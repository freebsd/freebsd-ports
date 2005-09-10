--- src/killall.c.orig	Fri Apr 23 15:51:26 2004
+++ src/killall.c	Sat Sep 10 03:55:48 2005
@@ -80,7 +80,7 @@
   struct dirent *de;
   FILE *file;
   struct stat st, sts[MAX_NAMES];
-  int *name_len;
+  int *name_len = 0;
   char *path, comm[COMM_LEN];
   char *command_buf;
   char *command;
@@ -171,7 +171,7 @@
     }
   for (i = 0; i < pids; i++)
     {
-      if (asprintf (&path, PROC_BASE "/%d/stat", pid_table[i]) < 0)
+      if (asprintf (&path, PROC_BASE "/%d/status", pid_table[i]) < 0)
 	continue;
       if (!(file = fopen (path, "r"))) 
 	{
@@ -180,72 +180,13 @@
 	}
       free (path);
       empty = 0;
-      okay = fscanf (file, "%*d (%[^)]", comm) == 1;
+      okay = fscanf (file, "%s", comm) == 1;
       (void) fclose (file);
       if (!okay)
 	continue;
       got_long = 0;
       command = NULL;		/* make gcc happy */
       length = strlen (comm);
-      if (length == COMM_LEN - 1)
-	{
-	  if (asprintf (&path, PROC_BASE "/%d/cmdline", pid_table[i]) < 0)
-	    continue;
-	  if (!(file = fopen (path, "r"))) {
-	    free (path);
-	    continue;
-	  }
-	  free (path);
-          while (1) {
-            /* look for actual command so we skip over initial "sh" if any */
-            char *p;
-	    int cmd_size = 128;
-	    command_buf = (char *)malloc (cmd_size);
-	    if (!command_buf)
-	      exit (1);
-
-            /* 'cmdline' has arguments separated by nulls */
-            for (p=command_buf; ; p++) {
-              int c;
-	      if (p == (command_buf + cmd_size)) 
-		{
-		  int cur_size = cmd_size;
-		  cmd_size *= 2;
-		  command_buf = (char *)realloc(command_buf, cmd_size);
-		  if (!command_buf)
-		    exit (1);
-		  p = command_buf + cur_size;
-		}
-              c = fgetc(file);
-              if (c == EOF || c == '\0') {
-                *p = '\0';
-                break;
-              } else {
-                *p = c;
-              }
-            }
-            if (strlen(command_buf) == 0) {
-              okay = 0;
-              break;
-            }
-            p = strrchr(command_buf,'/');
-            p = p ? p+1 : command_buf;
-            if (strncmp(p, comm, COMM_LEN-1) == 0) {
-              okay = 1;
-              command = p;
-              break;
-            }
-          }
-          (void) fclose(file);
-	  if (exact && !okay)
-	    {
-	      if (verbose)
-		fprintf (stderr, _("skipping partial match %s(%d)\n"), comm,
-			 pid_table[i]);
-	      continue;
-	    }
-	  got_long = okay;
-	}
       for (j = 0; j < names; j++)
 	{
 	  pid_t id;
@@ -279,7 +220,7 @@
 	    }
 	  else
 	    {
-	      if (asprintf (&path, PROC_BASE "/%d/exe", pid_table[i]) < 0)
+	      if (asprintf (&path, PROC_BASE "/%d/file", pid_table[i]) < 0)
 		continue;
 #ifdef FLASK_LINUX
           if (stat_secure(path,&st,&lsid) < 0) {
@@ -355,6 +296,7 @@
 	fprintf (stderr, _("%s: no process killed\n"), namelist[i]);
   if (pidof)
     putchar ('\n');
+    return 0;
   error = found == ((1 << (names - 1)) | ((1 << (names - 1)) - 1)) ? 0 : 1;
   /*
    * We scan all (supposedly) killed processes every second to detect dead
