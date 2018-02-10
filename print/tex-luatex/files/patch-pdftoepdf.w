--- luatexdir/image/pdftoepdf.w.orig	2018-01-31 15:17:41 UTC
+++ luatexdir/image/pdftoepdf.w
@@ -70,8 +70,14 @@ static char *get_file_checksum(char *a, 
         if (ck == NULL)
             luatex_fail("PDF inclusion: out of memory while processing '%s'",
                         a);
-        snprintf(ck, PDF_CHECKSUM_SIZE, "%" PRIu64 "_%" PRIu64, (uint64_t) size,
-                 (uint64_t) mtime);
+       // snprintf(ck, PDF_CHECKSUM_SIZE, "%" PRIu64 "_%" PRIu64, (uint64_t) size,
+       //          (uint64_t) mtime);
+	        snprintf(ck, PDF_CHECKSUM_SIZE, "%"
+		PRIu64
+		"_%"
+		PRIu64,
+		(uint64_t) size,
+		(uint64_t) mtime);
    } else {
         switch (fe) {
         case FE_FAIL:
