--- ./src/mediatrc_ffmpeg.h.orig	2011-05-15 15:23:34.000000000 +0200
+++ ./src/mediatrc_ffmpeg.h	2011-10-03 14:39:08.471837492 +0200
@@ -3,7 +3,7 @@
 // Purpose:     FFMPEG Media Transcoder
 // Author:      Alex Thuering
 // Created:     26.04.2008
-// RCS-ID:      $Id: mediatrc_ffmpeg.h,v 1.19 2011/05/15 13:23:34 ntalex Exp $
+// RCS-ID:      $Id: mediatrc_ffmpeg.h,v 1.21 2011/08/01 20:30:09 ntalex Exp $
 // Copyright:   (c) Alex Thuering
 // Licence:     GPL
 /////////////////////////////////////////////////////////////////////////////
@@ -14,19 +14,15 @@
 #include "mediatrc.h"
 #include <stdint.h>
 #include <math.h>
+#include <map>
 
 #define INT64_C(val) val##LL
 #define UINT64_C(val) val##ULL
 extern "C" {
 #define __STDC_CONSTANT_MACROS
 #define __STDC_LIMIT_MACROS
-#ifdef HAVE_FFMPEG_AVUTIL_H
-#include <avformat.h>
-#include <swscale.h>
-#else
 #include <libavformat/avformat.h>
 #include <libswscale/swscale.h>
-#endif
 }
 
 // select an input stream for an output stream
@@ -39,8 +35,9 @@
 
 // select an input file for an output file
 typedef struct AVMetaDataMap {
-    int out_file;
-    int in_file;
+	int  file;      //< file index  
+	char type;      //< type of metadata to copy -- (g)lobal, (s)tream, (c)hapter or (p)rogram
+	int  index;     //< stream/chapter/program number 
 } AVMetaDataMap;
 
 typedef struct AVChapterMap {
@@ -50,6 +47,8 @@
 
 struct AVInputStream;
 struct AVOutputStream;
+struct AVDictionary;
+struct AVInputFile;
 
 #define MAX_FILES 50
 #define MAX_STREAMS_ 20
@@ -81,6 +80,8 @@
 	void SetRecordingTime(double recordingTime);
 	/** Sets video filters */
 	void SetVideoFilters(const wxString& videoFilters) { m_videoFilters = videoFilters; }
+	/** Sets audio volume (256=normal) */
+	void SetAudioVolume(int streamIndex, int audioVolume) { m_audioVolume[streamIndex] = audioVolume; }
 	
 	/** Starts transcoding. */
 	bool Run(bool& canceled);
@@ -108,21 +109,20 @@
 	void PrintReport(AVFormatContext **output_files, AVOutputStream **ost_table,
 			int nb_ostreams, int is_last_report);
 	int CopyChapters(int infile, int outfile);
-    AVFormatContext *input_files[MAX_FILES];
-    int nb_input_files;
     int64_t input_files_ts_offset[MAX_FILES];
     double* input_files_ts_scale[MAX_FILES];
     int nb_input_files_ts_scale[MAX_FILES];
+    
+    AVCodec **input_codecs;
+    int nb_input_codecs;
 
     AVFormatContext* output_files[MAX_FILES];
-	AVCodec** output_codecs;
     int nb_output_files;
-	int nb_output_codecs;
 
     AVStreamMap* stream_maps;
 	int nb_stream_maps;
 
-    AVMetaDataMap meta_data_maps[MAX_FILES];
+    AVMetaDataMap (*meta_data_maps)[2];
     int nb_meta_data_maps;
     int metadata_global_autocopy;
     int metadata_streams_autocopy;
@@ -134,7 +134,6 @@
     int frame_width;
     int frame_height;
     float frame_aspect_ratio;
-    int frame_aspect_ratio_override;
     PixelFormat frame_pix_fmt;
     int frame_bits_per_raw_sample;
     SampleFormat audio_sample_fmt;
@@ -163,10 +162,10 @@
     int audio_channels;
     unsigned int audio_codec_tag;
     char *audio_language;
-
+    
     char *subtitle_language;
     unsigned int subtitle_codec_tag;
-
+    
     float mux_preload;
     float mux_max_delay;
 
@@ -174,7 +173,7 @@
     int64_t start_time;
     int64_t recording_timestamp;
     int64_t input_ts_offset;
-    AVMetadata* metadata;
+    AVDictionary *metadata;
     int do_psnr;
     int do_pass;
     const char *pass_logfilename_prefix;
@@ -182,8 +181,8 @@
     int audio_sync_method;
     float audio_drift_threshold;
     int copy_ts;
-    int opt_shortest; //
-    int video_global_header;
+    int copy_tb;
+    int opt_shortest;
     char *vstats_filename;
     FILE *vstats_file;
     int opt_programid;
@@ -194,7 +193,7 @@
     int  video_channel;
     char *video_standard;
 
-    int audio_volume;
+    map<int, int> m_audioVolume; // stream index -> audio volume
 
     int exit_on_error;
     int verbose;
@@ -222,6 +221,12 @@
     AVBitStreamFilterContext *video_bitstream_filters;
     AVBitStreamFilterContext *audio_bitstream_filters;
     AVBitStreamFilterContext *subtitle_bitstream_filters;
+    
+    AVInputStream *input_streams;
+    int nb_input_streams;
+    AVInputFile *input_files;
+    int nb_input_files;
+    
     AVOutputStream** output_streams_for_file[MAX_FILES];
     int nb_output_streams_for_file[MAX_FILES];
 };
