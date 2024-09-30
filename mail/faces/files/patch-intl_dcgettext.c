--- intl/dcgettext.c.orig	2024-09-30 18:50:01.925202000 +0100
+++ intl/dcgettext.c	2024-09-30 18:51:19.264270000 +0100
@@ -39,9 +39,6 @@
 #endif
 
 #include <errno.h>
-#ifndef errno
-extern int errno;
-#endif
 #ifndef __set_errno
 # define __set_errno(val) errno = (val)
 #endif
