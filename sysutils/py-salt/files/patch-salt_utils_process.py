--- salt/utils/process.py.orig	2026-02-23 20:07:08 UTC
+++ salt/utils/process.py
@@ -43,11 +43,7 @@
 except ImportError:
     pass
 
-try:
-    import setproctitle
-
-    HAS_SETPROCTITLE = True
-except ImportError:
-    HAS_SETPROCTITLE = False
+# setproctitle disabled: it breaks rc script stop/restart when procname changes
+HAS_SETPROCTITLE = False
 
 # Process finalization function list
