--- ./src/3rdparty/phonon/gstreamer/artssink.h.orig	2011-06-28 01:58:24.379076184 +0200
+++ ./src/3rdparty/phonon/gstreamer/artssink.h	2011-06-28 01:58:41.639013768 +0200
@@ -40,9 +40,6 @@
 #define GST_IS_ARTS_SINK(obj)        (G_TYPE_CHECK_INSTANCE_TYPE((obj),GST_TYPE_ARTS_SINK))
 #define GST_IS_ARTS_SINK_CLASS(klass)(G_TYPE_CHECK_CLASS_TYPE((klass),GST_TYPE_ARTS_SINK))
 
-typedef struct _ArtsSink ArtsSink;
-typedef struct _ArtsSinkClass ArtsSinkClass;
-
 enum arts_parameter_t_enum {
     ARTS_P_BUFFER_SIZE = 1,
     ARTS_P_BUFFER_TIME = 2,
@@ -65,6 +62,7 @@
     int channels;
     int bytes_per_sample;
 };
+typedef struct _ArtsSink ArtsSink;
 
 struct GConfClient;
 struct GError;
@@ -78,6 +76,7 @@
 struct _ArtsSinkClass {
     GstAudioSinkClass parent_class;
 };
+typedef struct _ArtsSinkClass ArtsSinkClass;
 
 GType arts_sink_get_type (void);
 }
