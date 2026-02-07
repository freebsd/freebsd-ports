--- src/rendercv/cli/render_command/run_rendercv.py.orig	2025-12-20 00:43:25 UTC
+++ src/rendercv/cli/render_command/run_rendercv.py
@@ -19,13 +19,13 @@ from .progress_panel import ProgressPanel
 from .progress_panel import ProgressPanel
 
 
-def timed_step[T, **P](
+def timed_step(
     message: str,
     progress_panel: ProgressPanel,
-    func: Callable[P, T],
-    *args: P.args,
-    **kwargs: P.kwargs,
-) -> T:
+    func,
+    *args,
+    **kwargs,
+):
     """Execute function, measure timing, and update progress panel with result.
 
     Why:
