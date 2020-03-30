--- include/Lgamma.h.orig	2012-08-08 21:21:55 UTC
+++ include/Lgamma.h
@@ -18,6 +18,8 @@
    with the package; see the file 'COPYING'. If not, write to the Free Software
    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
+   Patches borrowed from SageMath.
+
 */
 
 
@@ -77,7 +79,7 @@ Complex exp_recycle();
 //n=0 should just give log_GAMMA(z)... thus making log_GAMMA
 //code obsolete. But leave log_GAMMA intact anyways.
 template <class ttype>
-precise(ttype) log_GAMMA (ttype z,int n=0)
+precise(ttype) log_GAMMA (ttype z,int n)
 {
     int M;
     precise(ttype) log_G,r,r2,y;
@@ -230,7 +232,7 @@ Complex GAMMA (ttype z1, ttype2 delta)
 //value exp_w which holds exp(-w)
 //computes G(z,w), so there's an extra w^(-z) factor.
 template <class ttype>
-Complex inc_GAMMA (ttype z,ttype w, const char *method="temme", ttype exp_w = 0, bool recycle=false)
+Complex inc_GAMMA (ttype z,ttype w, const char *method, ttype exp_w, bool recycle)
 {
 
     Complex G;
@@ -334,7 +336,7 @@ Complex inc_GAMMA (ttype z,ttype w, const char *method
 
 
 template <class ttype>
-ttype cfrac_GAMMA (ttype z,ttype w, ttype exp_w=0, bool recycle=false)  //computes G(z,w) via continued fraction
+ttype cfrac_GAMMA (ttype z,ttype w, ttype exp_w, bool recycle)  //computes G(z,w) via continued fraction
 {
 
         ttype G;
@@ -424,7 +426,7 @@ ttype cfrac_GAMMA (ttype z,ttype w, ttype exp_w=0, boo
 }
 
 template <class ttype>
-ttype asympt_GAMMA (ttype z,ttype w, ttype exp_w = 0, bool recycle=false)  //computes G(z,w) via asymptotic series
+ttype asympt_GAMMA (ttype z,ttype w, ttype exp_w, bool recycle)  //computes G(z,w) via asymptotic series
 {
 
         if(my_verbose>3) cout << "called asympt_GAMMA("<<z<<","<<w<<")"<< endl;
@@ -446,7 +448,7 @@ ttype asympt_GAMMA (ttype z,ttype w, ttype exp_w = 0, 
 
 
 template <class ttype>
-ttype comp_inc_GAMMA (ttype z,ttype w,ttype exp_w = 0, bool recycle=false)  //computes g(z,w)
+ttype comp_inc_GAMMA (ttype z,ttype w,ttype exp_w, bool recycle)  //computes g(z,w)
 {
 
     ttype g;
@@ -604,7 +606,7 @@ ttype comp_inc_GAMMA (ttype z,ttype w,ttype exp_w = 0,
 }
 
 template <class ttype>
-Complex gamma_sum(Complex s, int what_type, ttype *coeff, int N, Double g, Complex l, Double Q, Long Period, Complex delta=1, const char *method="temme")
+Complex gamma_sum(Complex s, int what_type, ttype *coeff, int N, Double g, Complex l, Double Q, Long Period, Complex delta, const char *method)
 {
     Complex SUM=0;
 
