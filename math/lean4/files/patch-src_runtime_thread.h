--- src/runtime/thread.h.orig	2026-01-20 14:00:20 UTC
+++ src/runtime/thread.h
@@ -179,11 +179,20 @@ template<typename T> class unique_lock {
     ~lock_guard() {}
 };
 template<typename T> class unique_lock {
+private:
+    bool m_owns_lock;
 public:
-    unique_lock(T const &) {}
-    ~unique_lock() {}
+    unique_lock(T const &) : m_owns_lock(true) {}
+    template<typename Mutex>
+    unique_lock(Mutex const &, std::adopt_lock_t) : m_owns_lock(true) {}
+    ~unique_lock() {
+        if (m_owns_lock) unlock();
+    }
     void lock() {}
     void unlock() {}
+    void release() {
+        m_owns_lock = false;
+    }
 };
 inline unsigned hardware_concurrency() { return 1; }
 }
