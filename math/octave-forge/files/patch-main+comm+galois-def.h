http://www.octave.org/octave-lists/archive/bug-octave.2004/msg00181.html
--- main/comm/galois-def.h.org	Wed Apr  2 04:37:14 2003
+++ main/comm/galois-def.h	Fri May  7 04:38:27 2004
@@ -306,13 +306,17 @@
     return r; \
   }
 
+#define TBM boolMatrix (1, 1, true)
+#define FBM boolMatrix (1, 1, false)
+#define NBM boolMatrix ()
+
 #define MM_CMP_OPS1(M1, C1, M2, C2, GR1, GR2, CHECK) \
   MM_CMP_OP1(mx_el_lt, <,  M1, C1, M2, C2, GR1, GR2, CHECK, NBM, NBM) \
   MM_CMP_OP1(mx_el_le, <=, M1, C1, M2, C2, GR1, GR2, CHECK, NBM, NBM) \
   MM_CMP_OP1(mx_el_ge, >=, M1, C1, M2, C2, GR1, GR2, CHECK, NBM, NBM) \
   MM_CMP_OP1(mx_el_gt, >,  M1, C1, M2, C2, GR1, GR2, CHECK, NBM, NBM) \
   MM_CMP_OP1(mx_el_eq, ==, M1,   , M2,   , GR1, GR2, CHECK, FBM, TBM) \
-  MM_CMP_OP1(mx_el_ne, !=, M1,   , M2,   , GR1, GR2, CHECK, TBM, FBM) \
+  MM_CMP_OP1(mx_el_ne, !=, M1,   , M2,   , GR1, GR2, CHECK, TBM, FBM)
 
 #define MM_BOOL_OP1(F, OP, M1, M2, ZERO, GR1, GR2, CHECKTYPE) \
   boolMatrix \
