--- src/liba52/xine_decoder.c.orig	Sun Apr 28 22:57:28 2002
+++ src/liba52/xine_decoder.c	Thu May 16 22:16:31 2002
@@ -36,8 +36,8 @@
 #include <fcntl.h>
 
 #include "audio_out.h"
-#include "a52.h"
-#include "a52_internal.h"
+#include <a52dec/a52.h>
+#include <a52dec/a52_internal.h>
 #include "buffer.h"
 #include "xine_internal.h"
 #include "xineutils.h"
@@ -58,7 +58,7 @@
   int              frame_length, frame_todo;
   uint16_t         syncword;
 
-  a52_state_t      a52_state;
+  a52_state_t      *a52_state;
   int              a52_flags;
   int              a52_bit_rate;
   int              a52_sample_rate;
@@ -154,8 +154,11 @@
   this->output_open   = 0;
   this->pts           = 0;
 
-  if( !this->samples )
-    this->samples = a52_init (xine_mm_accel(), &this->samples_base);
+  this->a52_state = a52_init (xine_mm_accel());
+
+  if( (this->a52_state) != NULL )
+    if( !this->samples )
+      this->samples = a52_samples (this->a52_state);
 
   /*
    * find out if this driver supports a52 output
@@ -284,7 +287,7 @@
     
     a52_output_flags = this->a52_flags_map[this->a52_flags & A52_CHANNEL_MASK];
     
-    if (a52_frame (&this->a52_state, 
+    if (a52_frame (this->a52_state, 
 		   this->frame_buffer, 
 		   &a52_output_flags,
 		   &level, 384)) {
@@ -293,7 +296,7 @@
     }
     
     if (this->disable_dynrng)
-      a52_dynrng (&this->a52_state, NULL, NULL);
+      a52_dynrng (this->a52_state, NULL, NULL);
 
     this->have_lfe = a52_output_flags & A52_LFE;
     if (this->have_lfe)
@@ -334,7 +337,7 @@
     buf->num_frames = 256*6;
 
     for (i = 0; i < 6; i++) {
-      if (a52_block (&this->a52_state, this->samples)) {
+      if (a52_block (this->a52_state)) {
 	printf ("liba52: a52_block error\n");
 	buf->num_frames = 0;
 	break; 
