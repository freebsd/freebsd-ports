--- libdispatch/dfilter.c.orig	2021-02-15 16:07:29 UTC
+++ libdispatch/dfilter.c
@@ -358,6 +358,42 @@ done:
     return stat;
 }
 
+
+#ifdef WORDS_BIGENDIAN
+/* Byte swap an 8-byte integer in place */
+static void
+byteswap8(unsigned char* mem)
+{
+    unsigned char c;
+    c = mem[0];
+    mem[0] = mem[7];
+    mem[7] = c;
+    c = mem[1];
+    mem[1] = mem[6];
+    mem[6] = c;
+    c = mem[2];
+    mem[2] = mem[5];
+    mem[5] = c;
+    c = mem[3];
+    mem[3] = mem[4];
+    mem[4] = c;
+}
+
+/* Byte swap an 8-byte integer in place */
+static void
+byteswap4(unsigned char* mem)
+{
+    unsigned char c;
+    c = mem[0];
+    mem[0] = mem[3];
+    mem[3] = c;
+    c = mem[1];
+    mem[1] = mem[2];
+    mem[2] = c;
+}
+#endif
+
+
 EXTERNL void
 NC4_filterfix8(unsigned char* mem, int decode)
 {
@@ -674,39 +710,3 @@ gettype(const int q0, const int q1, int* isunsignedp)
     if(isunsignedp) *isunsignedp = isunsigned;
     return type;
 }
-
-#ifdef WORDS_BIGENDIAN
-/* Byte swap an 8-byte integer in place */
-static void
-byteswap8(unsigned char* mem)
-{
-    unsigned char c;
-    c = mem[0];
-    mem[0] = mem[7];
-    mem[7] = c;
-    c = mem[1];
-    mem[1] = mem[6];
-    mem[6] = c;
-    c = mem[2];
-    mem[2] = mem[5];
-    mem[5] = c;
-    c = mem[3];
-    mem[3] = mem[4];
-    mem[4] = c;
-}
-
-/* Byte swap an 8-byte integer in place */
-static void
-byteswap4(unsigned char* mem)
-{
-    unsigned char c;
-    c = mem[0];
-    mem[0] = mem[3];
-    mem[3] = c;
-    c = mem[1];
-    mem[1] = mem[2];
-    mem[2] = c;
-}
-#endif
-
-
