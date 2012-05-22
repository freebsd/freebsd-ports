--- src/directory.cc.orig	2008-11-16 06:59:26.000000000 +0900
+++ src/directory.cc	2012-05-10 17:27:13.000000000 +0900
@@ -153,7 +153,7 @@
     for (dir = childs.begin(); dir != childs.end(); dir++) {
         printf("%s:%s:%d\n",(*dir)->get_current().c_str(),
                 path.c_str(),path.size());
-        if (!(*dir)->get_current().compare(0,path.size(),path))
+        if (!(*dir)->get_current().compare(path))
             return (*dir);
     }
     return this;
