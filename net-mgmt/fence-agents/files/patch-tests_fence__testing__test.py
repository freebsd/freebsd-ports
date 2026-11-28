--- tests/fence_testing_test.py.orig	2026-11-28 15:56:03 UTC
+++ tests/fence_testing_test.py
@@ -9,7 +9,7 @@ class TestPrepareCommand(unittest.TestCase):
 	DEVICE_CORRECT_WITH_ACTION = "devices.d/true-with_action.cfg"
 
 	def test_missing_device(self):
-		self.assertRaises(fence_testing._prepare_command, None, "getopt")
+		self.assertRaises(AssertionError, fence_testing._prepare_command, None, "getopt")
 
 	def test_missing_option(self):
 		self.assertRaises(AssertionError, fence_testing._prepare_command, self.DEVICE_MISSING_OPTION, "stdin")
