--- src/spinach.c.orig	2024-02-05 14:49:26.506828000 -0800
+++ src/spinach.c	2024-02-05 14:49:29.073850000 -0800
@@ -1,6 +1,7 @@
 const char *SIGN_spinach="{FILESIGN=spinach.c:20141022165616+0900:6d5712e8b172965e:Author@DeleGate.ORG:QAuaedIMjRwBwNOQV6i5Npwxzs5vGiO1LUZGAPvCx/z2/MaibLcm/aDgC8rvQcW099Jkdr9EknO0VzSUXBxHJ3eVBUQmhPQQydP4bqOafcJSwJaccO7R56eqsZ/8/qnDfJEhHyArArSsCPsxJtDo/36DRt1q461MBcYDDWLyasY=}";
 /*////////////////////////////////////////////////////////////////////////
-Copyright (c) 2009 National Institute of Advanced Industrial Science and Technology (AIST)
+Copyright (c) 2009 National Institute of Advanced Industrial Science and
+ Technology (AIST)
 AIST-Product-ID: 2000-ETL-198715-01, H14PRO-049, H15PRO-165, H18PRO-443
 
 Permission to use this material for noncommercial and/or evaluation
@@ -57,8 +58,8 @@
 int eccActivity = 0;
 
 #ifndef SHUT_WR
-#define SHUT_WR		SD_SEND /* 0 or 1 ? */
-#define SHUT_RDWR	SD_BOTH /* 2 */
+#define SHUT_WR		(0|1)/*SD_SEND*/ /* 0 or 1 ? */
+#define SHUT_RDWR	(2)/*SD_BOTH*/ /* 2 */
 #endif
 int ShutdownSocketRDWR(int fd){
 	return shutdown(fd,SHUT_RDWR);
@@ -5003,4 +5004,3 @@
 	}
 	return 0;
 }
-
