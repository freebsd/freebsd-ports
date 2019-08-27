--- src/mp4util.h.orig	2019-08-25 16:36:29 UTC
+++ src/mp4util.h
@@ -33,7 +33,7 @@ namespace mp4v2 { namespace impl {
 #ifndef ASSERT
 #   define ASSERT(expr) \
         if (!(expr)) { \
-            throw new Exception("assert failure: "LIBMPV42_STRINGIFY((expr)), __FILE__, __LINE__, __FUNCTION__ ); \
+            throw new Exception("assert failure: " LIBMPV42_STRINGIFY((expr)), __FILE__, __LINE__, __FUNCTION__ ); \
         }
 #endif
 
