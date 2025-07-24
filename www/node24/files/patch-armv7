--- tools/v8_gypfiles/v8.gyp.orig	2025-07-17 21:44:08 UTC
+++ tools/v8_gypfiles/v8.gyp
@@ -1314,9 +1314,6 @@
         # to implement atomic memory access.
         # Clang needs it for some atomic operations (https://clang.llvm.org/docs/Toolchain.html#atomics-library).
         ['(OS=="linux" and clang==1) or (v8_current_cpu in ["mips64", "mips64el", "arm", "riscv64", "loong64"])', {
-          'link_settings': {
-            'libraries': ['-latomic', ],
-          },
         }],
       ],
     },  # v8_base_without_compiler
