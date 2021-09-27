--- tests/test_misc.py.orig	2020-01-17 17:08:15 UTC
+++ tests/test_misc.py
@@ -214,7 +214,7 @@ class TestCaseMisc(PexpectTestCase.PexpectTestCase):
         # Force an invalid state to test isalive
         child.ptyproc.terminated = 0
         try:
-            with self.assertRaisesRegexp(pexpect.ExceptionPexpect,
+            with self.assertRaisesRegex(pexpect.ExceptionPexpect,
                                          ".*" + expect_errmsg):
                 child.isalive()
         finally:
@@ -224,7 +224,7 @@ class TestCaseMisc(PexpectTestCase.PexpectTestCase):
     def test_bad_arguments_suggest_fdpsawn(self):
         " assert custom exception for spawn(int). "
         expect_errmsg = "maybe you want to use fdpexpect.fdspawn"
-        with self.assertRaisesRegexp(pexpect.ExceptionPexpect,
+        with self.assertRaisesRegex(pexpect.ExceptionPexpect,
                                      ".*" + expect_errmsg):
             pexpect.spawn(1)
 
