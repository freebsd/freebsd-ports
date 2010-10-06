--- src/pstree.c.orig	2009-12-27 15:46:47.000000000 +0900
+++ src/pstree.c	2010-01-03 00:52:21.437862505 +0900
@@ -37,6 +37,9 @@
 #include <term.h>
 #include <termios.h>
 #include <langinfo.h>
+#ifdef __FreeBSD__
+#include <limits.h>
+#endif
 #include <assert.h>
 #include <sys/types.h>
 #include <sys/stat.h>
@@ -590,7 +594,11 @@
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
@@ -623,7 +631,11 @@
     if ((pid = (pid_t) atoi(de->d_name)) != 0) {
       if (! (path = malloc(strlen(PROC_BASE) + strlen(de->d_name) + 10)))
         exit(2);
+#ifdef __FreeBSD__
+      sprintf(path, "%s/%d/status", PROC_BASE, pid);
+#else
       sprintf(path, "%s/%d/stat", PROC_BASE, pid);
+#endif
       if ((file = fopen(path, "r")) != NULL) {
         empty = 0;
         sprintf(path, "%s/%d", PROC_BASE, pid);
@@ -638,6 +650,29 @@
           perror(path);
           exit(1);
         }
+#ifdef __FreeBSD__
+        /* Read comm and ppid */
+        if (fscanf(file, "%s %*d %d", readbuf, &ppid) == 2) {
+          tmpptr = readbuf;
+          size = 0;
+          /* Unescape comm */
+          do {
+            if (*tmpptr == '\\')
+            {
+              char tmp = tmpptr[4];
+              tmpptr[4] = 0;
+              comm[size++] = strtol(++tmpptr, NULL, 8);
+              tmpptr += 2;
+              tmpptr[1] = tmp;
+            }
+            else
+              comm[size++] = *tmpptr;
+          } while (*++tmpptr);
+          comm[size] = 0;
+          /* Balance braces */
+          {
+            {
+#else
         size = fread(readbuf, 1, BUFSIZ, file);
         if (ferror(file) == 0) {
           readbuf[size] = 0;
@@ -692,6 +727,7 @@
                   (void) closedir(taskdir);
                 }
               free(taskpath);
+#endif /*__FreeBSD__*/
               if (!print_args)
 #ifdef WITH_SELINUX
                 add_proc(comm, pid, ppid, st.st_uid, NULL, 0, 0, scontext);
