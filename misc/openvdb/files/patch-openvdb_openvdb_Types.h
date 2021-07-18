--- openvdb/openvdb/Types.h.orig	2021-06-11 21:38:41 UTC
+++ openvdb/openvdb/Types.h
@@ -9,7 +9,7 @@
 #include "TypeList.h" // backwards compat
 
 #ifdef OPENVDB_USE_IMATH_HALF
-#include <OpenEXR/half.h>
+#include <Imath/half.h>
 namespace openvdb {
 OPENVDB_USE_VERSION_NAMESPACE
 namespace OPENVDB_VERSION_NAME {
