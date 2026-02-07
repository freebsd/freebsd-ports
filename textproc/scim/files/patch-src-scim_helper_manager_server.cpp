--- src/scim_helper_manager_server.cpp.orig	2008-11-02 07:42:38.000000000 +0100
+++ src/scim_helper_manager_server.cpp	2013-10-08 17:37:59.000000000 +0200
@@ -95,9 +95,8 @@
     //      so I added a workaround: have an array of modules and unload them all together in the end only.
     //      TODO Need to figure out what's going on with this issue.
 
-    HelperModule module[mod_list.size ()];
-
     if (mod_list.size ()) {
+        HelperModule *module = new HelperModule[mod_list.size ()];
 
         for (size_t i = 0; i < mod_list.size (); ++i) {
 
@@ -120,6 +119,7 @@
         for (size_t i = 0; i < mod_list.size (); ++i) {
             module[i].unload ();
         }
+        delete[] module;
     }
 }
 
