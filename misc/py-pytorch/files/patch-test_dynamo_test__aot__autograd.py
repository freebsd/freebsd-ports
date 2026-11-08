--- test/dynamo/test_aot_autograd.py.orig	2026-09-02 17:43:46 UTC
+++ test/dynamo/test_aot_autograd.py
@@ -2,6 +2,7 @@ import re
 import copy
 import operator
 import re
+import sys
 import unittest
 from textwrap import dedent
 from unittest.mock import patch
@@ -1018,6 +1019,7 @@ SeqNr|OrigAten|SrcFn|FwdSrcFn
 
     # set donated_buffer=False due to create_graph=True
     @torch._functorch.config.patch("donated_buffer", False)
+    @unittest.skipIf(sys.platform.startswith("freebsd"), "Kineto causes SIGABRT on FreeBSD")
     def test_eager_sequence_nr(self):
         class Model(torch.nn.Module):
             def __init__(self) -> None:
