This patch is the origin of the upstream contribution referenced by
https://github.com/njsmith/scikits-sparse/pull/12

--- scikits/sparse/test_cholmod.py.orig	2015-06-24 10:39:06 UTC
+++ scikits/sparse/test_cholmod.py
@@ -53,17 +53,17 @@ def test_integer_size():
 def test_cholesky_smoke_test():
     f = cholesky(sparse.eye(10, 10) * 1.)
     d = np.arange(20).reshape(10, 2)
-    print "dense"
+    print("dense")
     assert np.allclose(f(d), d)
-    print "sparse"
+    print("sparse")
     s_csc = sparse.csc_matrix(np.eye(10)[:, :2] * 1.)
     assert sparse.issparse(f(s_csc))
     assert np.allclose(f(s_csc).todense(), s_csc.todense())
-    print "csr"
+    print("csr")
     s_csr = s_csc.tocsr()
     assert sparse.issparse(f(s_csr))
     assert np.allclose(f(s_csr).todense(), s_csr.todense())
-    print "extract"
+    print("extract")
     assert np.all(f.P() == np.arange(10))
 
 def real_matrix():
@@ -193,7 +193,7 @@ def test_cholesky_matrix_market():
             f3.cholesky_AAt_inplace(X.T)
             assert np.allclose(f3(Xty), answer)
 
-            print problem, mode
+            print(problem, mode)
             for f in (f1, f2, f3, f4):
                 pXtX = XtX.todense()[f.P()[:, np.newaxis],
                                      f.P()[np.newaxis, :]]
