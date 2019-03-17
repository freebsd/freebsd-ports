--- pyqtdistutils.py.orig	2019-03-17 19:30:42 UTC
+++ pyqtdistutils.py
@@ -272,7 +272,7 @@ class build_ext(distutils.command.build_
                 sip_exe,
                 '-c', self.build_temp
             ] + SIP_FLAGS.split() + [
-                '-I', os.path.join(sip_dir, 'PyQt5'),
+                '-I', sip_dir, # for FreeBSD's SIP file locations
                 '-b', sbf,
                 source
             ]
