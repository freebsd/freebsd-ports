--- intl/dcigettext.c.orig	Sat Jun 18 01:40:35 2005
+++ intl/dcigettext.c	Sat Jun 18 01:40:57 2005
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
