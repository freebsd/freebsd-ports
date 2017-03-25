--- iocore/cluster/ClusterCache.cc.orig	2016-07-11 23:03:32 UTC
+++ iocore/cluster/ClusterCache.cc
@@ -437,7 +437,7 @@ CacheContinuation::do_op(Continuation *c
   }
   case CACHE_OPEN_WRITE:
   case CACHE_OPEN_READ: {
-    ink_release_assert(c > 0);
+    ink_release_assert(c);
     //////////////////////
     // Use short format //
     //////////////////////
@@ -500,7 +500,7 @@ CacheContinuation::do_op(Continuation *c
 
   case CACHE_OPEN_READ_LONG:
   case CACHE_OPEN_WRITE_LONG: {
-    ink_release_assert(c > 0);
+    ink_release_assert(c);
     //////////////////////
     // Use long format  //
     //////////////////////
