--- src/avbin.c.orig	2008-09-21 08:45:33.000000000 +0200
+++ src/avbin.c	2010-07-11 10:38:40.684168520 +0200
@@ -43,6 +43,8 @@
 
 static AVbinLogCallback user_log_callback = NULL;
 
+static int av_log_level;
+
 /**
  * Format log messages and call the user log callback.  Essentially a
  * reimplementation of libavutil/log.c:av_log_default_callback.
@@ -215,10 +217,6 @@
                     info->audio.sample_format = AVBIN_SAMPLE_FORMAT_S16;
                     info->audio.sample_bits = 16;
                     break;
-                case SAMPLE_FMT_S24:
-                    info->audio.sample_format = AVBIN_SAMPLE_FORMAT_S24;
-                    info->audio.sample_bits = 24;
-                    break;
                 case SAMPLE_FMT_S32:
                     info->audio.sample_format = AVBIN_SAMPLE_FORMAT_S32;
                     info->audio.sample_bits = 32;
