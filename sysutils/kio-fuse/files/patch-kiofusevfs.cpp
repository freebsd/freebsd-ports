--- kiofusevfs.cpp.orig	2020-06-05 16:51:15 UTC
+++ kiofusevfs.cpp
@@ -2320,7 +2320,9 @@ int KIOFuseVFS::kioErrorToFuseError(const int kioError
 		case KIO::ERR_CANNOT_RENAME_PARTIAL        : return EIO;
 		case KIO::ERR_NEED_PASSWD                  : return EACCES;
 		case KIO::ERR_CANNOT_SYMLINK               : return EIO;
+#ifdef ENODATA
 		case KIO::ERR_NO_CONTENT                   : return ENODATA;
+#endif
 		case KIO::ERR_DISK_FULL                    : return ENOSPC;
 		case KIO::ERR_IDENTICAL_FILES              : return EEXIST;
 		case KIO::ERR_SLAVE_DEFINED                : return EIO;
