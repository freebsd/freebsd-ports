--- stage0/src/runtime/thread.h.orig	2026-06-16 21:55:32 UTC
+++ stage0/src/runtime/thread.h
@@ -179,13 +179,20 @@ template<typename T> class unique_lock {
     ~lock_guard() {}
 };
 template<typename T> class unique_lock {
+private:
+    bool m_owns_lock;
 public:
-    unique_lock(T const &) {}
-    unique_lock(T const &, std::adopt_lock_t) {}
-    ~unique_lock() {}
+    unique_lock(T const &) : m_owns_lock(true) {}
+    unique_lock(T const &, std::adopt_lock_t) : m_owns_lock(true) {}
+    ~unique_lock() {
+        if (m_owns_lock) unlock();
+    }
     void lock() {}
     void unlock() {}
-    T * release() { return nullptr; }
+    T * release() {
+        m_owns_lock = false;
+        return nullptr;
+    }
 };
 inline unsigned hardware_concurrency() { return 1; }
 }
