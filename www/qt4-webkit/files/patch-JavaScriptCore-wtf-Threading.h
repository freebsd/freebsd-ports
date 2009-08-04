--- ../JavaScriptCore/wtf/Threading.h.orig      2009-05-07 07:06:48.000000000 +0000
+++ ../JavaScriptCore/wtf/Threading.h   2009-05-07 08:00:22.000000000 +0000
@@ -196,8 +196,8 @@
 #elif COMPILER(GCC)
 #define WTF_USE_LOCKFREE_THREADSAFESHARED 1
 
-inline void atomicIncrement(int volatile* addend) { __gnu_cxx::__atomic_add(addend, 1); }
-inline int atomicDecrement(int volatile* addend) { return __gnu_cxx::__exchange_and_add(addend, -1) - 1; }
+inline void atomicIncrement(_Atomic_word volatile* addend) { __gnu_cxx::__atomic_add(addend, 1); }
+inline int atomicDecrement(_Atomic_word volatile* addend) { return __gnu_cxx::__exchange_and_add(addend, -1) - 1; }
 
 #endif
 
@@ -211,7 +211,7 @@
     void ref()
     {
 #if USE(LOCKFREE_THREADSAFESHARED)
-        atomicIncrement(&m_refCount);
+        atomicIncrement((_Atomic_word *)&m_refCount);
 #else
         MutexLocker locker(m_mutex);
         ++m_refCount;
@@ -221,7 +221,7 @@
     void deref()
     {
 #if USE(LOCKFREE_THREADSAFESHARED)
-        if (atomicDecrement(&m_refCount) <= 0)
+        if (atomicDecrement((_Atomic_word *)&m_refCount) <= 0)
 #else
         {
             MutexLocker locker(m_mutex);