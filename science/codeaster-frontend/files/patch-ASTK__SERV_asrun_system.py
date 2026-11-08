--- ASTK_SERV/asrun/system.py.orig	2026-10-24 15:21:16 UTC
+++ ASTK_SERV/asrun/system.py
@@ -34,6 +34,7 @@ from asrun.common.sysutils import (
 from asrun.common.utils import get_tmpname_base, get_encoding, now
 from asrun.common.sysutils import (
     FileName,
+    on_freebsd,
     on_linux,
     on_mac,
     on_windows,
@@ -852,7 +853,10 @@ class AsterSystem:
                 except ValueError:
                     pass
             elif on_linux():
-                iret, out = self.Shell('cat /proc/cpuinfo', mach, user)
+                if on_freebsd():
+                    iret, out = self.Shell('sysctl -n hw.ncpu', mach, user)
+                else:
+                    iret, out = self.Shell('cat /proc/cpuinfo', mach, user)
                 exp = re.compile(r'^processor\s+:\s+([0-9]+)', re.MULTILINE)
                 l_ids = exp.findall(out)
                 if len(l_ids) >= 1:      # else: it should not !
@@ -874,7 +878,10 @@ class AsterSystem:
         if what in ('memtotal',):
             num = None
             if on_linux():
-                iret, out = self.Shell('cat /proc/meminfo', mach, user)
+                if on_freebsd():
+                    iret, out = self.Shell('sysctl -n hw.physmem', mach, user)
+                else:
+                    iret, out = self.Shell('cat /proc/meminfo', mach, user)
                 mat = re.search(r'^%s *: *([0-9]+) *kb' % what, out, re.MULTILINE | re.IGNORECASE)
                 if mat is not None:         # else: it should not !
                     num = int(mat.group(1)) // 1024
