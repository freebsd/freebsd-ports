# Use the correct constants for this type
#
--- src/mga_dri.c.orig	2017-01-17 22:40:29 UTC
+++ src/mga_dri.c
@@ -316,7 +316,7 @@ static void MGAWaitForIdleDMA( ScrnInfoP
    for (;;) {
       do {
          /* first ask for quiescent and flush */
-         lock.flags = DRM_LOCK_QUIESCENT | DRM_LOCK_FLUSH;
+         lock.flags = _DRM_LOCK_QUIESCENT | _DRM_LOCK_FLUSH;
          do {
 	    ret = drmCommandWrite( pMga->drmFD, DRM_MGA_FLUSH,
                                    &lock, sizeof( drm_lock_t ) );
@@ -324,7 +324,7 @@ static void MGAWaitForIdleDMA( ScrnInfoP
 
          /* if it's still busy just try quiescent */
          if ( ret == -EBUSY ) { 
-            lock.flags = DRM_LOCK_QUIESCENT;
+            lock.flags = _DRM_LOCK_QUIESCENT;
             do {
 	       ret = drmCommandWrite( pMga->drmFD, DRM_MGA_FLUSH,
                                       &lock, sizeof( drm_lock_t ) );
