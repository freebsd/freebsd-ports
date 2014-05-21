--- ./chrome/chrome_tests.gypi.orig	2014-04-30 22:42:53.000000000 +0200
+++ ./chrome/chrome_tests.gypi	2014-05-05 18:29:40.000000000 +0200
@@ -1628,7 +1628,7 @@
         'test/remoting/remote_desktop_browsertest.h',
         'test/remoting/waiter.cc',
         'test/remoting/waiter.h',
-        'test/security_tests/sandbox_browsertest_linux.cc',
+        #'test/security_tests/sandbox_browsertest_linux.cc',
         'test/security_tests/sandbox_browsertest_win.cc',
         # TODO(craig): Rename this and run from base_unittests when the test
         # is safe to run there. See http://crbug.com/78722 for details.
