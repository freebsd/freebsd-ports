--- openbsd-compat/openbsd-compat.h.orig	2020-09-01 07:17:43 UTC
+++ openbsd-compat/openbsd-compat.h
@@ -12,7 +12,7 @@
 #endif
 
 #if defined(HAVE_ENDIAN_H)
-#include <endian.h>
+#include <sys/endian.h>
 #endif
 
 #if defined(__APPLE__) && !defined(HAVE_ENDIAN_H)
@@ -33,7 +33,7 @@
 #endif /* _WIN32 && !HAVE_ENDIAN_H */
 
 #if defined(__FreeBSD__) && !defined(HAVE_ENDIAN_H)
-#include <sys/endian.h>
+#include <sys/sys/endian.h>
 #endif
 
 #include <stdlib.h>
