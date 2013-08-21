--- ext/libav/gstavdec.c.orig	2013-08-20 23:08:42.000000000 +0200
+++ ext/libav/gstavdec.c	2013-08-20 23:08:53.000000000 +0200
@@ -1432,9 +1432,6 @@
       case CODEC_ID_SIPR:
         rank = GST_RANK_SECONDARY;
         break;
-      case CODEC_ID_MP3:
-        rank = GST_RANK_NONE;
-        break;
       default:
         rank = GST_RANK_MARGINAL;
         break;
