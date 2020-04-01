--- bruch.c.orig	2007-12-06 16:30:00 UTC
+++ bruch.c
@@ -1,4 +1,5 @@
 /* SYMMETRICA source code file: bruch.c */
+/* Patch from SageMath */
 #include "def.h"
 #include "macro.h"
 
@@ -975,14 +976,16 @@ INT kuerzen_integer_integer(bruch) OP bruch;
     ggterg = ggt_i(S_B_UI(bruch),S_B_OI(bruch));
 
     if (ggterg == S_B_UI(bruch)) {
+        INT tmp = S_B_OI(bruch);
         freeself_bruch(bruch);
-        M_I_I(S_B_OI(bruch) / ggterg,bruch);
+        M_I_I(tmp / ggterg,bruch);
         goto ende;
         }
 
     if (-ggterg == S_B_UI(bruch)) {
+        INT tmp = S_B_OI(bruch);
         freeself_bruch(bruch);
-        M_I_I(- S_B_OI(bruch) / ggterg,bruch);
+        M_I_I(- tmp / ggterg,bruch);
         goto ende;
         }
 
@@ -1032,12 +1035,14 @@ INT kuerzen_integer_longint(bruch) OP bruch;
 
     if (S_O_K(S_B_U(bruch)) == INTEGER)
         if (S_B_UI(bruch) == 1) { 
+            INT tmp = S_B_OI(bruch);
             freeself_bruch(bruch);
-            M_I_I(S_B_OI(bruch),bruch); 
+            M_I_I(tmp,bruch); 
             goto ende; }
         else if (S_B_UI(bruch) == -1) { 
+            INT tmp = S_B_OI(bruch);
             freeself_bruch(bruch);
-            M_I_I( - S_B_OI(bruch),bruch); 
+            M_I_I( - tmp,bruch); 
             goto ende; }
     if (NEGP(S_B_O(bruch)) && NEGP(S_B_U(bruch)))
         {
