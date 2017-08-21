--- libavcodec/libopenjpegenc.c.orig	2017-07-29 17:49:30 UTC
+++ libavcodec/libopenjpegenc.c
@@ -32,6 +32,8 @@
 #include "avcodec.h"
 #include "internal.h"
 
+#if HAVE_OPENJPEG_2_2_OPENJPEG_H
+#  include <openjpeg-2.2/openjpeg.h>
 #if HAVE_OPENJPEG_2_1_OPENJPEG_H
 #  include <openjpeg-2.1/openjpeg.h>
 #elif HAVE_OPENJPEG_2_0_OPENJPEG_H
@@ -42,7 +44,7 @@
 #  include <openjpeg.h>
 #endif
 
-#if HAVE_OPENJPEG_2_1_OPENJPEG_H || HAVE_OPENJPEG_2_0_OPENJPEG_H
+#if HAVE_OPENJPEG_2_2_OPENJPEG_H || HAVE_OPENJPEG_2_1_OPENJPEG_H || HAVE_OPENJPEG_2_0_OPENJPEG_H
 #  define OPENJPEG_MAJOR_VERSION 2
 #  define OPJ(x) OPJ_##x
 #else
@@ -305,7 +307,7 @@ static av_cold int libopenjpeg_encode_in
 
     opj_set_default_encoder_parameters(&ctx->enc_params);
 
-#if HAVE_OPENJPEG_2_1_OPENJPEG_H
+#if HAVE_OPENJPEG_2_2_OPENJPEG_H || HAVE_OPENJPEG_2_1_OPENJPEG_H
     switch (ctx->cinema_mode) {
     case OPJ_CINEMA2K_24:
         ctx->enc_params.rsiz = OPJ_PROFILE_CINEMA_2K;
@@ -769,7 +771,7 @@ static int libopenjpeg_encode_frame(AVCo
     opj_stream_set_write_function(stream, stream_write);
     opj_stream_set_skip_function(stream, stream_skip);
     opj_stream_set_seek_function(stream, stream_seek);
-#if HAVE_OPENJPEG_2_1_OPENJPEG_H
+#if HAVE_OPENJPEG_2_2_OPENJPEG_H || HAVE_OPENJPEG_2_1_OPENJPEG_H
     opj_stream_set_user_data(stream, &writer, NULL);
 #elif HAVE_OPENJPEG_2_0_OPENJPEG_H
     opj_stream_set_user_data(stream, &writer);
