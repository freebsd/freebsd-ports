--- src/Lcommandline_elliptic.cc.orig	2012-08-08 21:21:56 UTC
+++ src/Lcommandline_elliptic.cc
@@ -18,6 +18,8 @@
    with the package; see the file 'COPYING'. If not, write to the Free Software
    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
+   Patches borrowed from SageMath.
+
 */
 
 #include "Lcommandline_elliptic.h"
@@ -121,11 +123,11 @@ void data_E(char *a1, char *a2, char *a3, char *a4, ch
 
 
     F = cgetg(6, t_VEC);
-    F[1] = lgeti(BIGDEFAULTPREC);
-    F[2] = lgeti(BIGDEFAULTPREC);
-    F[3] = lgeti(BIGDEFAULTPREC);
-    F[4] = lgeti(BIGDEFAULTPREC);
-    F[5] = lgeti(BIGDEFAULTPREC);
+    F[1] = (long)cgeti(BIGDEFAULTPREC);
+    F[2] = (long)cgeti(BIGDEFAULTPREC);
+    F[3] = (long)cgeti(BIGDEFAULTPREC);
+    F[4] = (long)cgeti(BIGDEFAULTPREC);
+    F[5] = (long)cgeti(BIGDEFAULTPREC);
 
     //gaffsg(a1,(GEN) F[1]);
     //gaffsg(a2,(GEN) F[2]);
@@ -133,15 +135,15 @@ void data_E(char *a1, char *a2, char *a3, char *a4, ch
     //gaffsg(a4,(GEN) F[4]);
     //gaffsg(a6,(GEN) F[5]);
 
-    gaffect(strtoGEN(a1), (GEN) F[1]);
-    gaffect(strtoGEN(a2), (GEN) F[2]);
-    gaffect(strtoGEN(a3), (GEN) F[3]);
-    gaffect(strtoGEN(a4), (GEN) F[4]);
-    gaffect(strtoGEN(a6), (GEN) F[5]);
+    gaffect(gp_read_str(a1), (GEN) F[1]);
+    gaffect(gp_read_str(a2), (GEN) F[2]);
+    gaffect(gp_read_str(a3), (GEN) F[3]);
+    gaffect(gp_read_str(a4), (GEN) F[4]);
+    gaffect(gp_read_str(a6), (GEN) F[5]);
 
-    E = initell(F,BIGDEFAULTPREC);
+    E = ellinit(F, NULL, BIGDEFAULTPREC);
 
-    C=globalreduction(E);
+    C=ellglobalred(E);
 
     x=gtodouble((GEN) C[1]);
 
@@ -167,8 +169,8 @@ void data_E(char *a1, char *a2, char *a3, char *a4, ch
 
             p=n;
             gaffsg(p,y);
-            coeff[p] = Double(1.*llrint(gtodouble(apell(E,y))))/sqrt(Double(1.*p));
-            //coeff[p] = Double(1.*Long(gtodouble(apell(E,y))+.1))/sqrt(Double(1.*p));
+            coeff[p] = Double(1.*llrint(gtodouble(ellap(E,y))))/sqrt(Double(1.*p));
+            //coeff[p] = Double(1.*Long(gtodouble(ellap(E,y))+.1))/sqrt(Double(1.*p));
 
             if(gtolong(gmod((GEN) E[12],(GEN) y))==0) // if p|discriminant, i.e. bad reduction
             {
