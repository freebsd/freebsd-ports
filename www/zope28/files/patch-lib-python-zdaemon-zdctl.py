--- lib/python/zdaemon/zdctl.py.orig	Fri Oct 24 23:32:59 2003
+++ lib/python/zdaemon/zdctl.py	Fri Apr  2 01:55:59 2004
@@ -208,9 +208,9 @@
             args += self._get_override("-z", "directory")
             args.extend(self.options.program)
             if self.options.daemon:
-                flag = os.P_WAIT
-            else:
                 flag = os.P_NOWAIT
+            else:
+                flag = os.P_WAIT
             os.spawnvp(flag, args[0], args)
         elif not self.zd_pid:
             self.send_action("start")
