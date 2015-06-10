commit 130873c
Author: Aurélien Zanelli <aurelien.zanelli@darkosphere.fr>
Date:   Sat Nov 1 12:18:02 2014 +0100

    vpx: remove compatibility defines
    
    We are guaranteed to have VPX_IMG_FMT_I420, VPX_PLANE_Y,
    VPX_PLANE_U and VPX_PLANE_V as we require libvpx > 1.1.0.
    
    https://bugzilla.gnome.org/show_bug.cgi?id=739476
---
 ext/vpx/gstvp8utils.h | 17 -----------------
 1 file changed, 17 deletions(-)

--- ext/vp8/gstvp8utils.h.orig	2011-12-11 18:49:11 UTC
+++ ext/vp8/gstvp8utils.h
@@ -25,23 +25,6 @@
 
 G_BEGIN_DECLS
 
-/* Some compatibility defines for older libvpx versions */
-#ifndef VPX_IMG_FMT_I420
-#define VPX_IMG_FMT_I420 IMG_FMT_I420
-#endif
-
-#ifndef VPX_PLANE_Y
-#define VPX_PLANE_Y PLANE_Y
-#endif
-
-#ifndef VPX_PLANE_U
-#define VPX_PLANE_U PLANE_U
-#endif
-
-#ifndef VPX_PLANE_V
-#define VPX_PLANE_V PLANE_V
-#endif
-
 const char * gst_vpx_error_name (vpx_codec_err_t status);
 
 G_END_DECLS
