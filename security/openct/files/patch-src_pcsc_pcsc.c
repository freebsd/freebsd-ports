--- src/pcsc/pcsc.c.orig	2007-05-25 21:11:45 UTC
+++ src/pcsc/pcsc.c
@@ -25,6 +25,7 @@
 #ifdef DEBUG_IFDH
 #include <syslog.h>
 #endif
+#include <limits.h>
 #ifdef __APPLE__
 #include <PCSC/wintypes.h>
 #include <PCSC/pcsclite.h>
@@ -390,6 +391,10 @@ IFDHTransmitToICC(DWORD Lun, SCARD_IO_HE
 	ctn = ((unsigned short)(Lun >> 16)) % IFDH_MAX_READERS;
 	slot = ((unsigned short)(Lun & 0x0000FFFF)) % IFDH_MAX_SLOTS;
 
+	if (TxLength > USHRT_MAX) {
+		(*RxLength) = 0;
+		return IFD_PROTOCOL_NOT_SUPPORTED;
+	}
 #ifdef HAVE_PTHREAD
 	pthread_mutex_lock(&ifdh_context_mutex[ctn]);
 #endif
@@ -399,7 +404,7 @@ IFDHTransmitToICC(DWORD Lun, SCARD_IO_HE
 #endif
 		dad = (UCHAR) ((slot == 0) ? 0x00 : slot + 1);
 		sad = 0x02;
-		lr = (unsigned short)(*RxLength);
+		lr = (*RxLength > USHRT_MAX) ? USHRT_MAX : (unsigned short)(*RxLength);
 		lc = (unsigned short)TxLength;
 
 		ret = CT_data(ctn, &dad, &sad, lc, TxBuffer, &lr, RxBuffer);
@@ -438,6 +443,10 @@ IFDHControl(DWORD Lun, PUCHAR TxBuffer,
 	ctn = ((unsigned short)(Lun >> 16)) % IFDH_MAX_READERS;
 	slot = ((unsigned short)(Lun & 0x0000FFFF)) % IFDH_MAX_SLOTS;
 
+	if (TxLength > USHRT_MAX) {
+		(*RxLength) = 0;
+		return IFD_PROTOCOL_NOT_SUPPORTED;
+	}
 #ifdef HAVE_PTHREAD
 	pthread_mutex_lock(&ifdh_context_mutex[ctn]);
 #endif
@@ -447,7 +456,7 @@ IFDHControl(DWORD Lun, PUCHAR TxBuffer,
 #endif
 		dad = 0x01;
 		sad = 0x02;
-		lr = (unsigned short)(*RxLength);
+		lr = (*RxLength > USHRT_MAX) ? USHRT_MAX : (unsigned short)(*RxLength);
 		lc = (unsigned short)TxLength;
 
 		ret = CT_data(ctn, &dad, &sad, lc, TxBuffer, &lr, RxBuffer);
