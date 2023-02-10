--- Source/WTF/wtf/Function.h.orig	2023-02-01 10:03:43.795431000 -0800
+++ Source/WTF/wtf/Function.h	2023-02-01 10:37:20.896904000 -0800
@@ -50,7 +50,7 @@
         : m_callable(WTFMove(callable)) { }
     CallableWrapper(const CallableWrapper&) = delete;
     CallableWrapper& operator=(const CallableWrapper&) = delete;
-    Out call(In... in) final { return m_callable(std::forward<In>(in)...); }
+    Out call(In... in) final { }
 private:
     CallableType m_callable;
 };
@@ -79,7 +79,6 @@
     Out operator()(In... in) const
     {
         ASSERT(m_callableWrapper);
-        return m_callableWrapper->call(std::forward<In>(in)...);
     }
 
     explicit operator bool() const { return !!m_callableWrapper; }
