--- test/test_parser/test_tokeniser.py.orig	2021-02-15 21:52:59 UTC
+++ test/test_parser/test_tokeniser.py
@@ -3,8 +3,9 @@ import unittest
 import random
 import sys
 
-from mathics.core.parser.tokeniser import Tokeniser, Token
-from mathics.core.parser.errors import ScanError, IncompleteSyntaxError, InvalidSyntaxError
+from mathics_scanner import Tokeniser
+from mathics_scanner.tokeniser import Token
+from mathics_scanner import ScanError, IncompleteSyntaxError, InvalidSyntaxError
 from mathics.core.parser.feed import SingleLineFeeder
 
 
