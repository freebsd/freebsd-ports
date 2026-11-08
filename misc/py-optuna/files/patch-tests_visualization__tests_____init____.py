-- Skip plotly static image export in visualization tests.  The kaleido
-- package required for plotly write_image is not available in FreeBSD Ports,
-- so these tests would otherwise fail.
--- tests/visualization_tests/__init__.py.orig	2026-08-04 00:02:01 UTC
+++ tests/visualization_tests/__init__.py
@@ -0,0 +1,9 @@
+try:
+    import kaleido  # noqa: F401
+except ImportError:
+    import plotly.graph_objects as go
+
+    def _write_image(self, *args, **kwargs):
+        pass
+
+    go.Figure.write_image = _write_image
