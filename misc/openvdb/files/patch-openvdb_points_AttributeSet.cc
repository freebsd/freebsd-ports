--- openvdb/points/AttributeSet.cc.orig	2019-09-16 16:50:50 UTC
+++ openvdb/points/AttributeSet.cc
@@ -34,6 +34,7 @@
 #include "AttributeGroup.h"
 
 #include <algorithm> // std::equal
+#include <climits> // CHAR_BIT
 #include <string>
 
 namespace openvdb {
