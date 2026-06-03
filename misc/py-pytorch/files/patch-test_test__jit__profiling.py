--- test/test_jit_profiling.py.orig	2026-04-18 23:58:15 UTC
+++ test/test_jit_profiling.py
@@ -2,6 +2,13 @@ sys.argv.append("--jit-executor=profiling")
 
 import sys
 sys.argv.append("--jit-executor=profiling")
+from torch.testing._internal.common_utils import parse_cmd_line_args, run_tests  # noqa: F401
+
+if __name__ == '__main__':
+    # The value of GRAPH_EXECUTOR depends on command line arguments so make sure they're parsed
+    # before instantiating tests.
+    parse_cmd_line_args()
+
 from test_jit import *  # noqa: F403
 
 if __name__ == '__main__':
