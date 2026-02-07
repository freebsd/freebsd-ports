--- src/rtree/RTreeC.h.orig	2024-11-16 19:15:18 UTC
+++ src/rtree/RTreeC.h
@@ -32,7 +32,7 @@ class RTreeC (public)
 
   RTreeC();
   RTreeC(rtree_t*);
-  RTreeC(std::uint64_t, std::string, std::uint32_t);
+  RTreeC(std::size_t, std::string, std::uint32_t);
   ~RTreeC();
 
   static RTreeC* bsrt_read(int);
