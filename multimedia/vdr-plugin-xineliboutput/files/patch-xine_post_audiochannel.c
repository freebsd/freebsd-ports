--- vdr-xineliboutput/xine_post_audiochannel.c.orig
+++ vdr-xineliboutput/xine_post_audiochannel.c
@@ -72,7 +72,7 @@ typedef struct audioch_post_plugin_s
 /*
  *    Port functions
  */
-#if XINE_VERSION_CODE < 10200
+#if 1 // XINE_VERSION_CODE < 10200
 static int audioch_port_open(xine_audio_port_t *port_gen, xine_stream_t *stream,
                              uint32_t bits, uint32_t rate, int mode) 
 #else
@@ -87,7 +87,7 @@ static int audioch_port_open(xine_audio_
   _x_post_inc_usage(port);
   
   port->stream = stream;
-#if XINE_VERSION_CODE < 10200
+#if 1 // XINE_VERSION_CODE < 10200
   port->bits = bits;
   port->rate = rate;
   port->mode = mode;
@@ -114,7 +114,7 @@ static void audioch_port_put_buffer (xin
   int i;
 
   if(this->channels == 2) {
-#if XINE_VERSION_CODE < 10200
+#if 1 // XINE_VERSION_CODE < 10200
     int step = buf->format.bits / 8;
 #else
     int step = sample_bytes_table[buf->format.sample_format];
@@ -124,7 +124,7 @@ static void audioch_port_put_buffer (xin
     newbuf->vpts = buf->vpts;
     newbuf->frame_header_count = buf->frame_header_count;
     newbuf->first_access_unit = buf->first_access_unit;
-#if XINE_VERSION_CODE < 10200
+#if 1 // XINE_VERSION_CODE < 10200
     newbuf->format.bits = buf->format.bits;
     newbuf->format.rate = buf->format.rate;
     newbuf->format.mode = buf->format.mode;
@@ -258,7 +258,7 @@ static post_plugin_t *audioch_open_plugi
   input_param->name = "parameters";
   input_param->type = XINE_POST_DATA_PARAMETERS;
   input_param->data = &post_api;
-#if XINE_VERSION_CODE >= 10102
+#if 1 // XINE_VERSION_CODE >= 10102
   xine_list_push_back(this->post_plugin.input, input_param);
 #else
   xine_list_append_content(this->post_plugin.input, input_param);
