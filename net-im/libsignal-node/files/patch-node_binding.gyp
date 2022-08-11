--- node/binding.gyp.orig	2022-02-25 14:33:26 UTC
+++ node/binding.gyp
@@ -6,6 +6,7 @@
 {
     'conditions': [
         ['OS=="mac"', {'variables': {'NODE_OS_NAME': 'darwin', 'CARGO_TARGET_SUFFIX': 'apple-darwin'}},
+         'OS=="freebsd"', {'variables': {'NODE_OS_NAME': 'freebsd', 'CARGO_TARGET_SUFFIX': 'unknown-freebsd'}},
          'OS=="win"', {'variables': {'NODE_OS_NAME': 'win32', 'CARGO_TARGET_SUFFIX': 'pc-windows-msvc'}},
          'OS=="linux"', {'variables': {'NODE_OS_NAME': 'linux', 'CARGO_TARGET_SUFFIX': 'unknown-linux-gnu'}},
          {'variables': {'NODE_OS_NAME': '<(OS)'}}],
