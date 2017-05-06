--- src/libcec/adapter/Pulse-Eight/USBCECAdapterDetection.cpp.orig	2017-01-28 22:51:30 UTC
+++ src/libcec/adapter/Pulse-Eight/USBCECAdapterDetection.cpp
@@ -56,6 +56,9 @@ static GUID USB_RAW_GUID = { 0xA5DCBF10,
 static GUID USB_CDC_GUID = { 0x4D36E978, 0xE325, 0x11CE, { 0xBF, 0xC1, 0x08, 0x00, 0x2B, 0xE1, 0x03, 0x18 } };
 
 #elif defined(HAVE_LIBUDEV)
+#if defined(__FreeBSD__)
+#include <sys/sysctl.h>
+#endif
 #include <dirent.h>
 #include <poll.h>
 extern "C" {
