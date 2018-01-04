From 2ecf240b1cd20875991a5b18efafbe799864ff7f Mon Sep 17 00:00:00 2001
From: Mark Thompson <sw@jkqxz.net>
Date: Mon, 9 Oct 2017 20:10:26 +0100
Subject: [PATCH] vaapi: Use libva2 message callbacks

They are no longer global, so they work vaguely sensibly.
--- video/vaapi.c.orig	2017-09-13 01:40:14 UTC
+++ video/vaapi.c
@@ -112,9 +112,27 @@ static void va_get_formats(struct mp_vaa
     ctx->image_formats = formats;
 }
 
-// VA message callbacks are global and do not have a context parameter, so it's
-// impossible to know from which VADisplay they originate. Try to route them
-// to existing mpv/libmpv instances within this process.
+#if VA_CHECK_VERSION(1, 0, 0)
+static void va_message_callback(void *context, const char *msg, int mp_level)
+{
+    struct mp_vaapi_ctx *res = context;
+    mp_msg(res->log, mp_level, "libva: %s", msg);
+}
+
+static void va_error_callback(void *context, const char *msg)
+{
+    va_message_callback(context, msg, MSGL_ERR);
+}
+
+static void va_info_callback(void *context, const char *msg)
+{
+    va_message_callback(context, msg, MSGL_V);
+}
+#else
+// Pre-libva2 VA message callbacks are global and do not have a context
+// parameter, so it's impossible to know from which VADisplay they
+// originate.  Try to route them to existing mpv/libmpv instances within
+// this process.
 static pthread_mutex_t va_log_mutex = PTHREAD_MUTEX_INITIALIZER;
 static struct mp_vaapi_ctx **va_mpv_clients;
 static int num_va_mpv_clients;
@@ -149,6 +167,7 @@ static void va_info_callback(const char 
 {
     va_message_callback(msg, MSGL_V);
 }
+#endif
 
 static void open_lavu_vaapi_device(struct mp_vaapi_ctx *ctx)
 {
@@ -181,6 +200,10 @@ struct mp_vaapi_ctx *va_initialize(VADis
         },
     };
 
+#if VA_CHECK_VERSION(1, 0, 0)
+    vaSetErrorCallback(display, va_error_callback, res);
+    vaSetInfoCallback(display,  va_info_callback,  res);
+#else
     pthread_mutex_lock(&va_log_mutex);
     MP_TARRAY_APPEND(NULL, va_mpv_clients, num_va_mpv_clients, res);
     pthread_mutex_unlock(&va_log_mutex);
@@ -191,6 +214,7 @@ struct mp_vaapi_ctx *va_initialize(VADis
     vaSetErrorCallback(va_error_callback);
     vaSetInfoCallback(va_info_callback);
 #endif
+#endif
 
     int major_version, minor_version;
     int status = vaInitialize(display, &major_version, &minor_version);
@@ -231,6 +255,7 @@ void va_destroy(struct mp_vaapi_ctx *ctx
         if (ctx->destroy_native_ctx)
             ctx->destroy_native_ctx(ctx->native_ctx);
 
+#if !VA_CHECK_VERSION(1, 0, 0)
         pthread_mutex_lock(&va_log_mutex);
         for (int n = 0; n < num_va_mpv_clients; n++) {
             if (va_mpv_clients[n] == ctx) {
@@ -241,6 +266,7 @@ void va_destroy(struct mp_vaapi_ctx *ctx
         if (num_va_mpv_clients == 0)
             TA_FREEP(&va_mpv_clients); // avoid triggering leak detectors
         pthread_mutex_unlock(&va_log_mutex);
+#endif
 
         talloc_free(ctx);
     }
