--- build/common.gypi.orig	2012-01-25 10:01:56.000000000 +0200
+++ build/common.gypi	2012-01-29 21:49:50.000000000 +0200
@@ -406,6 +406,11 @@
     # able to turn it off for remote debugging on Chromium OS
     'linux_disable_pie%': 0,
 
+    'os_ver%': 0,
+    'prefix_dir%': '/usr',
+    'use_system_tcmalloc%': 0,
+    'use_system_libjpeg%': 0,
+
     # The release channel that this build targets. This is used to restrict
     # channel-specific build options, like which installer packages to create.
     # The default is 'all', which does no channel-specific filtering.
@@ -632,7 +637,7 @@
         # This is used to tweak build flags for gcc 4.4.
         'gcc_version%': '<!(python <(DEPTH)/build/compiler_version.py)',
         # Figure out the python architecture to decide if we build pyauto.
-        'python_arch%': '<!(<(DEPTH)/build/linux/python_arch.sh <(sysroot)/usr/<(system_libdir)/libpython<(python_ver).so.1.0)',
+        'python_arch%': '<!(<(DEPTH)/build/linux/python_arch.sh <(sysroot)<(prefix_dir)/lib/libpython<(python_ver).so.1)',
         'conditions': [
           ['branding=="Chrome"', {
             'linux_breakpad%': 1,
@@ -1973,6 +1978,22 @@
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
