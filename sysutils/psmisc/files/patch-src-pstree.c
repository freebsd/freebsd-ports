--- src/pstree.c.orig	2009-12-27 15:46:47.000000000 +0900
+++ src/pstree.c	2010-01-03 00:52:21.437862505 +0900
@@ -37,6 +37,7 @@
 #include <term.h>
 #include <termios.h>
 #include <langinfo.h>
+#include <limits.h>
 #include <assert.h>
 #include <sys/types.h>
 #include <sys/stat.h>
@@ -590,7 +591,11 @@
   struct dirent *de;
   FILE *file;
   struct stat st;
+#ifdef __FreeBSD__
+  char *path, comm[COMM_LEN + 1];
+#else
   char *path, *comm;
+#endif
   char *buffer;
   size_t buffer_size;
   char readbuf[BUFSIZ + 1];
@@ -623,7 +628,7 @@
     if ((pid = (pid_t) atoi(de->d_name)) != 0) {
       if (! (path = malloc(strlen(PROC_BASE) + strlen(de->d_name) + 10)))
         exit(2);
-      sprintf(path, "%s/%d/stat", PROC_BASE, pid);
+      sprintf (path, "%s/%d/status", PROC_BASE, pid);
       if ((file = fopen(path, "r")) != NULL) {
         empty = 0;
         sprintf(path, "%s/%d", PROC_BASE, pid);
@@ -638,6 +643,10 @@
           perror(path);
           exit(1);
         }
+#ifdef __FreeBSD__
+        if (fscanf(file, "%s %*d %d", comm, &ppid) == 2)
+          add_proc(comm, pid, ppid, st.st_uid, NULL, 0, 0);
+#else
         size = fread(readbuf, 1, BUFSIZ, file);
         if (ferror(file) == 0) {
           readbuf[size] = 0;
@@ -725,6 +734,7 @@
             }
           }
         }
+#endif /*__FreeBSD__*/
         (void) fclose(file);
       }
       free(path);
