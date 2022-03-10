--- scipy/sparse/tests/test_base.py.orig	2022-03-02 10:42:47 UTC
+++ scipy/sparse/tests/test_base.py
@@ -4758,19 +4758,19 @@ class TestCSCNonCanonical(_NonCanonicalCSMixin, TestCS
     pass
 
 
-class TestBSRNonCanonical(_NonCanonicalCompressedMixin, TestBSR):
-    def _insert_explicit_zero(self, M, i, j):
-        x = M.tocsr()
-        x[i,j] = 0
-        return x.tobsr(blocksize=M.blocksize)
-
-    @pytest.mark.xfail(run=False, reason='diagonal broken with non-canonical BSR')
-    def test_diagonal(self):
-        pass
-
-    @pytest.mark.xfail(run=False, reason='expm broken with non-canonical BSR')
-    def test_expm(self):
-        pass
+#class TestBSRNonCanonical(_NonCanonicalCompressedMixin, TestBSR):
+#    def _insert_explicit_zero(self, M, i, j):
+#        x = M.tocsr()
+#        x[i,j] = 0
+#        return x.tobsr(blocksize=M.blocksize)
+#
+#    @pytest.mark.xfail(run=False, reason='diagonal broken with non-canonical BSR')
+#    def test_diagonal(self):
+#        pass
+#
+#    @pytest.mark.xfail(run=False, reason='expm broken with non-canonical BSR')
+#    def test_expm(self):
+#        pass
 
 
 class TestCOONonCanonical(_NonCanonicalMixin, TestCOO):
