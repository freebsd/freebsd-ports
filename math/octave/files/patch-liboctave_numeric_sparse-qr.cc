--- liboctave/numeric/sparse-qr.cc.orig	2023-04-13 16:43:35 UTC
+++ liboctave/numeric/sparse-qr.cc
@@ -1786,7 +1786,7 @@ sparse_qr<SparseComplexMatrix>::sparse_qr_rep::Q (bool
       OCTAVE_LOCAL_BUFFER (cs_complex_t, bvec, nr);
 
       for (octave_idx_type i = 0; i < nr; i++)
-        bvec[i] = cs_complex_t (0.0, 0.0);
+        bvec[i] = (cs_complex_t)0;
 
       OCTAVE_LOCAL_BUFFER (Complex, buf, S->m2);
 
@@ -1813,7 +1813,7 @@ sparse_qr<SparseComplexMatrix>::sparse_qr_rep::Q (bool
           for (octave_idx_type i = 0; i < nr; i++)
             vec[i+idx] = buf[i];
 
-          bvec[j] = cs_complex_t (0.0, 0.0);
+          bvec[j] = (cs_complex_t)0;
         }
     }
 
@@ -2073,7 +2073,7 @@ sparse_qr<SparseComplexMatrix>::sparse_qr_rep::tall_so
         Xx[j] = b.xelem (j, i);
 
       for (octave_idx_type j = nr; j < S->m2; j++)
-        buf[j] = cs_complex_t (0.0, 0.0);
+        buf[j] = (cs_complex_t)0;
 
       CXSPARSE_ZNAME (_ipvec) (S->pinv,
                                reinterpret_cast<cs_complex_t *>(Xx),
@@ -2143,7 +2143,7 @@ sparse_qr<SparseComplexMatrix>::sparse_qr_rep::wide_so
         Xx[j] = b.xelem (j, i);
 
       for (octave_idx_type j = nr; j < nbuf; j++)
-        buf[j] = cs_complex_t (0.0, 0.0);
+        buf[j] = (cs_complex_t)0;
 
       CXSPARSE_ZNAME (_pvec) (S->q, reinterpret_cast<cs_complex_t *> (Xx),
                               buf, nr);
@@ -2206,7 +2206,7 @@ sparse_qr<SparseComplexMatrix>::sparse_qr_rep::tall_so
         Xx[j] = b.xelem (j, i);
 
       for (octave_idx_type j = nr; j < S->m2; j++)
-        buf[j] = cs_complex_t (0.0, 0.0);
+        buf[j] = (cs_complex_t)0;
 
       CXSPARSE_ZNAME (_ipvec) (S->pinv,
                                reinterpret_cast<cs_complex_t *> (Xx),
@@ -2304,7 +2304,7 @@ sparse_qr<SparseComplexMatrix>::sparse_qr_rep::wide_so
         Xx[j] = b.xelem (j, i);
 
       for (octave_idx_type j = nr; j < nbuf; j++)
-        buf[j] = cs_complex_t (0.0, 0.0);
+        buf[j] = (cs_complex_t)0;
 
       CXSPARSE_ZNAME (_pvec) (S->q,
                               reinterpret_cast<cs_complex_t *> (Xx),
@@ -2392,7 +2392,7 @@ sparse_qr<SparseComplexMatrix>::sparse_qr_rep::tall_so
       octave_quit ();
 
       for (octave_idx_type j = nr; j < S->m2; j++)
-        buf[j] = cs_complex_t (0.0, 0.0);
+        buf[j] = (cs_complex_t)0;
 
       CXSPARSE_ZNAME (_ipvec) (S->pinv, bvec + bidx, buf, nr);
 
@@ -2460,7 +2460,7 @@ sparse_qr<SparseComplexMatrix>::sparse_qr_rep::wide_so
       octave_quit ();
 
       for (octave_idx_type j = nr; j < nbuf; j++)
-        buf[j] = cs_complex_t (0.0, 0.0);
+        buf[j] = (cs_complex_t)0;
 
       CXSPARSE_ZNAME (_pvec) (S->q, bvec + bidx, buf, nr);
       CXSPARSE_ZNAME (_utsolve) (N->U, buf);
@@ -2522,7 +2522,7 @@ sparse_qr<SparseComplexMatrix>::sparse_qr_rep::tall_so
         Xx[j] = b.xelem (j, i);
 
       for (octave_idx_type j = nr; j < S->m2; j++)
-        buf[j] = cs_complex_t (0.0, 0.0);
+        buf[j] = (cs_complex_t)0;
 
       CXSPARSE_ZNAME (_ipvec) (S->pinv,
                                reinterpret_cast<cs_complex_t *> (Xx),
@@ -2620,7 +2620,7 @@ sparse_qr<SparseComplexMatrix>::sparse_qr_rep::wide_so
         Xx[j] = b.xelem (j, i);
 
       for (octave_idx_type j = nr; j < nbuf; j++)
-        buf[j] = cs_complex_t (0.0, 0.0);
+        buf[j] = (cs_complex_t)0;
 
       CXSPARSE_ZNAME (_pvec) (S->q, reinterpret_cast<cs_complex_t *>(Xx),
                               buf, nr);
