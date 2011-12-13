--- build/common.gypi.orig	2011-11-10 16:01:45.000000000 +0200
+++ build/common.gypi	2011-12-01 00:10:48.000000000 +0200
@@ -403,6 +403,10 @@
     # able to turn it off for remote debugging on Chromium OS
     'linux_disable_pie%': 0,
 
+    'os_ver%': 0,
+    'prefix_dir%': '/usr',
+    'use_system_tcmalloc%': 0,
+
     # The release channel that this build targets. This is used to restrict
     # channel-specific build options, like which installer packages to create.
     # The default is 'all', which does no channel-specific filtering.
@@ -615,7 +619,7 @@
         # This is used to tweak build flags for gcc 4.4.
         'gcc_version%': '<!(python <(DEPTH)/build/compiler_version.py)',
         # Figure out the python architecture to decide if we build pyauto.
-        'python_arch%': '<!(<(DEPTH)/build/linux/python_arch.sh <(sysroot)/usr/<(system_libdir)/libpython<(python_ver).so.1.0)',
+        'python_arch%': '<!(<(DEPTH)/build/linux/python_arch.sh <(sysroot)<(prefix_dir)/lib/libpython<(python_ver).so.1)',
         'conditions': [
           ['branding=="Chrome"', {
             'linux_breakpad%': 1,
@@ -1242,7 +1246,7 @@
               ['exclude', '(^|/)(wayland)_[^/]*\\.(h|cc)$'],
             ],
           }],
-          ['OS!="linux"', {
+          ['OS!="linux" and OS!="freebsd"', {
             'sources/': [
               ['exclude', '_linux(_unittest)?\\.(h|cc)$'],
               ['exclude', '(^|/)linux/'],
@@ -1911,6 +1915,22 @@
         'ldflags': [
           '-Wl,--no-keep-memory',
         ],
+        'ldflags!': [
+          '-ldl',
+          '-pie',
+        ],
+        'libraries!': [
+          '-ldl',
+        ],
+        'conditions': [
+          ['gcc_version == 42', {
+            'cflags!': [
+              '-mssse3',
+              '-fno-signed-zeros',
+              '-Wno-unused-result',
+            ],
+          }],
+        ],
       },
     }],
     # Android-specific options; note that most are set above with Linux.
