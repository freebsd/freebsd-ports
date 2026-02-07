--- src/input/input_v4l.c.orig
+++ src/input/input_v4l.c
@@ -1394,10 +1394,6 @@
 	/* On buffer overrun we need to re prepare the capturing pcm device */
 	snd_pcm_prepare(this->pcm_handle);
 	break;
-      case -ESTRPIPE:   /* Suspend event */
-	xprintf(this->stream->xine, XINE_VERBOSITY_LOG,
-                "input_v4l: PCM suspend event occured\n");
-	break;
       default:	      /* Unknown */
 	xprintf(this->stream->xine, XINE_VERBOSITY_LOG,
                 "input_v4l: Unknown PCM error code: %d\n", pcmreturn);
