--- config.c.orig
+++ config.c
@@ -72,7 +72,6 @@ cSatCableNumbers::cSatCableNumbers(int S
 {
   size = Size;
   array = MALLOC(int, size);
-  memset(array, size * sizeof(int), 0);
   FromString(s);
 }
 
