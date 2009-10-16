--- libavformat/sierravmd.c
+++ libavformat/sierravmd.c
@@ -154,7 +154,7 @@ static int vmd_read_header(AVFormatContext *s,
     vmd->frame_table = NULL;
     sound_buffers = AV_RL16(&vmd->vmd_header[808]);
     raw_frame_table_size = vmd->frame_count * 6;
-    if(vmd->frame_count * vmd->frames_per_block  >= UINT_MAX / sizeof(vmd_frame)){
+    if(vmd->frame_count * vmd->frames_per_block  >= (UINT_MAX - sound_buffers) / sizeof(vmd_frame)){
         av_log(s, AV_LOG_ERROR, "vmd->frame_count * vmd->frames_per_block too large\n");
         return -1;
     }

