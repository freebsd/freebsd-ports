--- src/iref.h.orig	2013-04-30 11:13:29.000000000 +0900
+++ src/iref.h	2013-04-30 11:13:41.000000000 +0900
@@ -441,7 +441,7 @@
 #define r_set_ptr(rp,ptr) ((rp)->value.pstruct = (obj_header_t *)(ptr))
 
     union v {			/* name the union to keep gdb happy */
-	long intval;
+	int intval;
 	ushort boolval;
 	float realval;
 	ulong saveid;
