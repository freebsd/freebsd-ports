--- ga.c.orig	2007-12-06 16:30:01 UTC
+++ ga.c
@@ -1,5 +1,6 @@
 /* SYMMETRICA: ga.c */
 /* group algebra */
+/* Patch from SageMath */
 #include "def.h"
 #include "macro.h"
 
@@ -632,7 +633,7 @@ static INT co_posorneg_sum(a,b,what) OP a,b; INT what;
     else if (what == 0L)
         erg += vertikal_sum(S_V_L(a),c);
     erg += copy(a,d);
-    erg += sort(d);
+    erg += sym_sort(d);
     erg += m_il_p(S_V_II(d,S_V_LI(d)-1L),e); /* identitaet */
     for (i=0L,k=0L,j=S_V_LI(d);i<S_P_LI(e);i++)
         if (i+1L == S_V_II(d,k) )
@@ -722,7 +723,7 @@ INT garnir(f,g,h,c) OP f,g,h,c;
 
     j=0L;
     erg += append(h,g,h2); 
-    erg += sort(h2);
+    erg += sym_sort(h2);
     for (i=0L;i<S_V_LI(g);i++)
         {
         erg += m_i_i(S_V_II(g,i),S_P_I(a,j));
