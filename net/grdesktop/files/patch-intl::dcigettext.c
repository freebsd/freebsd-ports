--- intl/dcigettext.c.orig	Fri Oct 11 21:38:35 2002
+++ intl/dcigettext.c	Mon Dec 22 10:27:28 2003
@@ -58,11 +58,6 @@
 #include <stdlib.h>
 
 #include <string.h>
-#if !HAVE_STRCHR && !defined _LIBC
-# ifndef strchr
-#  define strchr index
-# endif
-#endif
 
 #if defined HAVE_UNISTD_H || defined _LIBC
 # include <unistd.h>
