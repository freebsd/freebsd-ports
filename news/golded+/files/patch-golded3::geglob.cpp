--- ./golded3/geglob.cpp.orig	Mon Oct 20 02:45:03 2003
+++ ./golded3/geglob.cpp	Mon Oct 20 02:45:13 2003
@@ -274,7 +274,7 @@
   vector<Macro>::iterator m = CFG->macro.begin();
   while(m != CFG->macro.end()) {
     if((key == m->key) and (type == m->type)) {
-      RunMacro(m);
+      RunMacro(*m);
       return true;
     }
     m++;
