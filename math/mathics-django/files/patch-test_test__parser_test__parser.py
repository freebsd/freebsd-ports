--- test/test_parser/test_parser.py.orig	2021-02-15 21:43:26 UTC
+++ test/test_parser/test_parser.py
@@ -6,7 +6,7 @@ import sys
 import random
 import unittest
 
-from mathics.core.parser.errors import ScanError, IncompleteSyntaxError, InvalidSyntaxError
+from mathics_scanner import ScanError, IncompleteSyntaxError, InvalidSyntaxError
 from mathics.core.parser.ast import Node, Symbol, Number, String, Filename
 from mathics.core.parser.feed import SingleLineFeeder
 from mathics.core.parser.parser import Parser
