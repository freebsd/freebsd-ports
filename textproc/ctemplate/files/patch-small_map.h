--- src/base/small_map.h.orig	2012-02-02 16:18:30.000000000 +0800
+++ src/base/small_map.h	2012-02-02 16:18:47.000000000 +0800
@@ -52,6 +52,8 @@
 #include <assert.h>
 #include <utility>   // for make_pair()
 #include "base/manual_constructor.h"
+using std::make_pair;
+
 _START_GOOGLE_NAMESPACE_
 
 template <bool> struct CompileAssert { };
