--- test/test_parser/test_util.py.orig	2021-02-15 21:52:59 UTC
+++ test/test_parser/test_util.py
@@ -1,7 +1,8 @@
 import unittest
 
 from mathics.core.definitions import Definitions
-from mathics.core.parser import parse, InvalidSyntaxError, IncompleteSyntaxError
+from mathics.core.parser import parse
+from mathics_scanner import InvalidSyntaxError, IncompleteSyntaxError
 from mathics.core.parser.feed import SingleLineFeeder, MultiLineFeeder
 
 
