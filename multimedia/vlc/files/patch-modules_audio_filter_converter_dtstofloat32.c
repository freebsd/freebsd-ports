--- modules/audio_filter/converter/dtstofloat32.c.orig	Tue Apr 17 17:45:06 2007
+++ modules/audio_filter/converter/dtstofloat32.c
@@ -4,7 +4,7 @@
  *   (http://developers.videolan.org/libdca.html).
  *****************************************************************************
  * Copyright (C) 2001, 2002libdca the VideoLAN team
- * $Id: dtstofloat32.c 15172 2006-04-11 13:17:20Z zorglub $
+ * $Id: dtstofloat32.c 19787 2007-04-14 15:07:46Z courmisch $
  *
  * Author: Gildas Bazin <gbazin@videolan.org>
  *
@@ -31,10 +31,10 @@
 #include <stdlib.h>                                      /* malloc(), free() */
 #include <string.h>                                              /* strdup() */
 
-#include <dts.h>                                       /* libdca header file */
+#include <dca.h>                                       /* libdca header file */
 
-#include <vlc/decoder.h>
-#include "aout_internal.h"
+#include <vlc_aout.h>
+#include <vlc_block.h>
 #include "vlc_filter.h"
 
 /*****************************************************************************
@@ -66,7 +66,7 @@
  *****************************************************************************/
 struct filter_sys_t
 {
-    dts_state_t * p_libdts; /* libdca internal structure */
+    dca_state_t * p_libdca; /* libdca internal structure */
     vlc_bool_t b_dynrng; /* see below */
     int i_flags; /* libdca flags, see dtsdec/doc/libdts.txt */
     vlc_bool_t b_dontwarn;
@@ -158,50 +158,50 @@
               || (output.i_original_channels
                    & (AOUT_CHAN_LEFT | AOUT_CHAN_RIGHT)) )
         {
-            p_sys->i_flags = DTS_MONO;
+            p_sys->i_flags = DCA_MONO;
         }
         break;
 
     case AOUT_CHAN_LEFT | AOUT_CHAN_RIGHT:
         if ( output.i_original_channels & AOUT_CHAN_DOLBYSTEREO )
         {
-            p_sys->i_flags = DTS_DOLBY;
+            p_sys->i_flags = DCA_DOLBY;
         }
         else if ( input.i_original_channels == AOUT_CHAN_CENTER )
         {
-            p_sys->i_flags = DTS_MONO;
+            p_sys->i_flags = DCA_MONO;
         }
         else if ( input.i_original_channels & AOUT_CHAN_DUALMONO )
         {
-            p_sys->i_flags = DTS_CHANNEL;
+            p_sys->i_flags = DCA_CHANNEL;
         }
         else
         {
-            p_sys->i_flags = DTS_STEREO;
+            p_sys->i_flags = DCA_STEREO;
         }
         break;
 
     case AOUT_CHAN_LEFT | AOUT_CHAN_RIGHT | AOUT_CHAN_CENTER:
-        p_sys->i_flags = DTS_3F;
+        p_sys->i_flags = DCA_3F;
         break;
 
     case AOUT_CHAN_LEFT | AOUT_CHAN_RIGHT | AOUT_CHAN_REARCENTER:
-        p_sys->i_flags = DTS_2F1R;
+        p_sys->i_flags = DCA_2F1R;
         break;
 
     case AOUT_CHAN_LEFT | AOUT_CHAN_RIGHT | AOUT_CHAN_CENTER
           | AOUT_CHAN_REARCENTER:
-        p_sys->i_flags = DTS_3F1R;
+        p_sys->i_flags = DCA_3F1R;
         break;
 
     case AOUT_CHAN_LEFT | AOUT_CHAN_RIGHT
           | AOUT_CHAN_REARLEFT | AOUT_CHAN_REARRIGHT:
-        p_sys->i_flags = DTS_2F2R;
+        p_sys->i_flags = DCA_2F2R;
         break;
 
     case AOUT_CHAN_LEFT | AOUT_CHAN_RIGHT | AOUT_CHAN_CENTER
           | AOUT_CHAN_REARLEFT | AOUT_CHAN_REARRIGHT:
-        p_sys->i_flags = DTS_3F2R;
+        p_sys->i_flags = DCA_3F2R;
         break;
 
     default:
@@ -211,13 +211,13 @@
     }
     if ( output.i_physical_channels & AOUT_CHAN_LFE )
     {
-        p_sys->i_flags |= DTS_LFE;
+        p_sys->i_flags |= DCA_LFE;
     }
-    //p_sys->i_flags |= DTS_ADJUST_LEVEL;
+    //p_sys->i_flags |= DCA_ADJUST_LEVEL;
 
     /* Initialize libdca */
-    p_sys->p_libdts = dts_init( 0 );
-    if( p_sys->p_libdts == NULL )
+    p_sys->p_libdca = dca_init( 0 );
+    if( p_sys->p_libdca == NULL )
     {
         msg_Err( p_this, "unable to initialize libdca" );
         return VLC_EGENERIC;
@@ -300,7 +300,7 @@
     /* Needs to be called so the decoder knows which type of bitstream it is
      * dealing with. */
     int i_sample_rate, i_bit_rate, i_frame_length;
-    if( !dts_syncinfo( p_sys->p_libdts, p_in_buf->p_buffer, &i_flags,
+    if( !dca_syncinfo( p_sys->p_libdca, p_in_buf->p_buffer, &i_flags,
                        &i_sample_rate, &i_bit_rate, &i_frame_length ) )
     {
         msg_Warn( p_aout, "libdca couldn't sync on frame" );
@@ -309,38 +309,38 @@
     }
 
     i_flags = p_sys->i_flags;
-    dts_frame( p_sys->p_libdts, p_in_buf->p_buffer,
+    dca_frame( p_sys->p_libdca, p_in_buf->p_buffer,
                &i_flags, &i_sample_level, 0 );
 
-    if ( (i_flags & DTS_CHANNEL_MASK) != (p_sys->i_flags & DTS_CHANNEL_MASK)
+    if ( (i_flags & DCA_CHANNEL_MASK) != (p_sys->i_flags & DCA_CHANNEL_MASK)
           && !p_sys->b_dontwarn )
     {
         msg_Warn( p_aout,
                   "libdca couldn't do the requested downmix 0x%x->0x%x",
-                  p_sys->i_flags  & DTS_CHANNEL_MASK,
-                  i_flags & DTS_CHANNEL_MASK );
+                  p_sys->i_flags  & DCA_CHANNEL_MASK,
+                  i_flags & DCA_CHANNEL_MASK );
 
         p_sys->b_dontwarn = 1;
     }
 
     if( 0)//!p_sys->b_dynrng )
     {
-        dts_dynrng( p_sys->p_libdts, NULL, NULL );
+        dca_dynrng( p_sys->p_libdca, NULL, NULL );
     }
 
-    for ( i = 0; i < dts_blocks_num(p_sys->p_libdts); i++ )
+    for ( i = 0; i < dca_blocks_num(p_sys->p_libdca); i++ )
     {
         sample_t * p_samples;
 
-        if( dts_block( p_sys->p_libdts ) )
+        if( dca_block( p_sys->p_libdca ) )
         {
-            msg_Warn( p_aout, "dts_block failed for block %d", i );
+            msg_Warn( p_aout, "dca_block failed for block %d", i );
             break;
         }
 
-        p_samples = dts_samples( p_sys->p_libdts );
+        p_samples = dca_samples( p_sys->p_libdca );
 
-        if ( (p_sys->i_flags & DTS_CHANNEL_MASK) == DTS_MONO
+        if ( (p_sys->i_flags & DCA_CHANNEL_MASK) == DCA_MONO
               && (p_filter->output.i_physical_channels 
                    & (AOUT_CHAN_LEFT | AOUT_CHAN_RIGHT)) )
         {
@@ -373,7 +373,7 @@
     aout_filter_t *p_filter = (aout_filter_t *)p_this;
     filter_sys_t *p_sys = (filter_sys_t *)p_filter->p_sys;
 
-    dts_free( p_sys->p_libdts );
+    dca_free( p_sys->p_libdca );
     free( p_sys );
 }
 
@@ -427,7 +427,7 @@
     filter_t *p_filter = (filter_t *)p_this;
     filter_sys_t *p_sys = p_filter->p_sys;
 
-    dts_free( p_sys->p_libdts );
+    dca_free( p_sys->p_libdca );
     free( p_sys );
 }
 
