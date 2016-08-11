--- dcetest.c.orig	2016-06-20 15:23:56 UTC
+++ dcetest.c
@@ -359,7 +359,7 @@ dce_parse_enum_response(const unsigned c
   int tint;
   char annotation[EPT_MAX_ANNOTATION_SIZE+1];
   int floor, floors;
-  int address_type;
+  int address_type=0;
 
   char tmp_address[200];
   char tmp_address2[200];
