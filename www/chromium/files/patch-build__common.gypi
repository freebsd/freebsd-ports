--- build/common.gypi.orig	2011-09-12 11:35:33.000000000 +0300
+++ build/common.gypi	2011-09-16 19:05:37.000000000 +0300
@@ -303,6 +303,10 @@
     'enable_register_protocol_handler%': '<(enable_register_protocol_handler)',
     'enable_smooth_scrolling%': '<(enable_smooth_scrolling)',
 
+    'os_ver%': 0,
+    'prefix_dir%': '/usr',
+    'use_system_tcmalloc%': 0,
+
     # The release channel that this build targets. This is used to restrict
     # channel-specific build options, like which installer packages to create.
     # The default is 'all', which does no channel-specific filtering.
@@ -516,7 +520,7 @@
         # This is used to tweak build flags for gcc 4.4.
         'gcc_version%': '<!(python <(DEPTH)/build/compiler_version.py)',
         # Figure out the python architecture to decide if we build pyauto.
-        'python_arch%': '<!(<(DEPTH)/build/linux/python_arch.sh <(sysroot)/usr/lib/libpython<(python_ver).so.1.0)',
+        'python_arch%': '<!(<(DEPTH)/build/linux/python_arch.sh <(sysroot)<(prefix_dir)/lib/libpython<(python_ver).so.1)',
         'conditions': [
           ['branding=="Chrome"', {
             'linux_breakpad%': 1,
@@ -956,7 +960,7 @@
               ['exclude', '(^|/)(gtk|x11)_[^/]*\\.(h|cc)$'],
             ],
           }],
-          ['OS!="linux"', {
+          ['OS!="linux" and OS!="freebsd"', {
             'sources/': [
               ['exclude', '_linux(_unittest)?\\.(h|cc)$'],
               ['exclude', '(^|/)linux/'],
@@ -1536,6 +1540,15 @@
         'ldflags': [
           '-Wl,--no-keep-memory',
         ],
+        'ldflags!': [
+          '-ldl',
+        ],
+        'libraries!': [
+          '-ldl',
+        ],
+        'cflags!': [
+          '-fno-signed-zeros',
+        ],
       },
     }],
     ['OS=="solaris"', {
