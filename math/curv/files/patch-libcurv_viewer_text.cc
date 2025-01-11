--- libcurv/viewer/text.cc.orig	2019-10-22 18:22:58 UTC
+++ libcurv/viewer/text.cc
@@ -1,6 +1,7 @@
 #include "text.h"
 
 #include <algorithm>
+#include <sys/types.h>
 
 std::string getLower(const std::string& _string) {
     std::string std = _string;
