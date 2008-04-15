--- src/windowscedevice.cpp.orig	2008-04-15 11:28:35.000000000 +0200
+++ src/windowscedevice.cpp	2008-04-15 11:37:11.000000000 +0200
@@ -29,6 +29,12 @@
 
 #include <devicemanager.h>
 
+#if defined(__FreeBSD__) && defined(__sparc64__)
+#include <sys/endian.h>
+#define bswap_16 bswap16
+#define bswap_32 bswap32
+#endif
+
 using namespace std;
 
 WindowsCEDevice::WindowsCEDevice(int fd, TCPServerSocket *tcpServerSocket)
