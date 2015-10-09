--- src/base/small_map.h.orig	2014-03-19 19:34:51 UTC
+++ src/base/small_map.h
@@ -52,6 +52,8 @@
 #include <assert.h>
 #include <utility>   // for make_pair()
 #include "base/manual_constructor.h"
+using std::make_pair;
+
 _START_GOOGLE_NAMESPACE_
 
 template <bool> struct CompileAssert { };
