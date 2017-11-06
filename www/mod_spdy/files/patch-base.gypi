FIXME: this feels a bit silly now.

--- base/base.gypi.org	2012-03-31 16:28:56.347804000 +0900
+++ base/base.gypi	2012-03-31 17:03:22.470770534 +0900
@@ -7,6 +7,7 @@
     'variables': {
       'base_target': 0,
       'chromium_root': '<(DEPTH)/third_party/chromium/src',
+      'system_include_path_execinfo%': '/usr/include',
     },
     'target_conditions': [
       # This part is shared between the targets defined below. Only files and
@@ -107,6 +108,7 @@
         'include_dirs': [
           '<(chromium_root)',
           '<(DEPTH)',
+          '<(system_include_path_execinfo)',
         ],
         # These warnings are needed for the files in third_party\dmg_fp.
         'msvs_disabled_warnings': [
