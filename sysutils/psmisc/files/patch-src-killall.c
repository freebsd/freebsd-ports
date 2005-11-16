--- src/killall.c.orig	Tue Sep 20 05:31:38 2005
+++ src/killall.c	Wed Nov 16 17:40:13 2005
@@ -59,35 +59,31 @@
            quiet = 0, wait_until_dead = 0, process_group = 0,
            ignore_case = 0, pidof;
 
+/*
+ * This is the implementation from 21.5, as the one in 21.6 and newer uses
+ * Linux specific functions getline() and rpmatch()
+ */
 static int
 ask (char *name, pid_t pid)
 {
-  int res;
-  size_t len;
-  char *line;
-
-  line = NULL;
-  len = 0;
-
-  do {
-    printf (_("Kill %s(%s%d) ? (y/N) "), name, process_group ? "pgid " : "",
-	    pid);
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
+  int ch, c;
+
+  do
+    {
+      printf (_("Kill %s(%s%d) ? (y/n) "), name, process_group ? "pgid " : "",
+	      pid);
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
 
 static int
@@ -267,7 +263,7 @@
         }
 #endif /*WITH_SELINUX*/
       /* load process name */
-      if (asprintf (&path, PROC_BASE "/%d/stat", pid_table[i]) < 0)
+      if (asprintf (&path, PROC_BASE "/%d/status", pid_table[i]) < 0)
 	continue;
       if (!(file = fopen (path, "r"))) 
 	{
@@ -275,72 +271,13 @@
 	  continue;
 	}
       free (path);
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
       /* mach by process name */
       for (j = 0; j < names; j++)
 	{
@@ -372,7 +309,7 @@
 	        }
 	      else
 	        {
-	          if (asprintf (&path, PROC_BASE "/%d/exe", pid_table[i]) < 0)
+	          if (asprintf (&path, PROC_BASE "/%d/file", pid_table[i]) < 0)
 		    continue;
 
 	          if (stat (path, &st) < 0) 
@@ -697,7 +634,7 @@
       fprintf (stderr, _("Maximum number of names is %d\n"), MAX_NAMES);
       exit (1);
     }
-  if (stat("/proc/self/stat", &isproc)==-1)
+  if (stat("/proc/curproc/status", &isproc)==-1)
     {
       fprintf (stderr, _("%s is empty (not mounted ?)\n"), PROC_BASE);
       exit (1);
