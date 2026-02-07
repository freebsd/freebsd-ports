--- src/pstree.c.orig	2012-02-19 23:07:14 UTC
+++ src/pstree.c
@@ -37,6 +37,9 @@
 #include <term.h>
 #include <termios.h>
 #include <langinfo.h>
+#if defined __FreeBSD__ || defined __DragonFly__
+#include <limits.h>
+#endif
 #include <assert.h>
 #include <sys/types.h>
 #include <sys/stat.h>
@@ -609,7 +612,11 @@ static void read_proc(void)
   struct dirent *de;
   FILE *file;
   struct stat st;
+#if defined __FreeBSD__ || defined __DragonFly__
+  char *path, comm[COMM_LEN + 1];
+#else
   char *path, *comm;
+#endif
   char *buffer;
   size_t buffer_size;
   char readbuf[BUFSIZ + 1];
@@ -642,7 +649,11 @@ static void read_proc(void)
     if ((pid = (pid_t) atoi(de->d_name)) != 0) {
       if (! (path = malloc(strlen(PROC_BASE) + strlen(de->d_name) + 10)))
         exit(2);
+#if defined __FreeBSD__ || defined __DragonFly__
+      sprintf(path, "%s/%d/status", PROC_BASE, pid);
+#else
       sprintf(path, "%s/%d/stat", PROC_BASE, pid);
+#endif
       if ((file = fopen(path, "r")) != NULL) {
         empty = 0;
         sprintf(path, "%s/%d", PROC_BASE, pid);
@@ -657,6 +668,29 @@ static void read_proc(void)
           perror(path);
           exit(1);
         }
+#if defined __FreeBSD__ || defined __DragonFly__
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
@@ -711,6 +745,7 @@ static void read_proc(void)
                   (void) closedir(taskdir);
                 }
               free(taskpath);
+#endif /*__FreeBSD__ || __DragonFly__ */
               if (!print_args)
 #ifdef WITH_SELINUX
                 add_proc(comm, pid, ppid, st.st_uid, NULL, 0, 0, scontext);
