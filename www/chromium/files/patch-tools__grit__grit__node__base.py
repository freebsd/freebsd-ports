--- tools/grit/grit/node/base.py.orig	2013-08-09 22:25:28.000000000 +0300
+++ tools/grit/grit/node/base.py	2013-08-16 21:30:43.000000000 +0300
@@ -460,6 +460,7 @@
         'is_win': target_platform in ('cygwin', 'win32'),
         'is_android': target_platform == 'android',
         'is_ios': target_platform == 'ios',
+        'is_bsd': 'bsd' in target_platform,
         'is_posix': (target_platform in ('darwin', 'linux2', 'linux3', 'sunos5',
                                          'android', 'ios')
                     or 'bsd' in target_platform),
