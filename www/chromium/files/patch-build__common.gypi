--- build/common.gypi.orig	2011-05-06 12:03:15.000000000 +0300
+++ build/common.gypi	2011-06-05 22:52:31.690163552 +0300
@@ -95,7 +95,7 @@
       'file_manager_extension%': 0,
 
       # Python version.
-      'python_ver%': '2.5',
+      'python_ver%': '2.6',
 
       # Set ARM-v7 compilation flags
       'armv7%': 0,
@@ -256,7 +256,7 @@
 
     # Whether proprietary audio/video codecs are assumed to be included with
     # this build (only meaningful if branding!=Chrome).
-    'proprietary_codecs%': 0,
+    'proprietary_codecs%': 1,
 
     # TODO(bradnelson): eliminate this when possible.
     # To allow local gyp files to prevent release.vsprops from being included.
@@ -321,8 +321,8 @@
     # Disable TCMalloc's debugallocation.
     'linux_use_debugallocation%': 0,
 
-    # Disable TCMalloc's heapchecker.
-    'linux_use_heapchecker%': 0,
+    # Enable TCMalloc's heapchecker.
+    'linux_use_heapchecker%': 1,
 
     # Disable shadow stack keeping used by heapcheck to unwind the stacks
     # better.
@@ -337,7 +337,7 @@
 
     # Used to disable Native Client at compile time, for platforms where it
     # isn't supported
-    'disable_nacl%': 0,
+    'disable_nacl%': 1,
 
     # Set Thumb compilation flags.
     'arm_thumb%': 0,
@@ -368,7 +368,7 @@
     # Set to 1 to compile with the built in pdf viewer.
     'internal_pdf%': 0,
 
-    # This allows to use libcros from the current system, ie. /usr/lib/
+    # This allows to use libcros from the current system, ie. /usr/local/lib/
     # The cros_api will be pulled in as a static library, and all headers
     # from the system include dirs.
     'system_libcros%': 0,
@@ -405,7 +405,7 @@
         # This is used to tweak build flags for gcc 4.4.
         'gcc_version%': '<!(python <(DEPTH)/build/compiler_version.py)',
         # Figure out the python architecture to decide if we build pyauto.
-        'python_arch%': '<!(<(DEPTH)/build/linux/python_arch.sh <(sysroot)/usr/lib/libpython<(python_ver).so.1.0)',
+        'python_arch%': '<!(<(DEPTH)/build/linux/python_arch.sh <(sysroot)/usr/local/lib/libpython<(python_ver).so.1)',
         'conditions': [
           ['branding=="Chrome"', {
             'linux_breakpad%': 1,
@@ -478,7 +478,7 @@
         ],
       }],
 
-      ['OS=="mac" or (OS=="linux" and chromeos==0 and target_arch!="arm")', {
+      ['OS=="mac" or OS=="freebsd" or (OS=="linux" and chromeos==0 and target_arch!="arm")', {
         'use_cups%': 1,
       }, {
         'use_cups%': 0,
@@ -779,7 +779,7 @@
               ['exclude', '(^|/)(gtk|x11)_[^/]*\\.(h|cc)$'],
             ],
           }],
-          ['OS!="linux"', {
+          ['OS!="linux" and OS!="freebsd"', {
             'sources/': [
               ['exclude', '_linux(_unittest)?\\.(h|cc)$'],
               ['exclude', '(^|/)linux/'],
