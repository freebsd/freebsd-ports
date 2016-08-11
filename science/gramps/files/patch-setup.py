--- setup.py.orig	2016-01-06 16:44:13 UTC
+++ setup.py
@@ -56,6 +56,11 @@ ALL_LINGUAS = ('ar', 'bg', 'ca', 'cs', '
                'zh_CN', 'zh_HK', 'zh_TW')
 INTLTOOL_FILES = ('data/tips.xml', 'gramps/plugins/lib/holidays.xml')
 
+svem_flag = '--single-version-externally-managed'
+if svem_flag in sys.argv:
+    # Die, setuptools, die.
+    sys.argv.remove(svem_flag)
+
 server = False
 if '--server' in sys.argv:
     sys.argv.remove('--server')
@@ -180,8 +185,8 @@ def build_man(build_cmd):
                 filename = False
 
             lang = man_dir[8:]
-            src = build_cmd.build_base  + '/data/man/' + lang  + '/gramps.1.gz'
-            target = 'share/man/' + lang + '/man1'
+            src = build_cmd.build_base  + '/data/man' + lang  + '/gramps.1.gz'
+            target = 'share/man' + lang + '/man1'
             data_files.append((target, [src]))
 
             log.info('Compiling %s >> %s.', src, target)
