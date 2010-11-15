--- include/types/pattern.h.orig	2010-11-15 14:46:53.000000000 -0500
+++ include/types/pattern.h	2010-11-15 14:48:07.000000000 -0500
@@ -54,7 +54,7 @@
 union pattern_arg_data {
 	struct in_addr ip;        /* used for ipv4 type */
 	uint32_t integer;         /* used for unsigned 32bits integer type */
-	int32_t sinteger;         /* used for signed 32bits integer type */
+	int sinteger;             /* used for signed 32bits integer type */
 	struct chunk str;
 };
 
