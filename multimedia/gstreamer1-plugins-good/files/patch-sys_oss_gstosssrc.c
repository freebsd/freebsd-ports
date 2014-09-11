--- sys/oss/gstosssrc.c.orig	2013-09-24 15:05:22.000000000 +0200
+++ sys/oss/gstosssrc.c	2014-09-11 09:10:55.116013220 +0200
@@ -100,7 +100,10 @@
 static guint gst_oss_src_delay (GstAudioSrc * asrc);
 static void gst_oss_src_reset (GstAudioSrc * asrc);
 
-#define FORMATS "{" GST_AUDIO_NE(S16)","GST_AUDIO_NE(U16)", S8, U8 }"
+#define FORMATS "{" GST_AUDIO_NE(S32)","GST_AUDIO_NE(U32)"," \
+                    GST_AUDIO_NE(S24)","GST_AUDIO_NE(U24)"," \
+                    GST_AUDIO_NE(S16)","GST_AUDIO_NE(U16)"," \
+                    "S8, U8 }"
 
 static GstStaticPadTemplate osssrc_src_factory = GST_STATIC_PAD_TEMPLATE ("src",
     GST_PAD_SRC,
@@ -314,6 +317,9 @@
     case GST_AUDIO_RING_BUFFER_FORMAT_TYPE_RAW:
     {
       switch (rfmt) {
+        case GST_AUDIO_FORMAT_S8:
+          result = AFMT_S8;
+          break;
         case GST_AUDIO_FORMAT_U8:
           result = AFMT_U8;
           break;
@@ -323,15 +329,36 @@
         case GST_AUDIO_FORMAT_S16BE:
           result = AFMT_S16_BE;
           break;
-        case GST_AUDIO_FORMAT_S8:
-          result = AFMT_S8;
-          break;
         case GST_AUDIO_FORMAT_U16LE:
           result = AFMT_U16_LE;
           break;
         case GST_AUDIO_FORMAT_U16BE:
           result = AFMT_U16_BE;
           break;
+        case GST_AUDIO_FORMAT_S24LE:
+          result = AFMT_S24_LE;
+          break;
+        case GST_AUDIO_FORMAT_S24BE:
+          result = AFMT_S24_BE;
+          break;
+        case GST_AUDIO_FORMAT_U24LE:
+          result = AFMT_U24_LE;
+          break;
+        case GST_AUDIO_FORMAT_U24BE:
+          result = AFMT_U24_BE;
+          break;
+        case GST_AUDIO_FORMAT_S32LE:
+          result = AFMT_S32_LE;
+          break;
+        case GST_AUDIO_FORMAT_S32BE:
+          result = AFMT_S32_BE;
+          break;
+        case GST_AUDIO_FORMAT_U32LE:
+          result = AFMT_U32_LE;
+          break;
+        case GST_AUDIO_FORMAT_U32BE:
+          result = AFMT_U32_BE;
+          break;
         default:
           result = 0;
           break;
@@ -428,7 +455,7 @@
   rate = GST_AUDIO_INFO_RATE (&spec->info);
   channels = GST_AUDIO_INFO_CHANNELS (&spec->info);
 
-  if (width != 16 && width != 8)
+  if (width != 32 && width != 24 && width != 16 && width != 8)
     goto dodgy_width;
 
   tmp = ilog2 (spec->segsize);
