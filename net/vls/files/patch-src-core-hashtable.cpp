--- src/core/hashtable.cpp.orig	2007-07-31 20:20:07.000000000 +0200
+++ src/core/hashtable.cpp	2007-07-31 20:21:02.000000000 +0200
@@ -97,7 +97,7 @@
 
 u32 C_HashMethod<handle>::Hash(handle hKey) const
 {
-  return (u32)hKey % m_uiMaxHash;
+  return (uintptr_t)hKey % m_uiMaxHash;
 }
 
 
