--- modules/core/src/cpp/hash/hash.hxx.orig	2021-07-15 11:55:00 UTC
+++ modules/core/src/cpp/hash/hash.hxx
@@ -7,7 +7,7 @@
 #pragma once
 
 #ifndef _MSC_VER
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 #include <machine/endian.h>
 #else
 #include <endian.h>
