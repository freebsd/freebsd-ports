AVHandler.cc:246:29: error: use of undeclared identifier 'CODEC_CAP_TRUNCATED'
  if (codec->capabilities & CODEC_CAP_TRUNCATED)
                            ^
AVHandler.cc:247:30: error: use of undeclared identifier 'CODEC_FLAG_TRUNCATED'
    vstream->codec->flags |= CODEC_FLAG_TRUNCATED;
                             ^

--- src/AVHandler.cc.orig	2017-05-28 14:27:02 UTC
+++ src/AVHandler.cc
@@ -243,8 +243,8 @@ AVHandler::setup_read()
   codec_name = codec->name;
 
   // We can handle truncated bitstreams
-  if (codec->capabilities & CODEC_CAP_TRUNCATED)
-    vstream->codec->flags |= CODEC_FLAG_TRUNCATED;
+  if (codec->capabilities & AV_CODEC_CAP_TRUNCATED)
+    vstream->codec->flags |= AV_CODEC_FLAG_TRUNCATED;
 
   if (avcodec_open2(vstream->codec, codec, NULL) < 0)
     {
