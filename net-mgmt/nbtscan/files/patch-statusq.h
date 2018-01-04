--- statusq.h.orig	2002-05-23 11:31:35 UTC
+++ statusq.h
@@ -22,6 +22,8 @@
 
 #define NB_DGRAM		137
 
+struct nb_host_info* parse_response(char*, int);
+
 struct nbname {
 	char ascii_name [16] ;
 	my_uint16_t rr_flags;
