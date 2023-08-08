Undo parts of upstream commit 6c2615dd66a12e9a10d7867241cc3bedfb2b2473 [0]
Machine context definitions were only added for Linux.
[0] https://github.com/WebKit/WebKit/commit/6c2615dd66a12e9a10d7867241cc3bedfb2b2473

Index: Source/WTF/wtf/PlatformHave.h
--- Source/WTF/wtf/PlatformHave.h.orig
+++ Source/WTF/wtf/PlatformHave.h
@@ -233,6 +233,10 @@
 #define HAVE_MACHINE_CONTEXT 1
 #endif
 
+#if OS(OPENBSD) && CPU(RISCV64)
+#undef HAVE_MACHINE_CONTEXT
+#endif
+
 #if OS(DARWIN) || (OS(LINUX) && defined(__GLIBC__) && !defined(__UCLIBC__) && !CPU(MIPS))
 #define HAVE_BACKTRACE 1
 #endif
