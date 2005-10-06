--- src/plugins/pngextractor.c.orig	Tue Oct  4 22:36:11 2005
+++ src/plugins/pngextractor.c	Tue Oct  4 22:36:40 2005
@@ -23,6 +23,13 @@
 #include <zlib.h>
 #include "convert.h"
 
+size_t
+strnlen (const char *string, size_t maxlen)
+{
+  const char *end = memchr (string, '\0', maxlen);
+  return end ? (size_t) (end - string) : maxlen;
+}
+
 static char * stndup(const char * str,
 		     size_t n) {
   char * tmp;
