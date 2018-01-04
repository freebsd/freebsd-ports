From 777bba473e3ed1c7b8b7f7f0322892851c70dfd9 Mon Sep 17 00:00:00 2001
From: =?UTF-8?q?V=C3=ADctor=20Manuel=20J=C3=A1quez=20Leal?=
 <vjaquez@igalia.com>
Date: Tue, 11 Jul 2017 17:29:13 +0200
Subject: libs: utils: libva 1.0 changed the logging

The logging mechanism in libva has changed it's functions
signatures. This patch updates that for libva versions >= 1.0

https://bugzilla.gnome.org/show_bug.cgi?id=784398

diff --git a/gst-libs/gst/vaapi/gstvaapiutils.c b/gst-libs/gst/vaapi/gstvaapiutils.c
index 0ed1efe..c24bed7 100644
--- gst-libs/gst/vaapi/gstvaapiutils.c
+++ gst-libs/gst/vaapi/gstvaapiutils.c
@@ -46,15 +46,43 @@
 #define STRCASE(x)      case x: return STRINGIFY(x)
 
 #if VA_CHECK_VERSION (0,40,0)
-static void
-gst_vaapi_log (const char *message)
+static gchar *
+strip_msg (const char *message)
 {
   gchar *msg;
 
   msg = g_strdup (message);
   if (!msg)
+    return NULL;
+  return g_strstrip (msg);
+}
+
+#if VA_CHECK_VERSION (1,0,0)
+static void
+gst_vaapi_err (void *data, const char *message)
+{
+  gchar *msg;
+
+  msg = strip_msg (message);
+  if (!msg)
+    return;
+  GST_ERROR ("%s", msg);
+  g_free (msg);
+}
+#endif
+
+static void
+gst_vaapi_log (
+#if VA_CHECK_VERSION (1,0,0)
+    void *data,
+#endif
+    const char *message)
+{
+  gchar *msg;
+
+  msg = strip_msg (message);
+  if (!msg)
     return;
-  g_strchomp (msg);
   GST_INFO ("%s", msg);
   g_free (msg);
 }
@@ -66,7 +94,10 @@ vaapi_initialize (VADisplay dpy)
   gint major_version, minor_version;
   VAStatus status;
 
-#if VA_CHECK_VERSION (0,40,0)
+#if VA_CHECK_VERSION (1,0,0)
+  vaSetErrorCallback (dpy, gst_vaapi_err, NULL);
+  vaSetInfoCallback (dpy, gst_vaapi_log, NULL);
+#elif VA_CHECK_VERSION (0,40,0)
   vaSetInfoCallback (gst_vaapi_log);
 #endif
 
-- 
cgit v0.10.2

