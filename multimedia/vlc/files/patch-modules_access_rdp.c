--- modules/access/rdp.c.orig	2016-07-22 12:10:45 UTC
+++ modules/access/rdp.c
@@ -45,18 +45,6 @@
 # include <freerdp/version.h>
 #endif
 
-#if !defined(FREERDP_VERSION_MAJOR) || \
-    (defined(FREERDP_VERSION_MAJOR) && !(FREERDP_VERSION_MAJOR > 1 || (FREERDP_VERSION_MAJOR == 1 && FREERDP_VERSION_MINOR >= 1)))
-# define SoftwareGdi sw_gdi
-# define Fullscreen fullscreen
-# define ServerHostname hostname
-# define Username username
-# define Password password
-# define ServerPort port
-# define EncryptionMethods encryption
-# define ContextSize context_size
-#endif
-
 #include <errno.h>
 #ifdef HAVE_POLL
 # include <poll.h>
@@ -140,6 +128,7 @@ static void desktopResizeHandler( rdpCon
     vlcrdp_context_t * p_vlccontext = (vlcrdp_context_t *) p_context;
     demux_sys_t *p_sys = p_vlccontext->p_demux->p_sys;
     rdpGdi *p_gdi = p_context->gdi;
+    unsigned bytesPerPixel;
 
     if ( p_sys->es )
     {
@@ -149,17 +138,21 @@ static void desktopResizeHandler( rdpCon
 
     /* Now init and fill es format */
     vlc_fourcc_t i_chroma;
-    switch( p_gdi->bytesPerPixel )
+    switch( p_gdi->dstFormat )
     {
         default:
-        case 16:
+            msg_Dbg( p_vlccontext->p_demux, "unhandled dstFormat %x bpp", p_gdi->dstFormat );
+        case PIXEL_FORMAT_BGR16:
             i_chroma = VLC_CODEC_RGB16;
+            bytesPerPixel = 16;
             break;
-        case 24:
+        case PIXEL_FORMAT_BGR24:
             i_chroma = VLC_CODEC_RGB24;
+            bytesPerPixel = 24;
             break;
-        case 32:
+        case PIXEL_FORMAT_BGRA32:
             i_chroma = VLC_CODEC_RGB32;
+            bytesPerPixel = 32;
             break;
     }
     es_format_t fmt;
@@ -172,7 +165,7 @@ static void desktopResizeHandler( rdpCon
     fmt.video.i_height = p_gdi->height;
     fmt.video.i_frame_rate_base = 1000;
     fmt.video.i_frame_rate = 1000 * p_sys->f_fps;
-    p_sys->i_framebuffersize = p_gdi->width * p_gdi->height * p_gdi->bytesPerPixel;
+    p_sys->i_framebuffersize = p_gdi->width * p_gdi->height * bytesPerPixel;
 
     if ( p_sys->p_block )
         p_sys->p_block = block_Realloc( p_sys->p_block, 0, p_sys->i_framebuffersize );
@@ -233,28 +226,19 @@ static bool postConnectHandler( freerdp 
     vlcrdp_context_t * p_vlccontext = (vlcrdp_context_t *) p_instance->context;
 
     msg_Dbg( p_vlccontext->p_demux, "connected to desktop %dx%d (%d bpp)",
-#if defined(FREERDP_VERSION_MAJOR) && (FREERDP_VERSION_MAJOR > 1 || (FREERDP_VERSION_MAJOR == 1 && FREERDP_VERSION_MINOR >= 1))
              p_instance->settings->DesktopWidth,
              p_instance->settings->DesktopHeight,
              p_instance->settings->ColorDepth
-#else
-             p_instance->settings->width,
-             p_instance->settings->height,
-             p_instance->settings->color_depth
-#endif
              );
 
     p_instance->update->DesktopResize = desktopResizeHandler;
     p_instance->update->BeginPaint = beginPaintHandler;
     p_instance->update->EndPaint = endPaintHandler;
 
-    gdi_init( p_instance,
-                CLRBUF_16BPP |
-#if defined(FREERDP_VERSION_MAJOR) && defined(FREERDP_VERSION_MINOR) && \
-    !(FREERDP_VERSION_MAJOR > 1 || (FREERDP_VERSION_MAJOR == 1 && FREERDP_VERSION_MINOR >= 2))
-                CLRBUF_24BPP |
-#endif
-                CLRBUF_32BPP, NULL );
+    if ( p_instance->settings->ColorDepth > 16 )
+        gdi_init( p_instance, PIXEL_FORMAT_XRGB32);
+    else
+        gdi_init( p_instance, PIXEL_FORMAT_RGB16);
 
     desktopResizeHandler( p_instance->context );
     return true;
@@ -428,10 +412,6 @@ static int Open( vlc_object_t *p_this )
     if ( p_sys->f_fps <= 0 ) p_sys->f_fps = 1.0;
     p_sys->i_frame_interval = 1000000 / p_sys->f_fps;
 
-#if FREERDP_VERSION_MAJOR == 1 && FREERDP_VERSION_MINOR < 2
-    freerdp_channels_global_init();
-#endif
-
     p_sys->p_instance = freerdp_new();
     if ( !p_sys->p_instance )
     {
@@ -506,9 +486,6 @@ static void Close( vlc_object_t *p_this 
 
     freerdp_disconnect( p_sys->p_instance );
     freerdp_free( p_sys->p_instance );
-#if FREERDP_VERSION_MAJOR == 1 && FREERDP_VERSION_MINOR < 2
-    freerdp_channels_global_uninit();
-#endif
 
     if ( p_sys->p_block )
         block_Release( p_sys->p_block );
