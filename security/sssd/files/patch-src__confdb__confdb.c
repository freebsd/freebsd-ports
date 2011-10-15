--- ./src/confdb/confdb.c.orig	2011-08-29 11:39:05.000000000 -0400
+++ ./src/confdb/confdb.c	2011-10-13 12:15:03.000000000 -0400
@@ -28,6 +28,11 @@
 #include "util/strtonum.h"
 #include "db/sysdb.h"
 
+char *strchrnul(const char *s, int ch) {
+       char *ret = strchr(s, ch);
+       return ret == NULL ? ((char *)s) + strlen(s) : ret;
+}
+
 #define CONFDB_ZERO_CHECK_OR_JUMP(var, ret, err, label) do { \
     if (!var) { \
         ret = err; \
