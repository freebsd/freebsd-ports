From e3c44790065894f4e7f98ab097fce22c5bcbbd0a Mon Sep 17 00:00:00 2001
From: Raphael Kubo da Costa <rakuco@FreeBSD.org>
Date: Tue, 2 Jul 2013 13:48:28 +0300
Subject: [PATCH] Bring in WebKit revisions 139553 and 139921.

They are primarily useful for getting rid of some libstdc++-specific
includes which break the build with libc++, and also for simplifying the
code and removing a Darwin-specific code path.

r139553 by ossy@webkit.org:
  Use sync_add_and_fetch instead of gnu_cxx::exchange_and_add
  https://bugs.webkit.org/show_bug.cgi?id=106729

  After r139514 we need atomicIncrement(int64_t volatile*) for all
  platform. Now the GCC implementation of atomicIncrement() is based on
  gnu_cxx::exchange_and_add, which doesn't support int64_t type, but
  sync_add_and_fetch does.

  Reviewed by Benjamin Poulain.

r139921 by benjamin@webkit.org:
  Use GCC's implementation of atomicIncrement/Decrement on Mac
  https://bugs.webkit.org/show_bug.cgi?id=106976

  Reviewed by Filip Pizlo.

  wtf/Atomics.h: GCC and LLVM have builtin for atomic ADD and SUB:
                 sync_add_and_fetch, sync_sub_and_fetch.

  Using them let the compiler just generate the atomic operations inline
  instead of generating a function call to LibC. It also simplify the
  code a bit.

Cherry-picked from qtwebkit/0baf197 and qtwebkit/801fc96. I'm cherry-picking
both revisions together to match what was done in 0de22e80.

Change-Id: Ie5c1067980662ff04e8e36d8cf6e9459b7c46aab
Reviewed-by: Allan Sandfeld Jensen <allan.jensen@digia.com>
---
 .../webkit/Source/JavaScriptCore/wtf/Atomics.h         | 18 ++----------------
 1 file changed, 2 insertions(+), 16 deletions(-)

diff --git a/src/3rdparty/webkit/Source/JavaScriptCore/wtf/Atomics.h b/src/3rdparty/webkit/Source/JavaScriptCore/wtf/Atomics.h
index bce5fba..acf0e5a 100644
--- src/3rdparty/webkit/Source/JavaScriptCore/wtf/Atomics.h
+++ src/3rdparty/webkit/Source/JavaScriptCore/wtf/Atomics.h
@@ -63,18 +63,10 @@
 
 #if OS(WINDOWS)
 #include <windows.h>
-#elif OS(DARWIN)
-#include <libkern/OSAtomic.h>
 #elif OS(ANDROID)
 #include <cutils/atomic.h>
 #elif OS(QNX)
 #include <atomic.h>
-#elif COMPILER(GCC) && !OS(SYMBIAN)
-#if (__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 2))
-#include <ext/atomicity.h>
-#else
-#include <bits/atomicity.h>
-#endif
 #endif
 
 namespace WTF {
@@ -90,12 +82,6 @@ inline int atomicIncrement(int volatile* addend) { return InterlockedIncrement(r
 inline int atomicDecrement(int volatile* addend) { return InterlockedDecrement(reinterpret_cast<long volatile*>(addend)); }
 #endif
 
-#elif OS(DARWIN)
-#define WTF_USE_LOCKFREE_THREADSAFEREFCOUNTED 1
-
-inline int atomicIncrement(int volatile* addend) { return OSAtomicIncrement32Barrier(const_cast<int*>(addend)); }
-inline int atomicDecrement(int volatile* addend) { return OSAtomicDecrement32Barrier(const_cast<int*>(addend)); }
-
 #elif OS(ANDROID)
 
 inline int atomicIncrement(int volatile* addend) { return android_atomic_inc(addend); }
@@ -109,8 +95,8 @@ inline int atomicDecrement(int volatile* addend) { return (int) atomic_sub_value
 #elif COMPILER(GCC) && !CPU(SPARC64) && !OS(SYMBIAN) // sizeof(_Atomic_word) != sizeof(int) on sparc64 gcc
 #define WTF_USE_LOCKFREE_THREADSAFEREFCOUNTED 1
 
-inline int atomicIncrement(int volatile* addend) { return __gnu_cxx::__exchange_and_add(addend, 1) + 1; }
-inline int atomicDecrement(int volatile* addend) { return __gnu_cxx::__exchange_and_add(addend, -1) - 1; }
+inline int atomicIncrement(int volatile* addend) { return __sync_add_and_fetch(addend, 1); }
+inline int atomicDecrement(int volatile* addend) { return __sync_sub_and_fetch(addend, 1); }
 
 #endif
 
-- 
1.8.4

