--- js/src/methodjit/MethodJIT.cpp~
+++ js/src/methodjit/MethodJIT.cpp
@@ -171,7 +171,7 @@
 
 JS_STATIC_ASSERT(offsetof(FrameRegs, sp) == 0);
 
-#if defined(__linux__) && defined(JS_CPU_X64)
+#if defined(__ELF__) && defined(JS_CPU_X64)
 # define SYMBOL_STRING_RELOC(name) #name "@plt"
 #else
 # define SYMBOL_STRING_RELOC(name) SYMBOL_STRING(name)
@@ -149,7 +149,7 @@
 
 #if defined(XP_MACOSX)
 # define HIDE_SYMBOL(name) ".private_extern _" #name
-#elif defined(__linux__)
+#elif defined(__ELF__)
 # define HIDE_SYMBOL(name) ".hidden" #name
 #else
 # define HIDE_SYMBOL(name)
