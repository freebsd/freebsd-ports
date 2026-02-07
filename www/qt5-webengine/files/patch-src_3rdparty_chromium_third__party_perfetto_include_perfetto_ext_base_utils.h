--- src/3rdparty/chromium/third_party/perfetto/include/perfetto/ext/base/utils.h.orig	2019-11-27 21:12:25 UTC
+++ src/3rdparty/chromium/third_party/perfetto/include/perfetto/ext/base/utils.h
@@ -23,6 +23,7 @@
 #include <errno.h>
 #include <stddef.h>
 #include <stdlib.h>
+#include <type_traits>
 #if !PERFETTO_BUILDFLAG(PERFETTO_OS_WIN)
 #include <sys/types.h>
 #endif
@@ -72,7 +73,7 @@ struct FreeDeleter {
 
 template <typename T>
 constexpr T AssumeLittleEndian(T value) {
-  static_assert(__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__,
+  static_assert(std::is_same<T,T>::value && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__,
                 "Unimplemented on big-endian archs");
   return value;
 }
