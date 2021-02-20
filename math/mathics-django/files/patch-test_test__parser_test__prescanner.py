--- test/test_parser/test_prescanner.py.orig	2021-02-15 21:52:59 UTC
+++ test/test_parser/test_prescanner.py
@@ -1,8 +1,8 @@
 
 import unittest
 
-from mathics.core.parser import IncompleteSyntaxError, ScanError
-from mathics.core.parser.prescanner import Prescanner
+from mathics_scanner import IncompleteSyntaxError, ScanError
+from mathics_scanner.prescanner import Prescanner
 from mathics.core.parser.feed import SingleLineFeeder
 
 
