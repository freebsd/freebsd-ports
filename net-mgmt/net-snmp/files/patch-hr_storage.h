--- agent/mibgroup/host/hr_storage.h.orig	Tue Feb 25 22:17:48 2003
+++ agent/mibgroup/host/hr_storage.h	Wed May  5 15:27:40 2004
@@ -12,6 +12,7 @@
 #define	HRS_TYPE_MBUF		1
 #define	HRS_TYPE_MEM		2
 #define	HRS_TYPE_SWAP		3
-#define	HRS_TYPE_FIXED_MAX	3     /* the largest fixed type */
+#define	HRS_TYPE_MBUFCLUSTER	4
+#define	HRS_TYPE_FIXED_MAX	4     /* the largest fixed type */
 
 #endif                          /* _MIBGROUP_HRSTORAGE_H */
