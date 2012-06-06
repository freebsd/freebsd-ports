--- src/mbase/project/table.cpp.orig	2012-06-05 22:28:36.000000000 +0200
+++ src/mbase/project/table.cpp	2012-06-05 22:39:36.000000000 +0200
@@ -427,7 +427,7 @@
         {
             for( fs::directory_iterator itr(dir), end; itr != end; ++itr )
                 if( IsFrameDir(*itr) )
-                    t_lst.push_back(itr->leaf());
+                    t_lst.push_back(itr->path().filename().string());
         }
     }
 
