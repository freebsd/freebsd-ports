--- io.h.orig
+++ io.h
@@ -2,7 +2,7 @@
 #define FISH_IO_H
 
 #include <vector>
-#if __cplusplus > 199711L
+#if __cplusplus > 199711L || defined(_LIBCPP_VERSION)
 // C++11
 #include <memory>
 using std::shared_ptr;
