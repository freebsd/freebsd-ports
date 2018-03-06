--- src/tools/ceph_kvstore_tool.cc.orig	2018-02-26 21:47:18 UTC
+++ src/tools/ceph_kvstore_tool.cc
@@ -36,7 +36,9 @@ using namespace std;
 
 class StoreTool
 {
+#ifdef HAVE_LIBAIO
   boost::scoped_ptr<BlueStore> bluestore;
+#endif
 
   // TODO: make KeyValueDB enable_shared_from_this
   // bluestore will hold *db* also, use unique_ptr/shared_ptr will
@@ -74,10 +76,13 @@ class StoreTool
   }
 
   ~StoreTool() {
+#ifdef HAVE_LIBAIO
     if (bluestore) {
       bluestore->umount();   
     }
-    else {
+    else 
+#endif
+    {
       if (db) {
         delete db;
       }
