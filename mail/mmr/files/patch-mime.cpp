--- mime.cpp.orig	Fri Oct 25 13:55:40 2002
+++ mime.cpp	Fri Oct 25 13:56:15 2002
@@ -102,7 +102,7 @@
 
 /* The MIME_body class constructor */
 MIME_body:: MIME_body(IObottle *RawFile, char *endings[],
-						MIME_body *lineage = NULL)
+						MIME_body *lineage)
 {
 	MD5_CTX md5_ctx;
 	int i;
@@ -652,7 +652,7 @@
    length) to a new IO stream with SaveRaw(), or these changes will be lost.
  */
 int
-MIME_body:: AddPart(const char *file, int is_mime = 0)
+MIME_body:: AddPart(const char *file, int is_mime)
 {
 	MD5_CTX md5_ctx;
 	int (*EncodeFile)(FILE *, IObottle *);
