--- test/test_parser/test_convert.py.orig	2021-02-15 21:52:59 UTC
+++ test/test_parser/test_convert.py
@@ -3,8 +3,9 @@ import random
 import sys
 
 from mathics.core.definitions import Definitions
-from mathics.core.parser import (
-    parse, InvalidSyntaxError, IncompleteSyntaxError,
+from mathics.core.parser import parse
+from mathics_scanner import (
+    InvalidSyntaxError, IncompleteSyntaxError,
     ScanError)
 from mathics.core.parser.feed import SingleLineFeeder
 from mathics.core.expression import (
