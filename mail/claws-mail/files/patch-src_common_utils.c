--- src/common/utils.c.orig	2015-10-14 15:42:07 UTC
+++ src/common/utils.c
@@ -49,6 +49,7 @@
 #include <ctype.h>
 #include <errno.h>
 #include <sys/param.h>
+#include <sys/socket.h>
 
 #if (HAVE_WCTYPE_H && HAVE_WCHAR_H)
 #  include <wchar.h>
