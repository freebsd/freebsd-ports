--- src/killall.c.orig	2009-12-18 21:45:36.000000000 +0900
+++ src/killall.c	2010-01-03 00:37:34.818411284 +0900
@@ -36,6 +36,8 @@
 #include <dirent.h>
 #include <signal.h>
 #include <errno.h>
+#include <limits.h>
+#include <locale.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <getopt.h>
@@ -83,40 +85,35 @@
            ignore_case = 0, pidof;
 static long younger_than = 0, older_than = 0;
 
+ /*
+  * This is based on the implementation from 21.5, as the one in 21.6
+  * and newer uses Linux specific functions getline() and rpmatch()
+  */
 static int
 ask (char *name, pid_t pid, const int signal)
 {
-  int res;
-  size_t len;
-  char *line;
-
-  line = NULL;
-  len = 0;
-
-  do {
-    if (signal == SIGTERM)
-        printf (_("Kill %s(%s%d) ? (y/N) "), name, process_group ? "pgid " : "",
-	        pid);
-    else
-        printf (_("Signal %s(%s%d) ? (y/N) "), name, process_group ? "pgid " : "",
-	        pid);
+  int ch, c;
 
-    fflush (stdout);
-
-    if (getline (&line, &len, stdin) < 0)
-      return 0;
-    /* Check for default */
-    if (line[0] == '\n') {
-      free(line);
-      return 0;
-    }
-    res = rpmatch(line);
-    if (res >= 0) {
-      free(line);
-      return res;
+  do
+    {
+      if (signal == SIGTERM)
+          printf (_("Kill %s(%s%d) ? (y/N) "), name, process_group ? "pgid " : "",
+                  pid);
+      else
+          printf (_("Signal %s(%s%d) ? (y/N) "), name, process_group ? "pgid " : "",
+                  pid);
+      fflush (stdout);
+      do
+	if ((ch = getchar ()) == EOF)
+	  exit (0);
+      while (ch == '\n' || ch == '\t' || ch == ' ');
+      do
+	if ((c = getchar ()) == EOF)
+	  exit (0);
+      while (c != '\n');
     }
-  } while(1);
-  /* Never should get here */
+  while (ch != 'y' && ch != 'n' && ch != 'Y' && ch != 'N');
+  return ch == 'y' || ch == 'Y';
 }
 
 static double
@@ -356,7 +353,7 @@
         }
 #endif /*WITH_SELINUX*/
       /* load process name */
-      if (asprintf (&path, PROC_BASE "/%d/stat", pid_table[i]) < 0)
+      if (asprintf (&path, PROC_BASE "/%d/status", pid_table[i]) < 0)
 	continue;
       if (!(file = fopen (path, "r"))) 
 	{
@@ -364,7 +361,7 @@
 	  continue;
 	}
       free (path);
-      okay = fscanf (file, "%*d (%15[^)]", comm) == 1;
+      okay = fscanf (file, "%s", comm) == 1;
       if (!okay) {
 	fclose(file);
 	continue;
@@ -386,65 +383,6 @@
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
       /* mach by process name */
       for (j = 0; j < names; j++)
 	{
@@ -495,7 +433,7 @@
 	        {
 		  int ok = 1;
 
-	          if (asprintf (&path, PROC_BASE "/%d/exe", pid_table[i]) < 0)
+	          if (asprintf (&path, PROC_BASE "/%d/file", pid_table[i]) < 0)
 		    continue;
 
 	          if (stat (path, &st) < 0) 
@@ -842,7 +780,7 @@
     fprintf (stderr, _("Maximum number of names is %d\n"), MAX_NAMES);
     exit (1);
   }
-  if (stat("/proc/self/stat", &isproc)==-1) {
+  if (stat("/proc/curproc/status", &isproc)==-1) {
     fprintf (stderr, _("%s is empty (not mounted ?)\n"), PROC_BASE);
     exit (1);
   }
