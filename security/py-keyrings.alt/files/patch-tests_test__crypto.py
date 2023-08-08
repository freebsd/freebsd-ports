# mock dependency set in TEST_DEPENDS is actually backports.unittest_mock
# but this package doesn't exist in the ports tree yet, so adjust the import
# here to import 'mock' proper. TODO

--- tests/test_crypto.py.orig	2022-10-24 18:56:47 UTC
+++ tests/test_crypto.py
@@ -1,5 +1,5 @@
 import getpass
-from unittest import mock
+import mock
 
 import pytest
 
