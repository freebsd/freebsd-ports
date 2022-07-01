--- node/binding.gyp.orig	2022-05-13 21:30:30 UTC
+++ node/binding.gyp
@@ -6,11 +6,12 @@
 {
     'conditions': [
         ['OS=="mac"', {'variables': {'NODE_OS_NAME': 'darwin', 'CARGO_TARGET_SUFFIX': 'apple-darwin'}},
          'OS=="win"', {'variables': {'NODE_OS_NAME': 'win32', 'CARGO_TARGET_SUFFIX': 'pc-windows-msvc'}},
          'OS=="linux"', {'variables': {'NODE_OS_NAME': 'linux', 'CARGO_TARGET_SUFFIX': 'unknown-linux-gnu'}},
          {'variables': {'NODE_OS_NAME': '<(OS)'}}],
         ['target_arch=="ia32"', {'variables': {'CARGO_ARCH': 'i686'}},
          'target_arch=="x64"', {'variables': {'CARGO_ARCH': 'x86_64'}},
+         'target_arch=="ppc64"', {'variables': {'CARGO_ARCH': 'powerpc64'}},
          'target_arch=="arm64"', {'variables': {'CARGO_ARCH': 'aarch64'}}]
     ],
     'targets': [
