--- liboctave/system/file-stat.cc.orig	2017-02-22 18:01:55 UTC
+++ liboctave/system/file-stat.cc
@@ -174,7 +174,7 @@ namespace octave
           update_internal ();
       }
 
-    inline file_stat::~file_stat () { }
+    file_stat::~file_stat () { }
 
     void
     file_stat::update_internal (bool force)
