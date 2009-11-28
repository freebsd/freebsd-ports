--- JavaScriptCore/assembler/MacroAssemblerCodeRef.h.orig	2009-10-19 08:34:08.000000000 -0400
+++ JavaScriptCore/assembler/MacroAssemblerCodeRef.h	2009-10-19 08:34:53.000000000 -0400
@@ -69,7 +69,7 @@ public:
 
     template<typename FunctionType>
     explicit FunctionPtr(FunctionType* value)
-        : m_value(reinterpret_cast<void*>(value))
+        : m_value((void*)(value))
     {
         ASSERT_VALID_CODE_POINTER(m_value);
     }
