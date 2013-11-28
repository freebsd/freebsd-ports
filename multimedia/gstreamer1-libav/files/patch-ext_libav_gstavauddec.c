--- ext/libav/gstavauddec.c.orig	2013-11-21 00:29:36.000000000 +0100
+++ ext/libav/gstavauddec.c	2013-11-21 00:29:59.000000000 +0100
@@ -909,9 +909,6 @@
       case AV_CODEC_ID_SIPR:
         rank = GST_RANK_SECONDARY;
         break;
-      case AV_CODEC_ID_MP3:
-        rank = GST_RANK_NONE;
-        break;
       default:
         rank = GST_RANK_MARGINAL;
         break;
