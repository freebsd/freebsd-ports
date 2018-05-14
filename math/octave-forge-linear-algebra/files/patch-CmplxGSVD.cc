--- CmplxGSVD.cc.orig	2015-01-24 19:54:11 UTC
+++ CmplxGSVD.cc
@@ -14,13 +14,12 @@
 // You should have received a copy of the GNU General Public License along with
 // this program; if not, see <http://www.gnu.org/licenses/>.
 
-#ifdef HAVE_CONFIG_H
-#include <config.h>
-#endif
+#include "CmplxGSVD.h"
 
 #include <iostream>
 
-#include "CmplxGSVD.h"
+#include <octave/oct.h>
+
 #include "f77-fcn.h"
 #include "lo-error.h"
 
@@ -30,6 +29,13 @@
    #include "pager.h"
 */
 
+#if defined (OCTAVE_HAVE_F77_INT_TYPE)
+#  define TO_F77_INT(x) octave::to_f77_int (x)
+#else
+typedef octave_idx_type F77_INT;
+#  define TO_F77_INT(x) (x)
+#endif
+
 extern "C"
 {
   F77_RET_T
@@ -38,27 +44,27 @@ extern "C"
      F77_CONST_CHAR_ARG_DECL, 	// JOBU    (input) CHARACTER*1
      F77_CONST_CHAR_ARG_DECL, 	// JOBV    (input) CHARACTER*1
      F77_CONST_CHAR_ARG_DECL, 	// JOBQ    (input) CHARACTER*1
-     const octave_idx_type&,	// M       (input) INTEGER
-     const octave_idx_type&,	// N       (input) INTEGER
-     const octave_idx_type&,	// P       (input) INTEGER
-     octave_idx_type &, 	// K       (output) INTEGER
-     octave_idx_type &,		// L       (output) INTEGER
+     const F77_INT&,        	// M       (input) INTEGER
+     const F77_INT&,        	// N       (input) INTEGER
+     const F77_INT&,        	// P       (input) INTEGER
+     F77_INT&,                  // K       (output) INTEGER
+     F77_INT&,                  // L       (output) INTEGER
      Complex*,			// A       (input/output) COMPLEX*16 array, dimension (LDA,N)
-     const octave_idx_type&, 	// LDA     (input) INTEGER
+     const F77_INT&,         	// LDA     (input) INTEGER
      Complex*, 			// B       (input/output) COMPLEX*16 array, dimension (LDB,N)
-     const octave_idx_type&, 	// LDB     (input) INTEGER
+     const F77_INT&,         	// LDB     (input) INTEGER
      double*, 			// ALPHA   (output) DOUBLE PRECISION array, dimension (N)
      double*, 			// BETA    (output) DOUBLE PRECISION array, dimension (N)
      Complex*,			// U       (output) COMPLEX*16 array, dimension (LDU,M)
-     const octave_idx_type&,	// LDU     (input) INTEGER 
+     const F77_INT&,        	// LDU     (input) INTEGER 
      Complex*, 			// V       (output) COMPLEX*16 array, dimension (LDV,P)
-     const octave_idx_type&,	// LDV     (input) INTEGER
+     const F77_INT&,        	// LDV     (input) INTEGER
      Complex*,			// Q       (output) COMPLEX*16 array, dimension (LDQ,N) 
-     const octave_idx_type&,	// LDQ     (input) INTEGER
+     const F77_INT&,        	// LDQ     (input) INTEGER
      Complex*, 			// WORK    (workspace) COMPLEX*16 array
      double*,			// RWORK   (workspace) DOUBLE PRECISION array
-     int*,	 		// IWORK   (workspace/output) INTEGER array, dimension (N)
-     octave_idx_type&		// INFO    (output)INTEGER
+     F77_INT*,                  // IWORK   (workspace/output) INTEGER array, dimension (N)
+     F77_INT&                   // INFO    (output)INTEGER
      F77_CHAR_ARG_LEN_DECL
      F77_CHAR_ARG_LEN_DECL
      F77_CHAR_ARG_LEN_DECL
@@ -121,11 +127,11 @@ octave_idx_type
 ComplexGSVD::init (const ComplexMatrix& a, const ComplexMatrix& b, 
 		   GSVD::type gsvd_type)
 {
-  octave_idx_type info;
+  F77_INT info;
 
-  octave_idx_type m = a.rows ();
-  octave_idx_type n = a.cols ();
-  octave_idx_type p = b.rows ();
+  F77_INT m = TO_F77_INT (a.rows ());
+  F77_INT n = TO_F77_INT (a.cols ());
+  F77_INT p = TO_F77_INT (b.rows ());
   
   ComplexMatrix atmp = a;
   Complex *tmp_dataA = atmp.fortran_vec ();
@@ -133,17 +139,17 @@ ComplexGSVD::init (const ComplexMatrix& 
   ComplexMatrix btmp = b;
   Complex *tmp_dataB = btmp.fortran_vec ();
 
-  // octave_idx_type min_mn = m < n ? m : n;
+  // F77_INT min_mn = m < n ? m : n;
 
   char jobu = 'U';
   char jobv = 'V';
   char jobq = 'Q';
 
-  octave_idx_type nrow_u = m;
-  octave_idx_type nrow_v = p;
-  octave_idx_type nrow_q = n;
+  F77_INT nrow_u = m;
+  F77_INT nrow_v = p;
+  F77_INT nrow_q = n;
 
-  octave_idx_type k, l;
+  F77_INT k, l;
 
   switch (gsvd_type)
     {
@@ -187,7 +193,7 @@ ComplexGSVD::init (const ComplexMatrix& 
   }
   Complex *q = right_sm.fortran_vec ();  
   
-  octave_idx_type lwork = 3*n;
+  F77_INT lwork = 3*n;
   lwork = lwork > m ? lwork : m;
   lwork = (lwork > p ? lwork : p) + n;
 
@@ -195,7 +201,7 @@ ComplexGSVD::init (const ComplexMatrix& 
   Array<double>   alpha (dim_vector (n, 1));
   Array<double>   beta (dim_vector (n, 1));
   Array<double>   rwork(dim_vector (2*n, 1));
-  Array<int>      iwork (dim_vector (n, 1));
+  Array<F77_INT>  iwork (dim_vector (n, 1));
 
   F77_XFCN (zggsvd, ZGGSVD, (F77_CONST_CHAR_ARG2 (&jobu, 1),
 			     F77_CONST_CHAR_ARG2 (&jobv, 1),
@@ -219,13 +225,13 @@ ComplexGSVD::init (const ComplexMatrix& 
     if (info > 0) {
       (*current_liboctave_error_handler) ("zggsvd.f: Jacobi-type procedure failed to converge."); 
     } else {
-      octave_idx_type i, j;
+      F77_INT i, j;
       
       if (GSVD::std == gsvd_type) {
 	R.resize(k+l, k+l); 
-	int astart = n-k-l;
+	F77_INT astart = n-k-l;
 	if (m - k - l >=  0) {
-	  int astart = n-k-l;
+	  F77_INT astart = n-k-l;
 	  /*
 	   *  R is stored in A(1:K+L,N-K-L+1:N)
 	   */
