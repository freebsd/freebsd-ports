--- ./chrome/browser/renderer_host/render_widget_helper.cc.orig	2010-12-16 02:11:57.000000000 +0100
+++ ./chrome/browser/renderer_host/render_widget_helper.cc	2010-12-20 20:15:08.000000000 +0100
@@ -58,7 +58,7 @@
   // object, so we should not be destroyed unless pending_paints_ is empty!
   DCHECK(pending_paints_.empty());
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
   ClearAllocatedDIBs();
 #endif
 }
@@ -274,7 +274,7 @@
     host->CreateNewFullscreenWidget(route_id, popup_type);
 }
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
 TransportDIB* RenderWidgetHelper::MapTransportDIB(TransportDIB::Id dib_id) {
   AutoLock locked(allocated_dibs_lock_);
 
