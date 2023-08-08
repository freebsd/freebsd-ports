Index: Source/WTF/wtf/RawHex.h
--- Source/WTF/wtf/RawHex.h.orig
+++ Source/WTF/wtf/RawHex.h
@@ -48,7 +48,7 @@ class RawHex { (public)
         : RawHex(static_cast<uintptr_t>(value))
     { }
 
-#if CPU(ADDRESS64) || OS(DARWIN)
+#if CPU(ADDRESS64) || OS(DARWIN) || OS(OPENBSD)
     // These causes build errors for CPU(ADDRESS32) on some ports because int32_t
     // is already handled by intptr_t, and uint32_t is handled by uintptr_t.
     explicit RawHex(int32_t value)
@@ -59,7 +59,7 @@ class RawHex { (public)
     { }
 #endif
 
-#if CPU(ADDRESS32) || OS(DARWIN)
+#if CPU(ADDRESS32) || OS(DARWIN) || OS(OPENBSD)
     // These causes build errors for CPU(ADDRESS64) on some ports because int64_t
     // is already handled by intptr_t, and uint64_t is handled by uintptr_t.
     explicit RawHex(int64_t value)
