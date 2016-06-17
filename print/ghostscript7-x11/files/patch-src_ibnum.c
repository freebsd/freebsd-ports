--- src/ibnum.c.orig	2003-01-17 00:49:04 UTC
+++ src/ibnum.c
@@ -124,11 +124,11 @@ sdecode_number(const byte * str, int for
 	case num_int32:
 	case num_int32 + 16:
 	    if ((format & 31) == 0) {
-		np->value.intval = sdecodelong(str, format);
+		np->value.intval = sdecodeint32(str, format);
 		return t_integer;
 	    } else {
 		np->value.realval =
-		    (double)sdecodelong(str, format) *
+		    (double)sdecodeint32(str, format) *
 		    binary_scale[format & 31];
 		return t_real;
 	    }
@@ -171,18 +171,14 @@ sdecodeshort(const byte * p, int format)
 }
 
 /* Decode a (32-bit, signed) long. */
-long
-sdecodelong(const byte * p, int format)
+int
+sdecodeint32(const byte * p, int format)
 {
     int a = p[0], b = p[1], c = p[2], d = p[3];
-    long v = (num_is_lsb(format) ?
-	      ((long)d << 24) + ((long)c << 16) + (b << 8) + a :
-	      ((long)a << 24) + ((long)b << 16) + (c << 8) + d);
+    int v = (num_is_lsb(format) ?
+	      ((int)d << 24) + ((int)c << 16) + (b << 8) + a :
+	      ((int)a << 24) + ((int)b << 16) + (c << 8) + d);
 
-#if arch_sizeof_long > 4
-    /* Propagate bit 31 as the sign. */
-    v = (v ^ 0x80000000L) - 0x80000000L;
-#endif
     return v;
 }
 
@@ -190,7 +186,7 @@ sdecodelong(const byte * p, int format)
 float
 sdecodefloat(const byte * p, int format)
 {
-    bits32 lnum = (bits32) sdecodelong(p, format);
+    bits32 lnum = (bits32) sdecodeint32(p, format);
     float fnum;
 
 #if !arch_floats_are_IEEE
