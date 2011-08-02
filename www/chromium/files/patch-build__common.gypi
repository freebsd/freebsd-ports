--- build/common.gypi.orig	2011-06-26 17:27:43.439782011 +0300
+++ build/common.gypi	2011-06-26 17:27:57.372781037 +0300
@@ -445,7 +445,7 @@
         # This is used to tweak build flags for gcc 4.4.
         'gcc_version%': '<!(python <(DEPTH)/build/compiler_version.py)',
         # Figure out the python architecture to decide if we build pyauto.
-        'python_arch%': '<!(<(DEPTH)/build/linux/python_arch.sh <(sysroot)/usr/lib/libpython<(python_ver).so.1.0)',
+        'python_arch%': '<!(<(DEPTH)/build/linux/python_arch.sh <(sysroot)/usr/local/lib/libpython<(python_ver).so.1.0)',
         'conditions': [
           ['branding=="Chrome"', {
             'linux_breakpad%': 1,
@@ -850,7 +850,7 @@
               ['exclude', '(^|/)(gtk|x11)_[^/]*\\.(h|cc)$'],
             ],
           }],
-          ['OS!="linux"', {
+          ['OS!="linux" and OS!="freebsd"', {
             'sources/': [
               ['exclude', '_linux(_unittest)?\\.(h|cc)$'],
               ['exclude', '(^|/)linux/'],
