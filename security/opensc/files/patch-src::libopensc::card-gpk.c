--- src/libopensc/card-gpk.c.orig	Thu May  2 08:54:27 2002
+++ src/libopensc/card-gpk.c	Tue Feb 25 15:30:23 2003
@@ -35,6 +35,7 @@
 	GPK4000_s,
 	GPK4000_sp,
 	GPK4000_sdo,
+	GPK4000_su40,
 	GPK8000 = 8000,
 	GPK8000_8K,
 	GPK8000_16K,
@@ -101,6 +102,7 @@
 } atrlist[] = {
   { "\x3B\x27\x00\x80\x65\xA2\x04\x01\x01\x37", 10, GPK4000_s },
   { "\x3B\x27\x00\x80\x65\xA2\x05\x01\x01\x37", 10, GPK4000_sp },
+  { "\x3B\x27\x00\x80\x65\xA2\x06\x01\x01\x37", 10, GPK4000_su40 },
   { "\x3B\x27\x00\x80\x65\xA2\x0C\x01\x01\x37", 10, GPK4000_su256 },
   { "\x3B\xA7\x00\x40\x14\x80\x65\xA2\x14\x01\x01\x37", 12, GPK4000_sdo },
   { "\x3B\xA7\x00\x40\x18\x80\x65\xA2\x08\x01\x01\x52", 12, GPK8000_8K },
@@ -735,8 +737,8 @@
 	apdu->le += 3;
 	if (crycks1)
 		memcpy(crycks1, out, 3);
-	memset(k1, 0, sizeof(k1));
-	memset(k2, 0, sizeof(k2));
+	memset(&k1, 0, sizeof(k1));
+	memset(&k2, 0, sizeof(k2));
 	memset(in, 0, sizeof(in));
 	memset(out, 0, sizeof(out));
 	memset(block, 0, sizeof(block));
@@ -878,8 +880,8 @@
 	if (memcmp(r_rn, out+4, 4) != 0)
 		r = SC_ERROR_INVALID_ARGUMENTS;
 
-	memset(k1, 0, sizeof(k1));
-	memset(k2, 0, sizeof(k2));
+	memset(&k1, 0, sizeof(k1));
+	memset(&k2, 0, sizeof(k2));
 	memset(out, 0, sizeof(out));
 	return r;
 }
@@ -1440,6 +1442,7 @@
 
 	SC_FUNC_CALLED(card->ctx, 1);
 	switch (priv->variant) {
+	case GPK4000_su40:
 	case GPK4000_su256:
 	case GPK4000_sdo:
 		offset = 0x6B;  /* courtesy gemplus hotline */
