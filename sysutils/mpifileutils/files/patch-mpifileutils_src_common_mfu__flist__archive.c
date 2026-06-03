--- mpifileutils/src/common/mfu_flist_archive.c.orig	2025-02-19 22:20:52 UTC
+++ mpifileutils/src/common/mfu_flist_archive.c
@@ -27,6 +27,10 @@
 #include <string.h>
 #include <getopt.h>
 
+#ifndef O_LARGEFILE
+#define O_LARGEFILE 0
+#endif
+
 /* gettimeofday */
 #include <sys/time.h>
 
@@ -5255,6 +5259,7 @@ static int extract_xattrs(
                 r = archive_entry_xattr_next(entry, &xname, &xval, &xsize);
                 if (r == ARCHIVE_OK) {
                     /* successfully extracted xattr, now try to set it */
+#if defined(__linux__)
                     int set_rc = setxattr(path, xname, xval, xsize, 0);
                     if (set_rc == -1) {
                         MFU_LOG(MFU_LOG_ERR, "failed to setxattr '%s' on '%s' errno=%d %s",
@@ -5263,6 +5268,10 @@ static int extract_xattrs(
                         rc = MFU_FAILURE;
                         /* don't break in case other xattrs work */
                     }
+#else
+                    /* FreeBSD: implement Linux setxattr() equivalent using extattr(2) */
+                    (void)path; (void)xname; (void)xval; (void)xsize;
+#endif
                 } else {
                     /* failed to read xattr */
                     MFU_LOG(MFU_LOG_ERR, "failed to extract xattr for '%s' of entry %llu at offset %llu",
