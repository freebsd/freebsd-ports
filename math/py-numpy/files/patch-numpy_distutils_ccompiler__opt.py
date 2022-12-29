--- numpy/distutils/ccompiler_opt.py.orig	2022-11-19 22:40:58 UTC
+++ numpy/distutils/ccompiler_opt.py
@@ -959,8 +959,12 @@ class _CCompiler:
         detect_arch = (
             ("cc_on_x64",      ".*(x|x86_|amd)64.*", ""),
             ("cc_on_x86",      ".*(win32|x86|i386|i686).*", ""),
-            ("cc_on_ppc64le",  ".*(powerpc|ppc)64(el|le).*", ""),
-            ("cc_on_ppc64",    ".*(powerpc|ppc)64.*", ""),
+            ("cc_on_ppc64le",  ".*(powerpc|ppc)64(el|le).*|.*powerpc.*", ""
+                                          "defined(__LP64__) && "
+                                          "defined(__LITTLE_ENDIAN__)"),
+            ("cc_on_ppc64",    ".*(powerpc|ppc).*|.*powerpc.*", ""
+                                          "defined(__LP64__) && "
+                                          "defined(__BIG_ENDIAN__)"),
             ("cc_on_aarch64",  ".*(aarch64|arm64).*", ""),
             ("cc_on_armhf",    ".*arm.*", "defined(__ARM_ARCH_7__) || "
                                           "defined(__ARM_ARCH_7A__)"),
