--- build/common.gypi.orig	2012-07-12 19:09:26.000000000 +0000
+++ build/common.gypi	2012-07-12 19:09:38.000000000 +0000
@@ -91,6 +91,34 @@
           '-Wl,-z,defs',
         ],
       }],
+      ['OS == "freebsd"', {
+        # Disable -Werror when not using the version of gcc that development
+        # is generally done with, to avoid breaking things for users with
+        # something older or newer (which produces different warnings).
+        'conditions': [
+          ['<(gcc_version) != <(gcc_devel_version)', {
+          'cflags!': ['-Werror']
+          }],
+        ],
+        'cflags': [
+          # Our dependency on OpenCV need us to turn on exceptions.
+          '-fexceptions',
+          # Now we are using exceptions. -fno-asynchronous-unwind-tables is
+          # set in libpagespeed's common.gypi. Now enable it.
+          '-fasynchronous-unwind-tables',
+          # We'd like to add '-Wtype-limits', but this does not work on
+          # earlier versions of g++ on supported operating systems.
+        ],
+        'cflags_cc': [
+          '-frtti',  # g++ 4.2 <trl/function> uses typeid
+        ],
+        # Disable -z,defs in linker.
+        # This causes mod_pagespeed.so to fail because it doesn't link apache
+        # libraries.
+        'ldflags!': [
+          '-Wl,-z,defs',
+        ],
+      }],
       ['OS == "mac"', {
         'xcode_settings':{
           'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',        # -fexceptions
