--- dcetest.c.orig	Tue Feb 15 11:32:36 2005
+++ dcetest.c	Tue Feb 15 11:31:48 2005
@@ -359,7 +359,7 @@
   int tint;
   char annotation[EPT_MAX_ANNOTATION_SIZE+1];
   int floor, floors;
-  int address_type;
+  int address_type=0;
 
   char tmp_address[200];
   char tmp_address2[200];
