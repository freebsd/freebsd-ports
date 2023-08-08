--- io_uring_engine.h.orig	2023-05-04 07:33:59 UTC
+++ io_uring_engine.h
@@ -7,7 +7,6 @@
 #include <string_view>
 #include <sys/socket.h>
 #include <sys/types.h>
-#include <linux/stat.h>
 
 struct io_uring_sqe;
 #ifndef WITHOUT_URING
