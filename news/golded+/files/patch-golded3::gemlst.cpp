--- ./golded3/gemlst.cpp.orig	Mon Oct 20 03:02:58 2003
+++ ./golded3/gemlst.cpp	Mon Oct 20 03:05:15 2003
@@ -1021,7 +1021,7 @@
     }
 
     if(found and list[j].msgno != t.replyto)
-      list.erase(&list[j]);
+      list.erase(list.begin() + j);
 
     if(found or list.size() == 0)
       list.push_back(t);
