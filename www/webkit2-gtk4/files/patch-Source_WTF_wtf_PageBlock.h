Index: Source/WTF/wtf/PageBlock.h
--- Source/WTF/wtf/PageBlock.h.orig
+++ Source/WTF/wtf/PageBlock.h
@@ -55,6 +55,8 @@ constexpr size_t CeilingOnPageSize = 16 * KB;
 constexpr size_t CeilingOnPageSize = 64 * KB;
 #elif OS(WINDOWS) || CPU(X86) || CPU(X86_64) || CPU(ARM) || CPU(ARM64) || CPU(RISCV64)
 constexpr size_t CeilingOnPageSize = 4 * KB;
+#elif CPU(SPARC64)
+constexpr size_t CeilingOnPageSize = 8 * KB;
 #else
 #error Must set CeilingOnPageSize in PageBlock.h when adding a new CPU architecture!
 #endif
