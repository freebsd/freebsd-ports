XXX error: macro "swap32" passed 2 arguments, but takes just 1
XXX error: macro "swap64" passed 2 arguments, but takes just 1

Index: Source/JavaScriptCore/assembler/MacroAssemblerX86Common.h
--- Source/JavaScriptCore/assembler/MacroAssemblerX86Common.h.orig
+++ Source/JavaScriptCore/assembler/MacroAssemblerX86Common.h
@@ -31,6 +31,12 @@
 #include "AbstractMacroAssembler.h"
 #include <array>
 
+/* conflicting definition in endian.h */
+#if OS(OPENBSD)
+#undef swap32
+#undef swap64
+#endif
+
 namespace JSC {
 
 using Assembler = TARGET_ASSEMBLER;
