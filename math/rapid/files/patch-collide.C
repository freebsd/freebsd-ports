--- collide.C.orig	2018-05-16 10:58:09 UTC
+++ collide.C
@@ -42,7 +42,7 @@
 
 #include "RAPID_version.H"
 
-static char rapidtag_data[] = "RAPIDTAG  file: "__FILE__"    date: "__DATE__"    time: "__TIME__;
+static char rapidtag_data[] = "RAPIDTAG  file: " __FILE__ "    date: " __DATE__ "    time: " __TIME__;
 
 // to silence the compiler's complaints about unreferenced identifiers.
 static void r1(char *f){  r1(f);  r1(rapidtag_data);  r1(rapid_version);}
