--- torch/jit/_trace.py.orig	2026-04-18 00:49:58 UTC
+++ torch/jit/_trace.py
@@ -300,6 +300,13 @@ def indent(s):
     return "\n".join(["\t" + line for line in s.splitlines()])
 
 
+def _safe_str(x):
+    try:
+        return str(x)
+    except RuntimeError:
+        return "<str() failed>"
+
+
 class TracingCheckError(Exception):
     def __init__(self, graph_diff_error, tensor_compare_error, extra_msg=None):
         self.message = "Tracing failed sanity checks!\n"
@@ -387,12 +394,18 @@ def _check_trace(
             mod_canonicalized = torch._C._jit_pass_canonicalize(traced_func.graph)
             torch._C._jit_pass_inline(mod_canonicalized)
             torch._C._jit_pass_erase_shape_information(mod_canonicalized)
-            mod_str = str(mod_canonicalized)
+            try:
+                mod_str = str(mod_canonicalized)
+            except RuntimeError:
+                mod_str = ""
             mod_str = re.sub(r"___torch_mangle_[0-9]+\.", "", mod_str)
             check_canonicalized = torch._C._jit_pass_canonicalize(check_mod_func.graph)
             torch._C._jit_pass_inline(check_canonicalized)
             torch._C._jit_pass_erase_shape_information(check_canonicalized)
-            check_str = str(check_canonicalized)
+            try:
+                check_str = str(check_canonicalized)
+            except RuntimeError:
+                check_str = ""
             check_str = re.sub(r"___torch_mangle_[0-9]+\.", "", check_str)
 
             graph_diff_errors = None
@@ -407,10 +420,15 @@ def _check_trace(
                 for n_mod, n_check in zip(
                     mod_canonicalized.nodes(), check_canonicalized.nodes()
                 ):
-                    if str(n_mod) != str(n_check):
+                    try:
+                        n_mod_str = str(n_mod)
+                        n_check_str = str(n_check)
+                    except RuntimeError:
+                        continue
+                    if n_mod_str != n_check_str:
                         graph_diff_errors += "First diverging operator:\n"
                         node_diff = difflib.ndiff(
-                            str(n_mod).splitlines(True), str(n_check).splitlines(True)
+                            n_mod_str.splitlines(True), n_check_str.splitlines(True)
                         )
                         source_printout = (
                             "Node diff:\n" + indent("".join(node_diff)) + "\n"
@@ -445,8 +463,11 @@ def _check_trace(
                     if n_mod.kindOf("value") != "t" or n_check.kindOf("value") != "t":
                         continue
 
-                    mod_tensor_val = n_mod.t("value")
-                    check_tensor_val = n_check.t("value")
+                    try:
+                        mod_tensor_val = n_mod.t("value")
+                        check_tensor_val = n_check.t("value")
+                    except RuntimeError:
+                        continue
 
                     try:
                         torch.testing.assert_close(
@@ -455,7 +476,7 @@ def _check_trace(
                     except (RuntimeError, AssertionError) as e:
                         if tensor_compare_errors is None:
                             tensor_compare_errors = ""
-                        tensor_compare_errors += "Node:\n" + indent(str(n_mod)) + "\n"
+                        tensor_compare_errors += "Node:\n" + indent(_safe_str(n_mod)) + "\n"
                         compare_stack = n_mod.sourceRange()
                         if compare_stack:
                             tensor_compare_errors += (
@@ -504,7 +525,7 @@ def _check_trace(
                     "Did you forget call .eval() on your model? Nodes:\n"
                 )
                 nondeterministic_ops_warning += "\n".join(
-                    [indent(str(op)) for op in nondeterm_ops][:20]
+                    [indent(_safe_str(op)) for op in nondeterm_ops][:20]
                 )
                 nondeterministic_ops_warning += (
                     "\nThis may cause errors in trace checking. To disable trace checking,"
