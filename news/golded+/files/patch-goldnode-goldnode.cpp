--- goldnode/goldnode.cpp.orig	Fri Feb 23 05:44:33 2007
+++ goldnode/goldnode.cpp	Fri Feb 23 05:45:36 2007
@@ -259,7 +259,7 @@
   point = strchr(str, '.');
   domain = strchr(str, '@');
   if(domain and point)
-    if((uint32_t)point > (uint32_t)domain)
+    if(point > domain)
       point = NULL;
 
   if(space)
@@ -304,7 +304,7 @@
     char* point = strchr(str, '.');
     domain = strchr(str, '@');
     if(domain and point)
-      if((uint32_t)point > (uint32_t)domain)
+      if(point > domain)
         point = NULL;
 
     if(net) {
