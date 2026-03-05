--- whowatch.h.orig	2010-02-02 19:18:34.763514932 -0800
+++ whowatch.h	2010-02-02 19:20:44.905393020 -0800
@@ -2,7 +2,7 @@
 #include <stdlib.h>
 #include <unistd.h>
 #include <fcntl.h>
-#include <utmp.h>
+#include <utmpx.h>
 #include <string.h>
 #include <signal.h>
 #include <sys/stat.h>
@@ -75,12 +75,12 @@
 {
 	struct user_t *next;
 	struct user_t *prev;
-        char name[UT_NAMESIZE + 1];	/* login name 		*/
-        char tty[UT_LINESIZE + 1];	/* tty			*/
+        char name[sizeof(((struct utmpx *)0)->ut_user)];	/* login name 		*/
+        char tty[sizeof(((struct utmpx *)0)->ut_line)];	/* tty			*/
         int prot;			
         int pid;			/* pid of login shell 	*/
 	char parent[16];
-        char host[UT_HOSTSIZE + 1];
+        char host[sizeof(((struct utmpx *)0)->ut_host)];
         int line;
 };
 
