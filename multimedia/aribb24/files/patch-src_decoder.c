https://github.com/scimmia9286/aribb24/commit/fa54dee41aa38560f02868b24f911a24c33780a8
--- src/decoder.c.orig	2019-09-16 15:57:19 UTC
+++ src/decoder.c
@@ -82,6 +82,7 @@ struct arib_decoder_t
     int (*handle_g2)(arib_decoder_t *, int);
     int (*handle_g3)(arib_decoder_t *, int);
     int kanji_ku;
+    int drcs_plane;
 
     int i_control_time;
 
@@ -448,11 +449,8 @@ static int decoder_handle_drcs( arib_decoder_t *decode
 {
     unsigned int uc;
 
-    uc = 0;
-    if( c < decoder->p_instance->p->i_drcs_num )
-    {
-        uc = decoder->p_instance->p->drcs_conv_table[c];
-    }
+    uc = decoder->p_instance->p->drcs_conv_table[decoder->drcs_plane-1][c];
+
     if( uc == 0 )
     {
         /* uc = 0x3000; */ /* WHITESPACE */
@@ -555,6 +553,7 @@ static int decoder_handle_esc( arib_decoder_t *decoder
 {
     int c;
     int (**handle)(arib_decoder_t *, int);
+    int drcs = 0;
 
     handle = &decoder->handle_g0;
     while( decoder_pull( decoder, &c ) != 0 )
@@ -562,6 +561,7 @@ static int decoder_handle_esc( arib_decoder_t *decoder
         switch( c )
         {
             case 0x20: // DRCS
+	    	drcs = 1;
                 break;
             case 0x24:
             case 0x28:
@@ -585,12 +585,29 @@ static int decoder_handle_esc( arib_decoder_t *decoder
                 return 1;
             case 0x39:
             case 0x3b:
-            case 0x42:
                 *handle = decoder_handle_kanji;
                 return 1;
+	    case 0x42:
+	    	if (drcs==1)
+		{
+			decoder->drcs_plane = c-0x40;
+			*handle = decoder_handle_drcs;
+		}
+		else
+		{
+			*handle = decoder_handle_kanji;
+		}
             case 0x36:
             case 0x4a:
-                *handle = decoder_handle_alnum;
+	    	if (drcs==1)
+		{
+			decoder->drcs_plane = c-0x40;
+			*handle = decoder_handle_drcs;
+		}
+		else
+		{
+			*handle = decoder_handle_alnum;
+		}
                 return 1;
             case 0x40:
             case 0x41:
@@ -608,6 +625,7 @@ static int decoder_handle_esc( arib_decoder_t *decoder
             case 0x4d:
             case 0x4e:
             case 0x4f:
+	    	decoder->drcs_plane = c-0x40;
                 *handle = decoder_handle_drcs;
                 return 1;
             case 0x6e: //LS2
@@ -1401,6 +1419,7 @@ void arib_initialize_decoder( arib_decoder_t* decoder 
     decoder->handle_g2 = decoder_handle_hiragana;
     decoder->handle_g3 = decoder_handle_katakana;
     decoder->kanji_ku = -1;
+    decoder->drcs_plane = -1;
 
     decoder->i_control_time = 0;
 
