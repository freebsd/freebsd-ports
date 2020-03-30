--- include/L.h.orig	2012-08-08 21:21:55 UTC
+++ include/L.h
@@ -18,6 +18,8 @@
    with the package; see the file 'COPYING'. If not, write to the Free Software
    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
+   Patches borrowed from SageMath.
+
 */
 
 
@@ -491,7 +493,7 @@ class L_function (public)
 
     //#include "Ldirichlet_series.h" //for computing Dirichlet series
     Complex partial_dirichlet_series(Complex s, long long N1, long long N2);
-    Complex dirichlet_series(Complex s, long long N);
+    Complex dirichlet_series(Complex s, long long N=-1LL);
 
     //#include "Ltaylor_series.h" //for computing taylor series for Dirichlet series
     //void compute_taylor_series(int N, int K, Complex s_0, Complex *series);
