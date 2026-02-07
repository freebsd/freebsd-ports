--- src/EbmlUnicodeString.cpp.orig	2023-12-17 02:35:17 UTC
+++ src/EbmlUnicodeString.cpp
@@ -40,7 +40,7 @@
 
 #include "ebml/EbmlUnicodeString.h"
 
-#include "lib/utf8-cpp/source/utf8/checked.h"
+#include "utf8cpp/utf8/checked.h"
 
 namespace libebml {
 
