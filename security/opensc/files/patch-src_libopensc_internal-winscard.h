--- src/libopensc/internal-winscard.h.orig	2010-09-01 11:37:56.000000000 +0200
+++ src/libopensc/internal-winscard.h	2010-09-01 11:38:31.000000000 +0200
@@ -113,7 +113,7 @@
 typedef LONG (PCSC_API *SCardStatus_t)(SCARDHANDLE hCard, LPSTR mszReaderNames, LPDWORD pcchReaderLen,
 	LPDWORD pdwState, LPDWORD pdwProtocol, LPBYTE pbAtr, LPDWORD pcbAtrLen);
 typedef LONG (PCSC_API *SCardGetStatusChange_t)(SCARDCONTEXT hContext, DWORD dwTimeout,
-	LPSCARD_READERSTATE_A rgReaderStates, DWORD cReaders);
+	LPSCARD_READERSTATE rgReaderStates, DWORD cReaders);
 typedef LONG (PCSC_API *SCardControlOLD_t)(SCARDHANDLE hCard, LPCVOID pbSendBuffer, DWORD cbSendLength,
 	LPVOID pbRecvBuffer, LPDWORD lpBytesReturned);
 typedef LONG (PCSC_API *SCardControl_t)(SCARDHANDLE hCard, DWORD dwControlCode, LPCVOID pbSendBuffer,
