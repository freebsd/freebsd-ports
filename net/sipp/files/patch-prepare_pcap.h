$FreeBSD$

--- prepare_pcap.h.orig
+++ prepare_pcap.h
@@ -22,7 +22,7 @@
 #include <netinet/udp.h>
 #include <time.h>
 
-#if defined(__HPUX) || defined(__DARWIN) || defined(__CYGWIN)
+#if defined(__HPUX) || defined(__DARWIN) || defined(__CYGWIN) || defined(__FreeBSD__)
 #define u_int8_t uint8_t
 #define u_int16_t uint16_t
 #define u_int32_t uint32_t
