--- misc/json2profile.cpp.orig	2020-12-20 07:39:23 UTC
+++ misc/json2profile.cpp
@@ -29,6 +29,8 @@
 #include <utility>
 #include <vector>
 
+#include <stdio.h> // missing header: https://github.com/thrill/thrill/issues/203
+
 using namespace thrill; // NOLINT
 using tlx::escape_html;
 
