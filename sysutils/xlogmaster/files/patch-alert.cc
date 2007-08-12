--- alert.cc.org	2007-07-16 14:54:21.000000000 +0200
+++ src/alert.cc	2007-07-16 14:54:48.000000000 +0200
@@ -102,7 +102,7 @@
 int 
 alert_interrupt(gpointer data)
 { 
-  int nr = (int) data;
+  long nr = (long) data;
   entry[nr]->fade += entry[nr]->fadestep;
   if ( entry[nr]->fade > fade_base )
     {
