--- include/matcher.h.orig	2017-12-25 17:41:10 UTC
+++ include/matcher.h
@@ -3,6 +3,10 @@
 
 #include <FilterParser.h>
 
+#ifdef _LIBCPP_VERSION
+namespace std { namespace tr1 = std; }
+#endif
+
 namespace newsboat {
 
 class matchable {
