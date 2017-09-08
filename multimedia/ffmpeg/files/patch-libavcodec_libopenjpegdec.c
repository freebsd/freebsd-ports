--- libavcodec/libopenjpegdec.c.orig	2017-07-29 17:49:30 UTC
+++ libavcodec/libopenjpegdec.c
@@ -34,7 +34,9 @@
 #include "internal.h"
 #include "thread.h"
 
-#if HAVE_OPENJPEG_2_1_OPENJPEG_H
+#if HAVE_OPENJPEG_2_2_OPENJPEG_H
+#  include <openjpeg-2.2/openjpeg.h>
+#elif HAVE_OPENJPEG_2_1_OPENJPEG_H
 #  include <openjpeg-2.1/openjpeg.h>
 #elif HAVE_OPENJPEG_2_0_OPENJPEG_H
 #  include <openjpeg-2.0/openjpeg.h>
@@ -44,7 +46,7 @@
 #  include <openjpeg.h>
 #endif
 
-#if HAVE_OPENJPEG_2_1_OPENJPEG_H || HAVE_OPENJPEG_2_0_OPENJPEG_H
+#if HAVE_OPENJPEG_2_2_OPENJPEG_H || HAVE_OPENJPEG_2_1_OPENJPEG_H || HAVE_OPENJPEG_2_0_OPENJPEG_H
 #  define OPENJPEG_MAJOR_VERSION 2
 #  define OPJ(x) OPJ_##x
 #else
@@ -429,7 +431,7 @@ static int libopenjpeg_decode_frame(AVCo
     opj_stream_set_read_function(stream, stream_read);
     opj_stream_set_skip_function(stream, stream_skip);
     opj_stream_set_seek_function(stream, stream_seek);
-#if HAVE_OPENJPEG_2_1_OPENJPEG_H
+#if HAVE_OPENJPEG_2_2_OPENJPEG_H || HAVE_OPENJPEG_2_1_OPENJPEG_H
     opj_stream_set_user_data(stream, &reader, NULL);
 #elif HAVE_OPENJPEG_2_0_OPENJPEG_H
     opj_stream_set_user_data(stream, &reader);
