# mock dependency set in TEST_DEPENDS is actually backports.unittest_mock
# but this package doesn't exist in the ports tree yet, so adjust the import
# here to import 'mock' proper. TODO

--- tests/test_crypto.py.orig	2019-01-04 05:26:47 UTC
+++ tests/test_crypto.py
@@ -1,5 +1,5 @@
 import unittest
-from unittest import mock
+import mock
 
 from .test_file import FileKeyringTests
 
