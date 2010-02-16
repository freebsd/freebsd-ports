--- driver/others/dynamic.c~	2010-01-21 01:28:45.000000000 +0900
+++ driver/others/dynamic.c	2010-02-16 13:43:09.000000000 +0900
@@ -181,9 +181,9 @@
   gotoblas = get_coretype();
   
 #ifdef ARCH_X86
-  if (gotoblas == NULL) gotoblas = gotoblas_KATMAI;
+  if (gotoblas == NULL) gotoblas = &gotoblas_KATMAI;
 #else
-  if (gotoblas == NULL) gotoblas = gotoblas_PRESCOTT;
+  if (gotoblas == NULL) gotoblas = &gotoblas_PRESCOTT;
 #endif
   
   if (gotoblas && gotoblas -> init) {
