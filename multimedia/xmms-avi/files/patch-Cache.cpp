--- lib/avifile/Cache.cpp.orig	Mon Dec 11 18:12:03 2006
+++ lib/avifile/Cache.cpp	Mon Dec 11 18:12:14 2006
@@ -410,7 +410,7 @@
     char** flags;
     int i;
     static int caller=0;
-    flags=new (char*)[MAXSTREAMS];
+    flags=new char*[MAXSTREAMS];
     mc.add(MAXSTREAMS*4);
     for(i=0; i<MAXSTREAMS; i++)
     {

