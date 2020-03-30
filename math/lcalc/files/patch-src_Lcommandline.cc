--- src/Lcommandline.cc.orig	2012-08-08 21:21:56 UTC
+++ src/Lcommandline.cc
@@ -18,6 +18,8 @@ Check the License for details. You should have receive
 with the package; see the file 'COPYING'. If not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
+   Patches borrowed from SageMath.
+
 */
 
 
@@ -412,12 +414,7 @@ int main (int argc, char *argv[])
 
             t2=.5; //t2=.5 because of the GAMMA(s+1/2)
 
-            pari_init(1000000000,2);
-            //pari_init_opts(400000000,2,INIT_DFTm); // the last option is to prevent
-            //pari from giving its interrupt signal when its elliptic curve a_p
-            //algorithm is called and interrupted with ctrl-c. Requires a more current
-            //version of pari, so use pari_init above until I have a configure set up
-            //that detects which pari, if any, is installed.
+            pari_init_opts(16000000, 2, INIT_DFTm);
 
             coeff = new Double[3];
             //compute the conductor which is copied to coeff[1]
@@ -473,7 +470,9 @@ int main (int argc, char *argv[])
 
 #ifdef INCLUDE_PARI
         if(do_elliptic_curve){
-             allocatemoremem((int) N_terms*16+1000000); //XXXXXXXXX this should depend on whether we're double or long double or mpfr double
+             // Reallocate PARI stack
+             paristack_setsize((size_t)N_terms*16 + 1000000, 0); //XXXXXXXXX this should depend on whether we're double or long double or mpfr double
+
              if (my_verbose>0) cout << "Will precompute " << N_terms << " elliptic L-function dirichlet coefficients..." << endl;
              initialize_new_L(a1,a2,a3,a4,a6,N_terms); 
         }
