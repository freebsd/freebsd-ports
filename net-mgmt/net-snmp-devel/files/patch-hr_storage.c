--- agent/mibgroup/host/hr_storage.c.orig	2007-06-08 19:33:58.000000000 +0900
+++ agent/mibgroup/host/hr_storage.c	2008-03-25 21:26:23.470718989 +0900
@@ -489,11 +489,13 @@
 	 *
 	 *********************/
 
+/* kuriyama: should be removed? */
 static const char *hrs_descr[] = {
     NULL,
     "Memory Buffers",           /* HRS_TYPE_MBUF */
     "Real Memory",              /* HRS_TYPE_MEM */
-    "Swap Space"                /* HRS_TYPE_SWAP */
+    "Swap Space",               /* HRS_TYPE_SWAP */
+    "Memory Buffer Clusters"    /* HRS_TYPE_MBUFCLUSTER */
 };
 
 
