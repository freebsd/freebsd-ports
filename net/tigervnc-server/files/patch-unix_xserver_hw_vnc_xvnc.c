--- unix/xserver/hw/vnc/xvnc.c.orig	2019-12-20 07:02:02 UTC
+++ unix/xserver/hw/vnc/xvnc.c
@@ -295,6 +295,15 @@ void ddxBeforeReset(void)
 }
 #endif
 
+#if INPUTTHREAD
+/** This function is called in Xserver/os/inputthread.c when starting
+    the input thread. */
+void
+ddxInputThreadInit(void)
+{
+}
+#endif
+
 void ddxUseMsg(void)
 {
     vncPrintBanner();
