--- lib/freebl/ppc-gcm.s.orig
+++ lib/freebl/ppc-gcm.s
@@ -639,13 +639,13 @@
 .endm

     # store non-volatile general registers
-    std          31,-8(SP);
-    std          30,-16(SP);
-    std          29,-24(SP);
-    std          28,-32(SP);
-    std          27,-40(SP);
-    std          26,-48(SP);
-    std          25,-56(SP);
+    std          31,-8(1);
+    std          30,-16(1);
+    std          29,-24(1);
+    std          28,-32(1);
+    std          27,-40(1);
+    std          26,-48(1);
+    std          25,-56(1);

     # store non-volatile vector registers
     addi         9, SP, -80
@@ -1031,13 +1031,13 @@
     lvx          24, 0, 9

     # restore non-volatile general registers
-    ld           31,-8(SP);
-    ld           30,-16(SP);
-    ld           29,-24(SP);
-    ld           28,-32(SP);
-    ld           27,-40(SP);
-    ld           26,-48(SP);
-    ld           25,-56(SP);
+    ld           31,-8(1);
+    ld           30,-16(1);
+    ld           29,-24(1);
+    ld           28,-32(1);
+    ld           27,-40(1);
+    ld           26,-48(1);
+    ld           25,-56(1);
     blr
 .size ppc_aes_gcmCRYPT, . - ppc_aes_gcmCRYPT

