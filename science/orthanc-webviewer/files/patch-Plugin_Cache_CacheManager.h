--- Plugin/Cache/CacheManager.h.orig	2022-02-22 07:33:59 UTC
+++ Plugin/Cache/CacheManager.h
@@ -29,6 +29,8 @@
 
 #include <boost/shared_ptr.hpp>
 
+#include <list>
+
 namespace OrthancPlugins
 {
   enum CacheProperty
