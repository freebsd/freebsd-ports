--- JavaScriptCore/assembler/MacroAssemblerCodeRef.h.orig	2010-01-14 15:19:17.000000000 +0000
+++ JavaScriptCore/assembler/MacroAssemblerCodeRef.h	2010-01-14 15:21:00.000000000 +0000
@@ -74,7 +74,7 @@ public:
      // Error:  #694: reinterpret_cast cannot cast away const or other type qualifiers
         : m_value((void*)(value))
 #else
-        : m_value(reinterpret_cast<void*>(value))
+        : m_value((void*)(value))
 #endif
     {
         ASSERT_VALID_CODE_POINTER(m_value);
