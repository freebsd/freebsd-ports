--- far2l/src/farwinapi.hpp.orig	2025-10-26 08:39:52 UTC
+++ far2l/src/farwinapi.hpp
@@ -180,8 +180,8 @@ void apiGetTempPath(FARString &strBuffer);
 bool apiExpandEnvironmentStrings(const wchar_t *src, FARString &strDest);
 
 BOOL apiGetVolumeInformation(const wchar_t *lpwszRootPathName, FARString *pVolumeName,
-		DWORD64 *lpVolumeSerialNumber, LPDWORD lpMaximumComponentLength, LPDWORD lpFileSystemFlags,
-		FARString *pFileSystemName, FARString *pFileSystemMountPoint = nullptr);
+		FARString *pDiskIdent, LPDWORD lpMaximumComponentLength, LPDWORD lpFileSystemFlags,
+		FARString *pFileSystemName, FARString *pDeviceName, FARString *pFileSystemMountPoint);
 
 void apiFindDataToDataEx(const FAR_FIND_DATA *pSrc, FAR_FIND_DATA_EX *pDest);
 
