--- scan/sane/hpaio.c.orig	2019-10-22 06:25:58 UTC
+++ scan/sane/hpaio.c
@@ -419,7 +419,7 @@ extern void sane_hpaio_close(SANE_Handle handle)
     if (strcmp(*((char **)handle), "ESCL") == 0)
        return escl_close(handle);
     if (strcmp(*((char **)handle), "ORBLITE") == 0)
-       return orblite_close(handle);
+       orblite_close(handle);
 }  /* sane_hpaio_close() */
 
 extern const SANE_Option_Descriptor * sane_hpaio_get_option_descriptor(SANE_Handle handle, SANE_Int option)
@@ -552,7 +552,7 @@ extern void sane_hpaio_cancel( SANE_Handle handle )
     if (strcmp(*((char **)handle), "ESCL") == 0)
        return escl_cancel(handle);
     if (strcmp(*((char **)handle), "ORBLITE") == 0)
-       return orblite_cancel(handle);
+       orblite_cancel(handle);
 }  /* sane_hpaio_cancel() */
 
 extern SANE_Status sane_hpaio_set_io_mode(SANE_Handle handle, SANE_Bool nonBlocking)
