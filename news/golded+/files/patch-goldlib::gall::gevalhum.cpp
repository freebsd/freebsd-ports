--- ./goldlib/gall/gevalhum.cpp.orig	Mon Oct 20 02:04:25 2003
+++ ./goldlib/gall/gevalhum.cpp	Mon Oct 20 02:17:07 2003
@@ -50,12 +50,12 @@
 
     while(ostk.size()) {
 
-      int* vptr = vstk.begin();
-      ops* optr = ostk.begin();
+      vector<int>::iterator vptr = vstk.begin();
+      vector<ops>::iterator optr = ostk.begin();
 
-      while(optr < ostk.end()) {
+      while(optr != ostk.end()) {
 
-        if(optr < (ostk.end() - 1)) {
+        if(optr != (ostk.end() - 1)) {
 
           if(*optr == parenthesis_left) {
             if(optr[1] == parenthesis_right) {
@@ -80,10 +80,10 @@
 
         if(ostk.size()) {
           if((*optr == negation) or (*optr == logic_not))
-            *vptr = evaluate_ops(optr, vptr, vptr);
+            *vptr = evaluate_op(*optr, *vptr, *vptr);
           else {
-            *vptr = evaluate_ops(optr, vptr, vptr+1);
-            if(vptr+1 < vstk.end())
+            *vptr = evaluate_op(*optr, *vptr, *(vptr+1));
+            if(vptr+1 != vstk.end())
               vstk.erase(vptr+1);
           }
           ostk.erase(optr);
