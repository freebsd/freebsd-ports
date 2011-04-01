--- ./chrome/browser/renderer_host/render_widget_helper.h.orig	2010-12-16 02:11:57.000000000 +0100
+++ ./chrome/browser/renderer_host/render_widget_helper.h	2010-12-20 20:15:08.000000000 +0100
@@ -110,7 +110,7 @@
                         const base::TimeDelta& max_delay,
                         IPC::Message* msg);
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
   // Given the id of a transport DIB, return a mapping to it or NULL on error.
   TransportDIB* MapTransportDIB(TransportDIB::Id dib_id);
 #endif
@@ -134,7 +134,7 @@
                                  WebKit::WebPopupType popup_type,
                                  int* route_id);
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
   // Called on the IO thread to handle the allocation of a TransportDIB.  If
   // |cache_in_browser| is |true|, then a copy of the shmem is kept by the
   // browser, and it is the caller's repsonsibility to call
@@ -191,7 +191,7 @@
   // Called on the IO thread to resume a cross-site response.
   void OnCrossSiteClosePageACK(const ViewMsg_ClosePage_Params& params);
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
   // Called on destruction to release all allocated transport DIBs
   void ClearAllocatedDIBs();
 
