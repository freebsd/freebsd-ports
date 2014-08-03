--- fmt_no.h.orig	2014-06-29 00:25:12.000000000 +0900
+++ fmt_no.h	2014-06-29 00:28:32.000000000 +0900
@@ -4,6 +4,8 @@
 #define _FMT_NO_H
 
 #include <sys/types.h>
+typedef long long loff_t;
+
 char* fmt_int_b(unsigned char pre, unsigned char post, unsigned int scale,
 	       	loff_t no, const char* bold, const char* norm, 
 		const char boldinvis, const unsigned char base,
