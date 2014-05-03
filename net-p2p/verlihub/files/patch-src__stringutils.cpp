commit 4d6a2ebf7e47b2854fdf4a9cc7daec625b035b3c
Author: Nimesh Ghelani <nimeshghelani@gmail.com>
Date:   Sat Nov 10 01:47:07 2012 +0530

    added unistd.h to stringutils.cpp causing compilation error

diff --git a/src/stringutils.cpp b/src/stringutils.cpp
index 35d7d46..b020a79 100755
--- src/stringutils.cpp
+++ src/stringutils.cpp
@@ -32,6 +32,8 @@
 #include <ctype.h>
 #ifdef _WIN32
 #include <windows.h>
+#else
+#include <unistd.h>
 #endif
 
 namespace nVerliHub {
