--- parttypes.h.orig	2021-01-13 22:14:27 UTC
+++ parttypes.h
@@ -16,6 +16,9 @@
 #include "guid.h"
 
 using namespace std;
+#ifdef USE_UTF16
+using namespace icu;
+#endif
 
 // A partition type
 struct AType {
