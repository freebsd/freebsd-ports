--- Source/JavaScriptCore/llint/LLIntData.h.orig	2021-10-21 08:52:07 UTC
+++ Source/JavaScriptCore/llint/LLIntData.h
@@ -217,7 +217,7 @@ ALWAYS_INLINE LLIntCode getCodeFunctionPtr(OpcodeID op
 #if COMPILER(MSVC)
     return reinterpret_cast<LLIntCode>(getCodePtr<tag>(opcodeID).executableAddress());
 #else
-    return reinterpret_cast<LLIntCode>(getCodePtr<tag>(opcodeID).template executableAddress());
+    return reinterpret_cast<LLIntCode>(getCodePtr<tag>(opcodeID).template executableAddress<>());
 #endif
 }
 
@@ -227,7 +227,7 @@ ALWAYS_INLINE LLIntCode getWide16CodeFunctionPtr(Opcod
 #if COMPILER(MSVC)
     return reinterpret_cast<LLIntCode>(getWide16CodePtr<tag>(opcodeID).executableAddress());
 #else
-    return reinterpret_cast<LLIntCode>(getWide16CodePtr<tag>(opcodeID).template executableAddress());
+    return reinterpret_cast<LLIntCode>(getWide16CodePtr<tag>(opcodeID).template executableAddress<>());
 #endif
 }
 
@@ -237,7 +237,7 @@ ALWAYS_INLINE LLIntCode getWide32CodeFunctionPtr(Opcod
 #if COMPILER(MSVC)
     return reinterpret_cast<LLIntCode>(getWide32CodePtr<tag>(opcodeID).executableAddress());
 #else
-    return reinterpret_cast<LLIntCode>(getWide32CodePtr<tag>(opcodeID).template executableAddress());
+    return reinterpret_cast<LLIntCode>(getWide32CodePtr<tag>(opcodeID).template executableAddress<>());
 #endif
 }
 
@@ -328,7 +328,7 @@ ALWAYS_INLINE LLIntCode getCodeFunctionPtr(WasmOpcodeI
 #if COMPILER(MSVC)
     return reinterpret_cast<LLIntCode>(getCodePtr<tag>(opcodeID).executableAddress());
 #else
-    return reinterpret_cast<LLIntCode>(getCodePtr<tag>(opcodeID).template executableAddress());
+    return reinterpret_cast<LLIntCode>(getCodePtr<tag>(opcodeID).template executableAddress<>());
 #endif
 }
 
@@ -338,7 +338,7 @@ ALWAYS_INLINE LLIntCode getWide16CodeFunctionPtr(WasmO
 #if COMPILER(MSVC)
     return reinterpret_cast<LLIntCode>(getWide16CodePtr<tag>(opcodeID).executableAddress());
 #else
-    return reinterpret_cast<LLIntCode>(getWide16CodePtr<tag>(opcodeID).template executableAddress());
+    return reinterpret_cast<LLIntCode>(getWide16CodePtr<tag>(opcodeID).template executableAddress<>());
 #endif
 }
 
@@ -348,7 +348,7 @@ ALWAYS_INLINE LLIntCode getWide32CodeFunctionPtr(WasmO
 #if COMPILER(MSVC)
     return reinterpret_cast<LLIntCode>(getWide32CodePtr<tag>(opcodeID).executableAddress());
 #else
-    return reinterpret_cast<LLIntCode>(getWide32CodePtr<tag>(opcodeID).template executableAddress());
+    return reinterpret_cast<LLIntCode>(getWide32CodePtr<tag>(opcodeID).template executableAddress<>());
 #endif
 }
 
