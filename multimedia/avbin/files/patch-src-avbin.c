--- src/avbin.c.orig	2008-09-21 08:45:33.000000000 +0200
+++ src/avbin.c	2009-08-11 15:02:52.574916144 +0200
@@ -215,10 +237,6 @@
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
