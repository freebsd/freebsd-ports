--- kover/directory.cc.orig	Sun Jun  6 16:25:27 2004
+++ kover/directory.cc	Sun Jun  6 16:36:15 2004
@@ -153,7 +153,7 @@
     for (dir = childs.begin(); dir != childs.end(); dir++) {
         printf("%s:%s:%d\n",(*dir)->get_current().c_str(),
                 path.c_str(),path.size());
-        if (!(*dir)->get_current().compare(0,path.size(),path))
+        if (!(*dir)->get_current().compare(path))
             return (*dir);
     }
     return this;
