--- 2.4.5/room/vill_road2.c.orig	2011-05-29 14:59:37.000000000 -0700
+++ 2.4.5/room/vill_road2.c	2011-05-29 15:00:06.000000000 -0700
@@ -7,7 +7,6 @@
 string function, type, match;
 
 reset(arg) {
-    start_harry();
     if (arg)
 	return;
     dest_dir = ({ "room/vill_road1","west",
@@ -22,6 +21,7 @@
         "south is the adventurers guild. The road runs towards the shore to\n"+
         "the east.\n";
     set_light(1);
+    start_harry();
 }
 
 start_harry() {
