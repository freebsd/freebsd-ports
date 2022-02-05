--- ffplay/audio_renderer.cpp.orig	2022-02-05 21:39:05 UTC
+++ ffplay/audio_renderer.cpp
@@ -149,7 +149,7 @@ int AudioRenderer::configure_audio_filters(VideoState 
                    1, is->audio_filter_src.freq);
     if (is->audio_filter_src.channel_layout)
         snprintf(asrc_args + ret, sizeof(asrc_args) - ret,
-                 ":channel_layout=0x%"PRIx64,  is->audio_filter_src.channel_layout);
+                 ":channel_layout=0x%" PRIx64,  is->audio_filter_src.channel_layout);
 
     ret = avfilter_graph_create_filter(&filt_asrc,
                                        avfilter_get_by_name("abuffer"), "ffplay_abuffer",
