Index: Source/WTF/wtf/InlineASM.h
--- Source/WTF/wtf/InlineASM.h.orig
+++ Source/WTF/wtf/InlineASM.h
@@ -43,7 +43,7 @@
 #define THUMB_FUNC_PARAM(name)
 #endif
 
-#if (OS(LINUX) || OS(FREEBSD)) && CPU(X86_64)
+#if (OS(LINUX) || OS(FREEBSD) || OS(OPENBSD)) && CPU(X86_64)
 #define GLOBAL_REFERENCE(name) #name "@plt"
 #elif CPU(X86) && COMPILER(MINGW)
 #define GLOBAL_REFERENCE(name) "@" #name "@4"
