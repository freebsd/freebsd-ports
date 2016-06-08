--- src/KRB4_std_plug.c.orig	2012-07-10 12:35:20.000000000 +0200
+++ src/KRB4_std_plug.c	2015-02-28 20:32:34.494881776 +0100
@@ -29,7 +29,7 @@
 #include "KRB4_std.h"
 
 #ifndef des_fixup_key_parity
-#define des_fixup_key_parity	des_set_odd_parity
+#define des_fixup_key_parity	DES_set_odd_parity
 #endif
 
 static void
