--- parttypes.h.orig	2018-07-05 20:19:46 UTC
+++ parttypes.h
@@ -16,6 +16,9 @@
 #define __PARTITION_TYPES
 
 using namespace std;
+#ifdef USE_UTF16
+using namespace icu;
+#endif
 
 // A partition type
 struct AType {
