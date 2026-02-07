--- lib/driver/cdio_private.h.orig	2025-12-23 15:00:13 UTC
+++ lib/driver/cdio_private.h
@@ -572,10 +572,6 @@ extern "C" {
   bool cdio_have_aix    (void);
 
   /*! DEPRECATED: use cdio_have_driver().
-    True if BSDI driver is available. */
-  bool cdio_have_bsdi    (void);
-
-  /*! DEPRECATED: use cdio_have_driver().
     True if FreeBSD driver is available. */
   bool cdio_have_freebsd (void);
 
