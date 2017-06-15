--- plugins/rdp/vinagre-rdp-tab.c.orig	2015-10-06 15:40:06 UTC
+++ plugins/rdp/vinagre-rdp-tab.c
@@ -476,16 +476,18 @@ frdp_drawing_area_draw (GtkWidget *area,
   return TRUE;
 }
 
-static void
+static BOOL
 frdp_begin_paint (rdpContext *context)
 {
   rdpGdi *gdi = context->gdi;
 
   gdi->primary->hdc->hwnd->invalid->null = 1;
   gdi->primary->hdc->hwnd->ninvalid = 0;
+
+  return TRUE;
 }
 
-static void
+static BOOL
 frdp_end_paint (rdpContext *context)
 {
   VinagreRdpTab        *rdp_tab = ((frdpContext *) context)->rdp_tab;
@@ -495,7 +497,7 @@ frdp_end_paint (rdpContext *context)
   gint                  x, y, w, h;
 
   if (gdi->primary->hdc->hwnd->invalid->null)
-    return;
+    return FALSE;
 
   x = gdi->primary->hdc->hwnd->invalid->x;
   y = gdi->primary->hdc->hwnd->invalid->y;
@@ -517,6 +519,8 @@ frdp_end_paint (rdpContext *context)
     {
       gtk_widget_queue_draw_area (priv->display, x, y, w, h);
     }
+
+  return TRUE;
 }
 
 static BOOL
@@ -591,11 +595,15 @@ frdp_post_connect (freerdp *instance)
 #if defined(FREERDP_VERSION_MAJOR) && defined(FREERDP_VERSION_MINOR) && \
     !(FREERDP_VERSION_MAJOR > 1 || (FREERDP_VERSION_MAJOR == 1 && \
     FREERDP_VERSION_MINOR >= 2))
-                    CLRBUF_24BPP,
+                    CLRBUF_24BPP, NULL
 #else
-                    CLRBUF_32BPP,
+#ifdef CLRBUF_32BPP
+                    CLRBUF_32BPP, NULL
+#else
+                    PIXEL_FORMAT_BGRA32
+#endif
 #endif
-                    NULL);
+                    );
   gdi = instance->context->gdi;
 
   instance->update->BeginPaint = frdp_begin_paint;
@@ -862,7 +870,7 @@ frdp_mouse_moved (GtkWidget      *widget
   return TRUE;
 }
 
-static gboolean
+static BOOL
 frdp_authenticate (freerdp  *instance,
                    char    **username,
                    char    **password,
@@ -934,11 +942,13 @@ frdp_authenticate (freerdp  *instance,
   return TRUE;
 }
 
-static BOOL
-frdp_certificate_verify (freerdp *instance,
-                         char    *subject,
-                         char    *issuer,
-                         char    *fingerprint)
+static DWORD
+frdp_certificate_verify (freerdp    *instance,
+                         const char *common_name,
+                         const char *subject,
+                         const char *issuer,
+                         const char *fingerprint,
+                         BOOL        host_mismatch)
 {
   VinagreTab *tab = VINAGRE_TAB (((frdpContext *) instance->context)->rdp_tab);
   GtkBuilder *builder;
@@ -973,12 +983,15 @@ frdp_certificate_verify (freerdp *instan
 
 
 #if HAVE_FREERDP_1_1
-static BOOL
-frdp_changed_certificate_verify (freerdp *instance,
-                                 char    *subject,
-                                 char    *issuer,
-                                 char    *new_fingerprint,
-                                 char    *old_fingerprint)
+static DWORD
+frdp_changed_certificate_verify (freerdp    *instance,
+                                 const char *common_name,
+                                 const char *subject,
+                                 const char *issuer,
+                                 const char *new_fingerprint,
+                                 const char *old_subject,
+                                 const char *old_issuer,
+                                 const char *old_fingerprint)
 {
   VinagreTab *tab = VINAGRE_TAB (((frdpContext *) instance->context)->rdp_tab);
   GtkBuilder *builder;
@@ -1108,7 +1107,7 @@ open_freerdp (VinagreRdpTab *rdp_tab)
   settings->encryption_level = ENCRYPTION_LEVEL_CLIENT_COMPATIBLE;
 #endif
 #include <freerdp/version.h>
-#if (FREERDP_VERSION_MAJOR == 1 && FREERDP_VERSION_MINOR >= 2 && FREERDP_VERSION_REVISION >= 1)
+#if (FREERDP_VERSION_MAJOR == 1 && FREERDP_VERSION_MINOR >= 2 && FREERDP_VERSION_REVISION >= 1) || (FREERDP_VERSION_MAJOR == 2)
   settings->UseRdpSecurityLayer = FALSE;
 #else
   settings->DisableEncryption = FALSE;
