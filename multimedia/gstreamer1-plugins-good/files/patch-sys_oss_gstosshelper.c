--- sys/oss/gstosshelper.c.orig	2014-01-14 13:03:14.000000000 +0100
+++ sys/oss/gstosshelper.c	2014-09-11 09:10:55.115013111 +0200
@@ -95,9 +95,13 @@
   format_mask = AFMT_U8 | AFMT_S8;
 
   if (G_BYTE_ORDER == G_LITTLE_ENDIAN)
-    format_mask |= AFMT_S16_LE | AFMT_U16_LE;
+    format_mask |= AFMT_S16_LE | AFMT_U16_LE
+      | AFMT_S24_LE | AFMT_U24_LE
+      | AFMT_S32_LE | AFMT_U32_LE;
   else
-    format_mask |= AFMT_S16_BE | AFMT_U16_BE;
+    format_mask |= AFMT_S16_BE | AFMT_U16_BE
+      | AFMT_S24_BE | AFMT_U24_BE
+      | AFMT_S32_BE | AFMT_U32_BE;
 
   caps = gst_caps_new_empty ();
 
@@ -169,6 +173,9 @@
   const gchar *format;
 
   switch (format_bit) {
+    case AFMT_S8:
+      format = "S8";
+      break;
     case AFMT_U8:
       format = "U8";
       break;
@@ -178,15 +185,36 @@
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
@@ -324,13 +352,17 @@
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
