--- src/iref.h.orig	2003-01-17 00:49:04 UTC
+++ src/iref.h
@@ -441,7 +441,7 @@ struct ref_s {
 #define r_set_ptr(rp,ptr) ((rp)->value.pstruct = (obj_header_t *)(ptr))
 
     union v {			/* name the union to keep gdb happy */
-	long intval;
+	int intval;
 	ushort boolval;
 	float realval;
 	ulong saveid;
