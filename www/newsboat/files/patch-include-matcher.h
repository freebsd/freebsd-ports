--- include/matcher.h.orig	2018-12-29 13:07:06 UTC
+++ include/matcher.h
@@ -3,6 +3,10 @@
 
 #include "FilterParser.h"
 
+#ifdef _LIBCPP_VERSION
+namespace std { namespace tr1 = std; }
+#endif
+
 namespace newsboat {
 
 class Matchable {
