# mock dependency set in TEST_DEPENDS is actually backports.unittest_mock
# but this package doesn't exist in the ports tree yet, so adjust the import
# here to import 'mock' proper. TODO

--- tests/test_file.py.orig	2022-09-05 01:38:48 UTC
+++ tests/test_file.py
@@ -6,7 +6,7 @@ import getpass
 import configparser
 
 import pytest
-from unittest import mock
+import mock
 
 from keyring.testing.backend import BackendBasicTests
 from keyring.testing.util import random_string
