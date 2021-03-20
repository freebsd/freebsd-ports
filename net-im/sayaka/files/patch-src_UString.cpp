--- src/UString.cpp.orig	2021-03-18 09:51:03 UTC
+++ src/UString.cpp
@@ -25,6 +25,7 @@
 
 #include "UString.h"
 #include <array>
+#include <cerrno>
 #include <cstring>
 
 // 出力文字コードが UTF-8 以外 (iconv による変換が必要) なら true。
