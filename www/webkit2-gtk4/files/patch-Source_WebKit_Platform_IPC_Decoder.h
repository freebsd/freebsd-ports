--- Source/WebKit/Platform/IPC/Decoder.h.orig	2023-02-01 09:22:02.401739000 -0800
+++ Source/WebKit/Platform/IPC/Decoder.h	2023-02-01 09:22:22.880444000 -0800
@@ -112,7 +112,6 @@
     template<typename T>
     Decoder& operator>>(std::optional<T>& t)
     {
-        t = decode<T>();
         return *this;
     }
 
