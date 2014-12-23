--- Input/mikmod/drv_xmms.c.orig	2003-05-19 21:22:06 UTC
+++ Input/mikmod/drv_xmms.c
@@ -117,6 +117,10 @@ static BOOL xmms_Reset(void)
 	return VC_Init();
 }
 
+static void xmms_CommandLine(CHAR * commandLine)
+{
+}
+
 MDRIVER drv_xmms =
 {
 	NULL,
@@ -127,6 +131,7 @@ MDRIVER drv_xmms =
         "xmms",
         NULL,
 #endif
+        xmms_CommandLine, 
         xmms_IsThere, 
 	VC_SampleLoad,
 	VC_SampleUnload,
