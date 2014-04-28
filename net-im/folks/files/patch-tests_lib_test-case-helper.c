--- tests/lib/test-case-helper.c.orig	2014-03-17 11:18:49.378390131 +0000
+++ tests/lib/test-case-helper.c	2014-03-17 11:19:02.351392648 +0000
@@ -75,7 +75,7 @@
 {
   FolksTestCaseWeakMethod *wm;
 
-  g_return_if_fail (self == (FolksTestCase *) test_target);
+  g_return_val_if_fail (self == (FolksTestCase *) test_target, NULL);
 
   /* This will never be freed, so make sure not to hold references. */
   wm = g_new0 (FolksTestCaseWeakMethod, 1);
