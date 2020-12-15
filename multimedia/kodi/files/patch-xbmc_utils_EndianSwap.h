--- xbmc/utils/EndianSwap.h.orig	2020-12-15 17:05:18 UTC
+++ xbmc/utils/EndianSwap.h
@@ -23,7 +23,7 @@
 extern "C" {
 #endif
 
-#if defined(__GNUC__) && (defined(__powerpc__) || defined(__ppc__))
+#if defined(__GNUC__) && (defined(__powerpc__) || defined(__ppc__)) && !defined(__clang__)
 static __inline__ uint16_t Endian_Swap16(uint16_t x)
 {
         uint16_t result;
