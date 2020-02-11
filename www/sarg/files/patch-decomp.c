--- decomp.c.orig	2020-02-11 12:34:30 UTC
+++ decomp.c
@@ -486,7 +486,7 @@ FileObject *decomp(const char *arq)
 	ssize_t nread;
 
 	// guess file type
-	fd=open(arq,O_RDONLY | O_LARGEFILE);
+	fd=open(arq,O_RDONLY);
 	if (fd==-1) {
 		debuga(__FILE__,__LINE__,_("Cannot open file \"%s\": %s\n"),arq,strerror(errno));
 		exit(EXIT_FAILURE);
