--- Source/JavaScriptCore/assembler/AbstractMacroAssembler.h.orig	2021-10-21 08:52:07 UTC
+++ Source/JavaScriptCore/assembler/AbstractMacroAssembler.h
@@ -971,7 +971,7 @@ class AbstractMacroAssembler : public AbstractMacroAss
     template<PtrTag tag>
     static void repatchCompact(CodeLocationDataLabelCompact<tag> dataLabelCompact, int32_t value)
     {
-        AssemblerType::repatchCompact(dataLabelCompact.template dataLocation(), value);
+        AssemblerType::repatchCompact(dataLabelCompact.template dataLocation<>(), value);
     }
 
     template<PtrTag tag>
