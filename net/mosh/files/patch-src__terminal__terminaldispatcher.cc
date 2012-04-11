--- ./src/terminal/terminaldispatcher.cc.orig	2012-04-11 06:57:23.000000000 -0400
+++ ./src/terminal/terminaldispatcher.cc	2012-04-11 06:58:05.000000000 -0400
@@ -85,7 +85,7 @@
     if ( endptr == segment_begin ) {
       val = -1;
     }
-    if ( errno == 0 ) {
+    if ( errno == 0 || segment_begin == endptr ) {
       parsed_params.push_back( val );
     }
 
@@ -99,7 +99,7 @@
   if ( endptr == segment_begin ) {
     val = -1;
   }
-  if ( errno == 0 ) {
+  if ( errno == 0 || segment_begin == endptr ) {
     parsed_params.push_back( val );
   }
 
