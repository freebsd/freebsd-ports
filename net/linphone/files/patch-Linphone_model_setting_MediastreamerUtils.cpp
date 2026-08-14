--- Linphone/model/setting/MediastreamerUtils.cpp.orig
+++ Linphone/model/setting/MediastreamerUtils.cpp
@@ -49,6 +49,7 @@
	if (event == MS_FILTER_OUTPUT_FMT_CHANGED) {
		SimpleCaptureGraph *graph = (SimpleCaptureGraph *)user_data;
-		int captureRate, playbackRate, captureChannels, playbackChannels;
+		int captureRate = 8000, playbackRate = 8000;
+		int captureChannels = 1, playbackChannels = 1;
		ms_filter_call_method(graph->audioCapture, MS_FILTER_GET_SAMPLE_RATE, &captureRate);
		ms_filter_call_method(graph->audioSink, MS_FILTER_GET_SAMPLE_RATE, &playbackRate);
		ms_filter_call_method(graph->audioCapture, MS_FILTER_GET_NCHANNELS, &captureChannels);
@@ -77,7 +78,8 @@
		playbackVolumeFilter = ms_factory_create_filter(msFactory, MS_VOLUME_ID);
	}
	if (!resamplerFilter) resamplerFilter = ms_factory_create_filter(msFactory, MS_RESAMPLE_ID);
-	int captureRate, playbackRate, captureChannels, playbackChannels;
+	int captureRate = 8000, playbackRate = 8000;
+	int captureChannels = 1, playbackChannels = 1;
	ms_filter_call_method(audioCapture, MS_FILTER_GET_SAMPLE_RATE, &captureRate);
	ms_filter_call_method(audioSink, MS_FILTER_GET_SAMPLE_RATE, &playbackRate);
	ms_filter_call_method(audioCapture, MS_FILTER_GET_NCHANNELS, &captureChannels);
