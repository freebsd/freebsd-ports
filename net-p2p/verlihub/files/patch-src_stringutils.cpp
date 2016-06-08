--- src/stringutils.cpp.orig	2014-04-29 10:31:39.558886643 -0400
+++ src/stringutils.cpp	2014-04-29 10:32:25.579606845 -0400
@@ -36,6 +36,9 @@
 #include <stdlib.h>
 #include <algorithm>
 #include <ctype.h>
+#ifdef HAVE_FREEBSD
+#include <unistd.h>
+#endif
 
 namespace nStringUtils
 {
