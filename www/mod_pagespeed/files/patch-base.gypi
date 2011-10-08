--- base/base.gypi.orig	2011-09-29 19:59:56.000000000 +0000
+++ base/base.gypi	2011-09-29 20:00:44.000000000 +0000
@@ -8,6 +8,7 @@
       'base_target': 0,
       'base_extra_target': 0,
       'chromium_root': '<(DEPTH)/third_party/chromium/src',
+      'system_include_path_execinfo%': '/usr/local/include',
     },
     'target_conditions': [
       # This part is shared between the targets defined below. Only files and
@@ -110,6 +111,7 @@
         'include_dirs': [
           '<(chromium_root)',
           '<(DEPTH)',
+          '<(system_include_path_execinfo)',
         ],
         # These warnings are needed for the files in third_party\dmg_fp.
         'msvs_disabled_warnings': [
