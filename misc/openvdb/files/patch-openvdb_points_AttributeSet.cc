--- openvdb/points/AttributeSet.cc.orig	2019-12-06 20:11:33 UTC
+++ openvdb/points/AttributeSet.cc
@@ -7,6 +7,7 @@
 #include "AttributeGroup.h"
 
 #include <algorithm> // std::equal
+#include <climits> // CHAR_BIT
 #include <string>
 
 namespace openvdb {
