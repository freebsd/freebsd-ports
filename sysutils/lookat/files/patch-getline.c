--- getline.c.orig	2015-12-28 06:38:39 UTC
+++ getline.c
@@ -168,7 +168,9 @@ getstr (lineptr, n, stream, terminator, 
 
 #ifndef __OpenBSD__
 #ifndef __NetBSD__
-
+#if defined(__FreeBSD__)
+#include <osreldate.h>
+#if __FreeBSD_version < 900000
 int
 getline (lineptr, n, stream)
      char **lineptr;
@@ -177,6 +179,8 @@ getline (lineptr, n, stream)
 {
   return getstr (lineptr, n, stream, '\n', 0);
 }
+#endif
+#endif
 
 #if defined(__FreeBSD__)
 #include <osreldate.h>
