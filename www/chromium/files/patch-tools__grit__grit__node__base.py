--- tools/grit/grit/node/base.py.orig	2013-03-06 22:30:09.000000000 +0200
+++ tools/grit/grit/node/base.py	2013-03-06 22:33:00.000000000 +0200
@@ -447,6 +447,7 @@
         'is_linux': target_platform.startswith('linux'),
         'is_macosx': target_platform == 'darwin',
         'is_win': target_platform in ('cygwin', 'win32'),
+        'is_bsd': 'bsd' in target_platform,
         'is_posix': (target_platform in ('darwin', 'linux2', 'linux3', 'sunos5')
                      or 'bsd' in target_platform),
         'pp_ifdef' : pp_ifdef,
