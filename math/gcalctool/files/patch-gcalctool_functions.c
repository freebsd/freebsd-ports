--- gcalctool/functions.c.orig	Mon Feb 28 17:07:30 2005
+++ gcalctool/functions.c	Mon Feb 28 17:07:43 2005
@@ -311,7 +311,6 @@
 void
 trig_filter(char **func) 
 {
-    assert(func);
 
     enum mode {
         normal = 0,
@@ -322,6 +321,8 @@
   
     int inverse;
     int hyperbolic;
+
+    assert(func);
 
     inverse = (v->inverse) ? inv : 0;
     hyperbolic = (v->hyperbolic) ? hyp : 0;
