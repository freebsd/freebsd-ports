--- cmake/libraries.cmake.orig	2023-02-07 10:27:13.362305000 +0100
+++ cmake/libraries.cmake	2023-02-07 10:29:06.625482000 +0100
@@ -9,7 +9,7 @@
 set(FLB_PATH_LIB_MSGPACK     "lib/msgpack-c")
 set(FLB_PATH_LIB_AVRO        "lib/avro")
 set(FLB_PATH_LIB_CHUNKIO     "lib/chunkio")
-set(FLB_PATH_LIB_LUAJIT      "lib/luajit-3065c9")
+# install from ports: set(FLB_PATH_LIB_LUAJIT      "lib/luajit-3065c9")
 set(FLB_PATH_LIB_MONKEY      "lib/monkey")
 set(FLB_PATH_LIB_JSMN        "lib/jsmn")
 set(FLB_PATH_LIB_MBEDTLS     "lib/mbedtls-2.28.0")
