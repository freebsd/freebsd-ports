--- mibs/bgp4_mib_1657_bgppeertable.cc-orig	2011-12-27 00:37:40.000000000 +0000
+++ mibs/bgp4_mib_1657_bgppeertable.cc	2011-12-27 00:38:11.000000000 +0000
@@ -476,7 +476,7 @@
 
 void free_context(void * context, struct netsnmp_iterator_info_s * /* iinfo */)
 {
-    DEBUGMSGTL((BgpMib::the_instance().name(),"freeing context %x\n", context));
+    DEBUGMSGTL((BgpMib::the_instance().name(),"freeing context %p\n", context));
     if (NULL != context) free(context);
     context = NULL;
 }
