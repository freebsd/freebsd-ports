--- src/logclass.H.orig	Thu Apr  1 01:00:29 1999
+++ src/logclass.H	Thu Feb  5 21:39:55 2004
@@ -28,7 +28,7 @@
 
 class Log {
 /*{{{  Functions  */
-  friend Filter;
+  friend class Filter;
 public:
   Log();
   ~Log();
@@ -200,7 +200,7 @@
 class Filter 
 {
 /*{{{  Functions  */
-  friend Log;
+  friend class Log;
 public:
   Filter();
   ~Filter();
