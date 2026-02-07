--- far2l/src/panels/infolist.cpp.orig	2025-10-26 08:39:52 UTC
+++ far2l/src/panels/infolist.cpp
@@ -62,7 +62,7 @@ THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF S
 // # include <sys/sysctl.h>
 #include <mach/mach_host.h>
 #include <mach/vm_statistics.h>
-#elif !defined(__FreeBSD__) && !defined(__DragonFly__) && !defined(__HAIKU__)
+#elif !defined(__DragonFly__) && !defined(__HAIKU__)
 #include <sys/sysinfo.h>
 #endif
 #include <sys/statvfs.h>
@@ -171,8 +171,7 @@ void InfoList::DisplayObject()
 	//	FARString strDriveRoot;
 	FARString strVolumeName, strFileSystemName, strFileSystemMountPoint;
 	DWORD MaxNameLength, FileSystemFlags;
-	DWORD64 VolumeNumber;
-	FARString strDiskNumber;
+	FARString strDeviceName, strDiskNumber; // Serial Number, really.
 	CloseFile();
 	ClearTitles();
 
@@ -223,13 +222,11 @@ void InfoList::DisplayObject()
 		ConvertNameToReal(strCurDir, strRealDir);
 
 		fprintf(stderr, "apiGetVolumeInformation: %ls\n", strRealDir.CPtr());
-		bool b_info = apiGetVolumeInformation(strRealDir, &strVolumeName, &VolumeNumber, &MaxNameLength, &FileSystemFlags,
-					&strFileSystemName, &strFileSystemMountPoint);
+		bool b_info = apiGetVolumeInformation(strRealDir, &strVolumeName, &strDiskNumber, &MaxNameLength, &FileSystemFlags,
+					&strFileSystemName, &strDeviceName, &strFileSystemMountPoint);
 		if (b_info) {
 			//		strTitle=FARString(L" ")+DiskType+L" "+Msg::InfoDisk+L" "+(strDriveRoot)+L" ("+strFileSystemName+L") ";
-			strTitle = L"(" + strFileSystemName + L")";
-
-			strDiskNumber.Format(L"%08X-%08X", (DWORD)(VolumeNumber >> 32), (DWORD)(VolumeNumber & 0xffffffff));
+			strTitle = strDeviceName + L" (" + strFileSystemName + L")";
 		} else						// Error!
 			strTitle = strCurDir;	// strDriveRoot;
 
@@ -259,9 +256,11 @@ void InfoList::DisplayObject()
 				PrintInfo(strVolumeName);
 			}
 
+		if (!strDiskNumber.IsEmpty()) {
 			GotoXY(X1 + 2, CurY++);
 			PrintText(Msg::InfoDiskNumber);
 			PrintInfo(strDiskNumber);
+		}
 
 			// new fields
 			GotoXY(X1 + 2, CurY++);
@@ -444,7 +443,7 @@ void InfoList::DisplayObject()
 			PrintInfo(strOutStr);
 		}
 
-#elif !defined(__FreeBSD__) && !defined(__DragonFly__) && !defined(__HAIKU__)
+#elif !defined(__DragonFly__) && !defined(__HAIKU__)
 		struct sysinfo si = {};
 		if (sysinfo(&si) == 0) {
 			DWORD dwMemoryLoad = 100 - ToPercent64(si.freeram + si.freeswap, si.totalram + si.totalswap);
@@ -683,7 +682,7 @@ void InfoList::PrintInfo(const wchar_t *str)
 
 	FARString strStr = str;
 	TruncStr(strStr, MaxLength);
-	int Length = (int)strStr.GetLength();
+	int Length = (int)strStr.CellsCount();
 	int NewX = X2 - Length - 1;
 
 	if (NewX > X1 && NewX > WhereX()) {
