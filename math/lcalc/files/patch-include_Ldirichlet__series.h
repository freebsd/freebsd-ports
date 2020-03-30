--- include/Ldirichlet_series.h.orig	2012-08-08 21:21:55 UTC
+++ include/Ldirichlet_series.h
@@ -17,6 +17,8 @@
    Check the License for details. You should have received a copy of it, along
    with the package; see the file 'COPYING'. If not, write to the Free Software
    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
+   
+   Patches borrowed from SageMath.
 
 */
 
@@ -43,7 +45,7 @@ partial_dirichlet_series(Complex s, long long N1, long
  //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
 template <class ttype>
 Complex L_function <ttype>::
-dirichlet_series(Complex s, long long N=-1)
+dirichlet_series(Complex s, long long N)
 {
     Complex z=0.;
     long long m,n;
