--- ktalkd/ktalkd/find_user.cpp
+++ ktalkd/ktalkd/find_user.cpp
@@ -339,34 +339,33 @@
 
 #else  /*not PROC_FIND_USER*/
 
+#include <utmpx.h>
+
 int find_user(char *name, char *tty, char *disp) {
 
-    struct utmp ubuf;
+    struct utmpx *ubuf;
     int status;
-    FILE *fd;
     struct stat statb;
-    char ftty[20+UT_LINESIZE];
-    char ttyFound[UT_LINESIZE] = "";
-    char dispFound[UT_HOSTSIZE+1] = "";
-
-    if (!(fd = fopen(_PATH_UTMP, "r"))) {
-        fprintf(stderr, "talkd: can't read %s.\n", _PATH_UTMP);
-        return (FAILED);
-    }
+    char ftty[20 + sizeof ubuf->ut_line];
+    char ttyFound[sizeof ubuf->ut_line] = "";
+    char dispFound[sizeof ubuf->ut_line + 1] = "";
+
+    setutxent();
 #define SCMPN(a, b)	strncmp(a, b, sizeof (a))
     status = NOT_HERE;
     (void) strcpy(ftty, _PATH_DEV);
-    while (fread((char *) &ubuf, sizeof ubuf, 1, fd) == 1) {
-        if (!SCMPN(ubuf.ut_name, name)) {
+    while ((ubuf = getutxent())) {
+        if ((ubuf->ut_type == USER_PROCESS) &&
+            (!SCMPN(ubuf->ut_user, name))) {
             if (*tty == '\0') {
                 /* no particular tty was requested */
-                (void) strcpy(ftty+5, ubuf.ut_line);
+                (void) strcpy(ftty+5, ubuf->ut_line);
                 if (stat(ftty,&statb) == 0) {
                     if (!(statb.st_mode & 020)) /* ?character device? */
                         continue;
-                    (void) strcpy(ttyFound, ubuf.ut_line);
+                    (void) strcpy(ttyFound, ubuf->ut_line);
 #ifdef USE_UT_HOST
-                    (void) strcpy(dispFound, ubuf.ut_host);
+                    (void) strcpy(dispFound, ubuf->ut_host);
                     strcat(dispFound, " ");
 #endif
                     status = SUCCESS;
@@ -384,13 +383,13 @@
                     }
                 }
             }
-	    else if (!strcmp(ubuf.ut_line, tty)) {
+	    else if (!strcmp(ubuf->ut_line, tty)) {
                 status = SUCCESS;
                 break;
             }
         }
     }
-    fclose(fd);
+    endutxent();
     if (status == SUCCESS) {
         (void) strcpy(tty, ttyFound);
         (void) strcpy(disp, dispFound);
