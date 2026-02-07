--- mystring.h.orig	2008-07-12 06:05:22 UTC
+++ mystring.h
@@ -53,7 +53,7 @@ struct mystring {
 	char s_data[1];
 };
 
-struct mystring str_head;
+extern struct mystring str_head;
 
 #define str_offset ((unsigned)str_head.s_data - (unsigned)&str_head)
 #define str_stos(s) ((struct mystring *)((unsigned)(s) - str_offset))
