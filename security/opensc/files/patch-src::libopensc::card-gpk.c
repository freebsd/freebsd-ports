--- src/libopensc/card-gpk.c.orig	Thu May  2 14:54:27 2002
+++ src/libopensc/card-gpk.c	Tue Sep 10 15:18:38 2002
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
@@ -1440,6 +1442,7 @@
 
 	SC_FUNC_CALLED(card->ctx, 1);
 	switch (priv->variant) {
+	case GPK4000_su40:
 	case GPK4000_su256:
 	case GPK4000_sdo:
 		offset = 0x6B;  /* courtesy gemplus hotline */
