--- include/matcher.h.orig	2014-02-02 16:00:13.000000000 +0100
+++ include/matcher.h	2014-02-02 16:00:19.000000000 +0100
@@ -3,6 +3,10 @@
 
 #include <FilterParser.h>
 
+#ifdef _LIBCPP_VERSION
+namespace std { namespace tr1 = std; }
+#endif
+
 namespace newsbeuter {
 
 	class matchable {
