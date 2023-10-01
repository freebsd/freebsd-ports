--- lib/driver/cdio_private.h.orig	2018-08-12 16:33:48 UTC
+++ lib/driver/cdio_private.h
@@ -553,10 +553,6 @@ extern "C" {
   bool cdio_have_aix    (void);
 
   /*! DEPRICATED: use cdio_have_driver().
-    True if BSDI driver is available. */
-  bool cdio_have_bsdi    (void);
-
-  /*! DEPRICATED: use cdio_have_driver().
     True if FreeBSD driver is available. */
   bool cdio_have_freebsd (void);
 
