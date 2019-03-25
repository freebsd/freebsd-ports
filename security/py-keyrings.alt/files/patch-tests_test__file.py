# mock dependency set in TEST_DEPENDS is actually backports.unittest_mock
# but this package doesn't exist in the ports tree yet, so adjust the import
# here to import 'mock' proper. TODO

--- tests/test_file.py.orig	2019-01-04 05:24:38 UTC
+++ tests/test_file.py
@@ -7,7 +7,7 @@ import unittest
 from six.moves import configparser
 
 import pytest
-from unittest import mock
+import mock
 
 from keyring.tests.test_backend import BackendBasicTests
 from keyring.tests.util import random_string
