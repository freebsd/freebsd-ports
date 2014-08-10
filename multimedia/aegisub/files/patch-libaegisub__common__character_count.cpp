--- libaegisub/common/character_count.cpp.orig	2014-08-05 20:41:47.000000000 +0900
+++ libaegisub/common/character_count.cpp	2014-08-05 20:43:19.000000000 +0900
@@ -22,6 +22,8 @@
 #include <unicode/uchar.h>
 #include <unicode/utf8.h>
 
+#include <algorithm>
+#include <memory>
 #include <mutex>
 #include <unicode/brkiter.h>
 
