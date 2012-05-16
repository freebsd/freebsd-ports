--- dcpp/Atomic.h.orig	2012-01-27 21:20:06.000000000 +0300
+++ dcpp/Atomic.h	2012-01-27 21:21:11.000000000 +0300
@@ -57,18 +57,18 @@
 
         // type cast
         operator value_type() const {
-                return boost::interprocess::detail::atomic_read32(&m_value);
+                return boost::interprocess::ipcdetail::atomic_read32(&m_value);
         }
 
         // increment
-        void inc() { boost::interprocess::detail::atomic_inc32(&m_value); }
+        void inc() { boost::interprocess::ipcdetail::atomic_inc32(&m_value); }
 
         // decrement
-        void dec() { boost::interprocess::detail::atomic_dec32(&m_value); }
+        void dec() { boost::interprocess::ipcdetail::atomic_dec32(&m_value); }
 
 private:
         mutable value_type m_value;
-        void assign(value_type val) { boost::interprocess::detail::atomic_write32(&m_value, val); }
+        void assign(value_type val) { boost::interprocess::ipcdetail::atomic_write32(&m_value, val); }
 };
 
 // int32_t
