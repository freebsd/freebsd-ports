--- writecap/pcapio.c.orig	2025-10-10 21:38:23 UTC
+++ writecap/pcapio.c
@@ -438,7 +438,7 @@ write_to_file(pcapio_writer* pfile, const uint8_t* dat
         default:
             nwritten = fwrite(data, data_length, 1, pfile->fh);
             if (nwritten != 1) {
-                if (ferror(pfile->fh)) {
+                if (ferror((FILE*) pfile->fh)) {
                     *err = errno;
                 } else {
                     *err = WTAP_ERR_SHORT_WRITE;
