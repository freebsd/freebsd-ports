--- tools/libfsimage/zfs/fsys_zfs.h.orig	2020-03-26 16:41:12 UTC
+++ tools/libfsimage/zfs/fsys_zfs.h
@@ -71,7 +71,7 @@ typedef	unsigned int size_t;
  * Can only be used in functions returning non-0 for failure.
  */
 #define	VERIFY_DN_TYPE(dnp, type) \
-	if (type && (dnp)->dn_type != type) { \
+	if (type != DMU_OT_NONE && (dnp)->dn_type != type) { \
 		return (ERR_FSYS_CORRUPT); \
 	}
 
@@ -80,7 +80,7 @@ typedef	unsigned int size_t;
  * Can only be used in functions returning 0 for failure.
  */
 #define	VERIFY_OS_TYPE(osp, type) \
-	if (type && (osp)->os_type != type) { \
+	if (type != DMU_OST_NONE && (osp)->os_type != type) { \
 		errnum = ERR_FSYS_CORRUPT; \
 		return (0); \
 	}
