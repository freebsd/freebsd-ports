--- ./phonon/pulsesupport.cpp
+++ ./phonon/pulsesupport.cpp
@@ -569,6 +569,31 @@
                 return;
             }
             pa_operation_unref(o);
+
+            // In the case of reconnection or simply lagging behind the stream object creation
+            // on startup (due to the probe+reconnect system), we invalidate all loaded streams
+            // and then load up info about all streams.
+            for (QMap<QString, PulseStream*>::iterator it = s_outputStreams.begin(); it != s_outputStreams.end(); ++it) {
+              PulseStream *stream = *it;
+              logMessage(QString("Phonon Output Stream %1 is gone at the PA end. Marking it as invalid in our cache as we may reuse it.").arg(stream->uuid()));
+              stream->setIndex(PA_INVALID_INDEX);
+            }
+            if (!(o = pa_context_get_sink_input_info_list(c, sink_input_cb, NULL))) {
+              logMessage(QString("pa_context_get_sink_input_info_list() failed"));
+              return;
+            }
+            pa_operation_unref(o);
+
+            for (QMap<QString, PulseStream*>::iterator it = s_captureStreams.begin(); it != s_captureStreams.end(); ++it) {
+              PulseStream *stream = *it;
+              logMessage(QString("Phonon Capture Stream %1 is gone at the PA end. Marking it as invalid in our cache as we may reuse it.").arg(stream->uuid()));
+              stream->setIndex(PA_INVALID_INDEX);
+            }
+            if (!(o = pa_context_get_source_output_info_list(c, source_output_cb, NULL))) {
+              logMessage(QString("pa_context_get_source_output_info_list() failed"));
+              return;
+            }
+            pa_operation_unref(o);
         }
 
 #ifdef HAVE_PULSEAUDIO_DEVICE_MANAGER