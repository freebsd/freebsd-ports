--- libs/yradio/radio.cpp.orig	2018-03-28 12:02:24 UTC
+++ libs/yradio/radio.cpp
@@ -23,6 +23,7 @@
 #include <yateradio.h>
 #include <string.h>
 
+/*
 #ifndef htobe32
 #include <byteswap.h>
 
@@ -59,6 +60,8 @@
 #endif
 
 #endif // htobe32
+*/
+#include <sys/endian.h>
 
 
 //#define DEBUG_RADIO_READ
