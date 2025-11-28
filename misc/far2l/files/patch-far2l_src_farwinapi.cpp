--- far2l/src/farwinapi.cpp.orig	2025-10-26 08:39:52 UTC
+++ far2l/src/farwinapi.cpp
@@ -38,6 +38,7 @@ THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF S
 #include <fcntl.h>
 #include <errno.h>
 #if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__CYGWIN__)
+#include <sys/disk.h>
 #include <sys/mount.h>
 #elif !defined(__HAIKU__)
 #include <sys/statfs.h>
@@ -472,8 +473,8 @@ bool apiExpandEnvironmentStrings(const wchar_t *src, F
 }
 
 BOOL apiGetVolumeInformation(const wchar_t *lpwszRootPathName, FARString *pVolumeName,
-		DWORD64 *lpVolumeSerialNumber, LPDWORD lpMaximumComponentLength, LPDWORD lpFileSystemFlags,
-		FARString *pFileSystemName, FARString *pFileSystemMountPoint)
+		FARString *pDiskIdent, LPDWORD lpMaximumComponentLength, LPDWORD lpFileSystemFlags,
+		FARString *pFileSystemName, FARString *pDeviceName, FARString *pFileSystemMountPoint)
 {
 	struct statvfs svfs {};
 	const std::string &path = Wide2MB(lpwszRootPathName);
@@ -483,13 +484,9 @@ BOOL apiGetVolumeInformation(const wchar_t *lpwszRootP
 
 	if (lpMaximumComponentLength)
 		*lpMaximumComponentLength = svfs.f_namemax;
-	if (lpVolumeSerialNumber)
-		*lpVolumeSerialNumber = (DWORD)svfs.f_fsid;
 	if (lpFileSystemFlags)
 		*lpFileSystemFlags = (DWORD)svfs.f_flag;
 
-	if (pVolumeName) {
-		pVolumeName->Clear();
 #if 0
 #if defined(FS_IOC_GETFSLABEL) && defined(FSLABEL_MAX)
 		int fd = open(path.c_str(), O_RDONLY);
@@ -502,13 +499,35 @@ BOOL apiGetVolumeInformation(const wchar_t *lpwszRootP
 		}
 #endif
 #endif
-	}
 
 	if (pFileSystemName) {
 		*pFileSystemName = MountInfo().GetFileSystem(path);
 	}
-	if (*pFileSystemMountPoint) {
+	if (pFileSystemMountPoint) {
 		*pFileSystemMountPoint = MountInfo().GetFileSystemMountPoint(lpwszRootPathName);
+	}
+	// XXX: can we avoid calling GetFileSystemMountPoint() twice?
+	const std::string devname = MountInfo().GetFileSystemMountPoint(lpwszRootPathName, true);
+	if (pDeviceName) {
+		*pDeviceName = devname;
+	}
+	if (pDiskIdent) {
+		int fd = open(devname.c_str(), O_RDONLY);
+		if (fd != -1) {
+			char ident[DISK_IDENT_SIZE];
+			if (ioctl(fd, DIOCGIDENT, ident) != -1)
+				*pDiskIdent = ident;
+			close(fd);
+		}
+	}
+	if (pVolumeName) {
+		std::string reply{}, cmd{"fstyp -l " + devname};
+		if (POpen(reply, cmd.c_str())) {
+			const auto pos = reply.find(' ') + 1;
+			if (pos > 0) {
+				*pVolumeName = reply.substr(pos, reply.size() - pos - 1);
+			} //else pVolumeName->Clear();
+		} //else pVolumeName->Clear();
 	}
 
 	return TRUE;
