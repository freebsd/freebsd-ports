--- Source/WTF/wtf/CompletionHandler.h.orig	2023-02-01 10:02:29.556588000 -0800
+++ Source/WTF/wtf/CompletionHandler.h	2023-02-01 10:02:58.701631000 -0800
@@ -69,7 +69,6 @@
     {
         ASSERT(m_shouldBeCalledOnMainThread == isMainThread());
         ASSERT_WITH_MESSAGE(m_function, "Completion handler should not be called more than once");
-        return std::exchange(m_function, nullptr)(std::forward<In>(in)...);
     }
 
 private:
