--- src/iscanbin.c.orig	2013-04-30 10:51:53.000000000 +0900
+++ src/iscanbin.c	2013-04-30 10:53:42.000000000 +0900
@@ -173,7 +173,7 @@
 		pbs->num_format = num_format;
 		if (top_size == 0) {
 		    /* Extended header (2-byte array size, 4-byte length) */
-		    ulong lsize;
+		    uint lsize;
 
 		    if (rcnt < 7) {
 			s_end_inline(s, p - 1, rlimit);
@@ -183,7 +183,7 @@
 		    if (p[1] != 0) /* reserved, must be 0 */
 			return_error(e_syntaxerror);
 		    top_size = sdecodeushort(p + 2, num_format);
-		    lsize = sdecodelong(p + 4, num_format);
+		    lsize = sdecodeint32(p + 4, num_format);
 		    if ((size = lsize) != lsize)
 			return_error(e_limitcheck);
 		    hsize = 8;
@@ -445,8 +445,7 @@
     for (; index < max_array_index; p += SIZEOF_BIN_SEQ_OBJ, index++) {
 	ref *op = abase + index;
 	uint osize;
-	long value;
-	uint atype, attrs;
+	int value, atype, attrs;
 
 	s_end_inline(s, p, rlimit);	/* in case of error */
 	if (rlimit - p < SIZEOF_BIN_SEQ_OBJ) {
@@ -464,14 +463,14 @@
 		make_null(op);
 		break;
 	    case BS_TYPE_INTEGER:
-		make_int(op, sdecodelong(p + 5, num_format));
+		make_int(op, sdecodeint32(p + 5, num_format));
 		break;
 	    case BS_TYPE_REAL:{
 		    float vreal;
 
 		    osize = sdecodeushort(p + 3, num_format);
 		    if (osize != 0) {	/* fixed-point number */
-			value = sdecodelong(p + 5, num_format);
+			value = sdecodeint32(p + 5, num_format);
 			vreal = (float)ldexp((double)value, -osize);
 		    } else {
 			vreal = sdecodefloat(p + 5, num_format);
@@ -480,7 +479,7 @@
 		    break;
 		}
 	    case BS_TYPE_BOOLEAN:
-		make_bool(op, sdecodelong(p + 5, num_format) != 0);
+		make_bool(op, sdecodeint32(p + 5, num_format) != 0);
 		break;
 	    case BS_TYPE_STRING:
 		osize = sdecodeushort(p + 3, num_format);
@@ -492,7 +491,7 @@
 		    make_empty_string(op, attrs);
 		    break;
 		}
-		value = sdecodelong(p + 5, num_format);
+		value = sdecodeint32(p + 5, num_format);
 		if (value < max_array_index * SIZEOF_BIN_SEQ_OBJ ||
 		    value + osize > size
 		    )
@@ -524,7 +523,7 @@
 		/* falls through */
 	    case BS_TYPE_NAME:
 		osize = sdecodeushort(p + 3, num_format);
-		value = sdecodelong(p + 5, num_format);
+		value = sdecodeint32(p + 5, num_format);
 		switch (osize) {
 		    case 0:
 			code = array_get(user_names_p, value, op);
@@ -546,7 +545,7 @@
 		osize = sdecodeushort(p + 3, num_format);
 		atype = t_array;
 	      arr:
-		value = sdecodelong(p + 5, num_format);
+		value = sdecodeint32(p + 5, num_format);
 		if (value + osize > min_string_index ||
 		    value & (SIZEOF_BIN_SEQ_OBJ - 1)
 		    )
