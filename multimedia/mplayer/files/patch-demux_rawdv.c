--- libmpdemux/demux_rawdv.c.orig	Sat Mar 22 17:31:29 2003
+++ libmpdemux/demux_rawdv.c	Wed Aug  6 21:10:01 2003
@@ -40,7 +40,7 @@
 {
    rawdv_frames_t *frames = (rawdv_frames_t *)demuxer->priv;
    sh_video_t *sh_video = demuxer->video->sh;
-   int newpos=(flags&1)?0:frames->current_frame;
+   off_t newpos=(flags&1)?0:frames->current_frame;
    if(flags&2)
    {
       // float 0..1
