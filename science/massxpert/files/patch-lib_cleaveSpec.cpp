--- lib/cleaveSpec.cpp.orig	2012-12-25 21:02:43 UTC
+++ lib/cleaveSpec.cpp
@@ -427,7 +427,7 @@ namespace massXpert
       return false;
 
   
-    if (parse() == -1)
+    if (parse() == false)
       return false;
   
     // If there are rules, we have to check them all.
