Author: Michael Niedermayer <michael@niedermayer.cc>
Date:   Tue Nov 29 18:48:40 2016 +0100

    ffserver_config: Setup codecpar in add_codec()
    
    fixes segfault in the status page code
    
    Signed-off-by: Michael Niedermayer <michael@niedermayer.cc>

https://git.videolan.org/?p=ffmpeg.git;a=commitdiff;h=472fee91bcf9

--- ffserver_config.c.orig	2016-12-05 23:28:53 UTC
+++ ffserver_config.c
@@ -323,6 +323,8 @@ done:
     av_dict_free(&recommended);
     av_stream_set_recommended_encoder_configuration(st, enc_config);
     st->codec = av;
+    st->codecpar = avcodec_parameters_alloc();
+    avcodec_parameters_from_context(st->codecpar, av);
     stream->streams[stream->nb_streams++] = st;
 }
 
