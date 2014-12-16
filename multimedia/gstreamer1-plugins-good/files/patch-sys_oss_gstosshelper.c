--- sys/oss/gstosshelper.c.orig	2014-07-21 10:24:27.000000000 +0200
+++ sys/oss/gstosshelper.c	2014-10-12 18:13:53.847663389 +0200
@@ -82,9 +82,9 @@
 gst_oss_helper_probe_caps (gint fd)
 {
 #if G_BYTE_ORDER == G_LITTLE_ENDIAN
-  const guint probe_formats[] = { AFMT_S16_LE, AFMT_U16_LE, AFMT_U8, AFMT_S8 };
+  const guint probe_formats[] = { AFMT_U32_LE, AFMT_S32_LE, AFMT_U24_LE, AFMT_S24_LE, AFMT_S16_LE, AFMT_U16_LE, AFMT_U8, AFMT_S8 };
 #else
-  const guint probe_formats[] = { AFMT_S16_BE, AFMT_U16_BE, AFMT_U8, AFMT_S8 };
+  const guint probe_formats[] = { AFMT_U32_BE, AFMT_S32_BE, AFMT_U24_BE, AFMT_S24_BE, AFMT_S16_BE, AFMT_U16_BE, AFMT_U8, AFMT_S8 };
 #endif
   GstOssProbe *probe;
   int i, f;
@@ -165,6 +165,9 @@
   const gchar *format;
 
   switch (format_bit) {
+    case AFMT_S8:
+      format = "S8";
+      break;
     case AFMT_U8:
       format = "U8";
       break;
@@ -174,15 +177,36 @@
     case AFMT_S16_BE:
       format = "S16BE";
       break;
-    case AFMT_S8:
-      format = "S8";
-      break;
     case AFMT_U16_LE:
       format = "U16LE";
       break;
     case AFMT_U16_BE:
       format = "U16BE";
       break;
+    case AFMT_S24_LE:
+      format = "S24LE";
+      break;
+    case AFMT_S24_BE:
+      format = "S24BE";
+      break;
+    case AFMT_U24_LE:
+      format = "U24LE";
+      break;
+    case AFMT_U24_BE:
+      format = "U24BE";
+      break;
+    case AFMT_S32_LE:
+      format = "S32LE";
+      break;
+    case AFMT_S32_BE:
+      format = "S32BE";
+      break;
+    case AFMT_U32_LE:
+      format = "U32LE";
+      break;
+    case AFMT_U32_BE:
+      format = "U32BE";
+      break;
     default:
       g_assert_not_reached ();
       return NULL;
@@ -320,13 +344,17 @@
   int format;
   int n_channels;
   int ret;
+  int rst;
 
   rate = irate;
   format = probe->format;
   n_channels = probe->n_channels;
+  rst = 4000; /* XXX Lowest supported rate for FreeBSD. */
 
   GST_LOG ("checking format %d, channels %d, rate %d",
       format, n_channels, rate);
+  /* Reset rate to lowest supported rate. */
+  ioctl (probe->fd, SNDCTL_DSP_SPEED, &rst);
   ret = ioctl (probe->fd, SNDCTL_DSP_SETFMT, &format);
   if (ret < 0 || format != probe->format) {
     GST_DEBUG ("unsupported format: %d (%d)", probe->format, format);
