--- mxmldoc.c.orig	2009-07-25 13:08:26.603202123 +0900
+++ mxmldoc.c	2009-07-25 13:08:37.818332350 +0900
@@ -57,7 +57,6 @@
 #ifndef WIN32
 #  include <dirent.h>
 #  include <unistd.h>
-#  include <spawn.h>
 #  include <sys/wait.h>
 extern char **environ;
 #endif /* !WIN32 */
