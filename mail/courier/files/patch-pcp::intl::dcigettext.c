--- pcp/intl/dcigettext.c.orig	Fri Oct 26 00:01:27 2001
+++ pcp/intl/dcigettext.c	Wed Jul  3 01:47:12 2002
@@ -57,7 +57,7 @@
 #include <stdlib.h>
 
 #include <string.h>
-#if !HAVE_STRCHR && !defined _LIBC
+#if !HAVE_STRCHR && !defined _LIBC && !defined __FreeBSD__
 # ifndef strchr
 #  define strchr index
 # endif
