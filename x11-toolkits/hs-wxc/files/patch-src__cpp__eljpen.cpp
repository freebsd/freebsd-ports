--- ./src/cpp/eljpen.cpp.orig	2012-07-03 11:12:17.000000000 +0100
+++ ./src/cpp/eljpen.cpp	2012-09-06 15:58:22.000000000 +0100
@@ -156,7 +156,7 @@
 EWXWEXPORT(void,wxPen_GetStipple)(void* self,wxBitmap* _ref)
 {
 #if defined(__WXGTK__)
-    *_ref = NULL;
+    *_ref = (GdkPixbuf *) NULL;
 #else
     *_ref = *(((wxPen*)self)->GetStipple());
 #endif
