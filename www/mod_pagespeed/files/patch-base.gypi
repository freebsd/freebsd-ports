--- base/base.gypi.orig	2012-07-11 20:16:43.000000000 -0400
+++ base/base.gypi	2012-07-11 21:12:00.214510822 -0400
@@ -7,6 +7,7 @@
     'variables': {
       'base_target': 0,
       'chromium_root': '<(DEPTH)/third_party/chromium/src',
+      'system_include_path_execinfo%': '%%LOCALBASE%%/include',
       'conditions': [
         # The default stack_trace_posix.cc is not compatible with NaCL newlib
         # toolchain, so we provide a stubbed version when building for NaCL.
@@ -117,6 +118,7 @@
         'include_dirs': [
           '<(chromium_root)',
           '<(DEPTH)',
+          '<(system_include_path_execinfo)',
         ],
         # These warnings are needed for the files in third_party\dmg_fp.
         'msvs_disabled_warnings': [
