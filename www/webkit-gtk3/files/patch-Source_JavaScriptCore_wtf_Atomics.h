--- Source/JavaScriptCore/wtf/Atomics.h.orig	2013-09-06 13:54:07.000000000 +0200
+++ Source/JavaScriptCore/wtf/Atomics.h	2013-09-06 13:55:58.000000000 +0200
@@ -65,18 +65,10 @@
 
 #if OS(WINDOWS)
 #include <windows.h>
-#elif OS(DARWIN)
-#include <libkern/OSAtomic.h>
 #elif OS(QNX)
 #include <atomic.h>
 #elif OS(ANDROID)
 #include <sys/atomics.h>
-#elif COMPILER(GCC)
-#if (__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 2))
-#include <ext/atomicity.h>
-#else
-#include <bits/atomicity.h>
-#endif
 #endif
 
 namespace WTF {
@@ -92,12 +84,6 @@ inline int atomicIncrement(int volatile*
 inline int atomicDecrement(int volatile* addend) { return InterlockedDecrement(reinterpret_cast<long volatile*>(addend)); }
 #endif
 
-#elif OS(DARWIN)
-#define WTF_USE_LOCKFREE_THREADSAFEREFCOUNTED 1
-
-inline int atomicIncrement(int volatile* addend) { return OSAtomicIncrement32Barrier(const_cast<int*>(addend)); }
-inline int atomicDecrement(int volatile* addend) { return OSAtomicDecrement32Barrier(const_cast<int*>(addend)); }
-
 #elif OS(QNX)
 #define WTF_USE_LOCKFREE_THREADSAFEREFCOUNTED 1
 
@@ -113,8 +99,8 @@ inline int atomicDecrement(int volatile*
 #elif COMPILER(GCC) && !CPU(SPARC64) // sizeof(_Atomic_word) != sizeof(int) on sparc64 gcc
 #define WTF_USE_LOCKFREE_THREADSAFEREFCOUNTED 1
 
-inline int atomicIncrement(int volatile* addend) { return __gnu_cxx::__exchange_and_add(addend, 1) + 1; }
-inline int atomicDecrement(int volatile* addend) { return __gnu_cxx::__exchange_and_add(addend, -1) - 1; }
+inline int atomicIncrement(int volatile* addend) { return __sync_add_and_fetch(addend, 1); }
+inline int atomicDecrement(int volatile* addend) { return __sync_sub_and_fetch(addend, 1); }
 
 #endif
 
