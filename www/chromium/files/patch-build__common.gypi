--- ./build/common.gypi.orig	2010-12-20 20:09:09.000000000 +0100
+++ ./build/common.gypi	2010-12-20 20:15:08.000000000 +0100
@@ -230,7 +230,7 @@
 
     # Whether proprietary audio/video codecs are assumed to be included with
     # this build (only meaningful if branding!=Chrome).
-    'proprietary_codecs%': 0,
+    'proprietary_codecs%': 1,
 
     # TODO(bradnelson): eliminate this when possible.
     # To allow local gyp files to prevent release.vsprops from being included.
@@ -279,8 +279,8 @@
     # Disable TCMalloc's debugallocation.
     'linux_use_debugallocation%': 0,
 
-    # Disable TCMalloc's heapchecker.
-    'linux_use_heapchecker%': 0,
+    # Enable TCMalloc's heapchecker.
+    'linux_use_heapchecker%': 1,
 
     # Disable shadow stack keeping used by heapcheck to unwind the stacks
     # better.
@@ -298,7 +298,7 @@
 
     # Used to disable Native Client at compile time, for platforms where it
     # isn't supported
-    'disable_nacl%': 0,
+    'disable_nacl%': 1,
 
     # Set Thumb compilation flags.
     'arm_thumb%': 0,
@@ -638,7 +638,7 @@
               ['exclude', '(^|/)(gtk|x11)_[^/]*\\.(h|cc)$'],
             ],
           }],
-          ['OS!="linux"', {
+          ['OS!="linux" and OS!="freebsd"', {
             'sources/': [
               ['exclude', '_linux(_unittest)?\\.(h|cc)$'],
               ['exclude', '(^|/)linux/'],
