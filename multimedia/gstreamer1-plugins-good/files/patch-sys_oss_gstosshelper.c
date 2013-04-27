--- sys/oss/gstosshelper.c.orig	Sun Apr  2 03:23:53 2006
+++ sys/oss/gstosshelper.c	Sun Apr  2 03:25:44 2006
@@ -343,13 +344,17 @@ gst_oss_helper_rate_check_rate (GstOssPr
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
   if (ret < 0)
     return -1;
