--- lib/eject.c.orig	2009-06-27 21:37:27.000000000 +0900
+++ lib/eject.c	2012-09-11 05:14:03.000000000 +0900
@@ -110,7 +110,7 @@
       sts = cdio_close_tray(opts->device, NULL);
     }
   } else
-    sts = mmc_start_stop_media((CdIo_t*)opts->cdio, opts->eject, 0, 0);
+    sts = mmc_start_stop_unit((CdIo_t*)opts->cdio, opts->eject, 0, 0, 0);
 #elif defined(__APPLE__)
   driver_return_code_t sts;
   if ( opts->eject )
@@ -121,7 +121,7 @@
     sts = cdio_close_tray(opts->device, NULL);
   }
 #else
-  driver_return_code_t sts = mmc_start_stop_media((CdIo_t*)opts->cdio, opts->eject, 0, 0);
+  driver_return_code_t sts = mmc_start_stop_unit((CdIo_t*)opts->cdio, opts->eject, 0, 0, 0);
 #endif
 	
   return unieject_status(sts);
