--- statusq.h.orig	2010-04-26 16:39:16.000000000 +0300
+++ statusq.h	2010-04-26 16:39:28.000000000 +0300
@@ -22,6 +22,8 @@
 
 #define NB_DGRAM		137
 
+struct nb_host_info* parse_response(char*, int);
+
 struct nbname {
 	char ascii_name [16] ;
 	my_uint16_t rr_flags;
