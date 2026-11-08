--- src/mod/applications/mod_av/avcodec.c.orig	2026-10-03 00:00:00 UTC
+++ src/mod/applications/mod_av/avcodec.c	2026-10-03 00:00:00 UTC
@@ -530,7 +530,7 @@
 	aprofile->decoder_thread_count = avcodec_globals.dec_threads;
 
 	if (!strcasecmp(name, "H264")) {
-		aprofile->ctx.profile = FF_PROFILE_H264_BASELINE;
+		aprofile->ctx.profile = AV_PROFILE_H264_BASELINE;
 		aprofile->ctx.level = 31;
 #ifdef AV_CODEC_FLAG_PSNR
 		aprofile->ctx.flags |= AV_CODEC_FLAG_PSNR;
@@ -2071,7 +2071,7 @@
 
 	ctx = &aprofile->ctx;
 
-	ctx->profile = FF_PROFILE_H264_BASELINE;
+	ctx->profile = AV_PROFILE_H264_BASELINE;
 	ctx->level = 31;
 
 	for (param = switch_xml_child(profile, "param"); param; param = param->next) {
@@ -2094,11 +2094,11 @@
 
 			if (ctx->profile == 0 && !strcasecmp(aprofile->name, "H264")) {
 				if (!strcasecmp(value, "baseline")) {
-					ctx->profile = FF_PROFILE_H264_BASELINE;
+					ctx->profile = AV_PROFILE_H264_BASELINE;
 				} else if (!strcasecmp(value, "main")) {
-					ctx->profile = FF_PROFILE_H264_MAIN;
+					ctx->profile = AV_PROFILE_H264_MAIN;
 				} else if (!strcasecmp(value, "high")) {
-					ctx->profile = FF_PROFILE_H264_HIGH;
+					ctx->profile = AV_PROFILE_H264_HIGH;
 				}
 			}
 		} else if (!strcmp(name, "level")) {
