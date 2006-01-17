
$FreeBSD$

--- formats/format_g729.c.orig	Fri Jan 13 12:20:53 2006
+++ formats/format_g729.c	Fri Jan 13 12:23:33 2006
@@ -60,7 +60,7 @@ struct ast_filestream {
 	struct ast_frame fr;				/* Frame information */
 	char waste[AST_FRIENDLY_OFFSET];	/* Buffer for sending frames, etc */
 	char empty;							/* Empty character */
-	unsigned char g729[20];				/* Two Real G729 Frames */
+	unsigned char g729[10];				/* One Real G729 Frame */
 };
 
 
@@ -141,11 +141,11 @@ static struct ast_frame *g729_read(struc
 	s->fr.frametype = AST_FRAME_VOICE;
 	s->fr.subclass = AST_FORMAT_G729A;
 	s->fr.offset = AST_FRIENDLY_OFFSET;
-	s->fr.samples = 160;
-	s->fr.datalen = 20;
+	s->fr.samples = 80;
+	s->fr.datalen = 10;
 	s->fr.mallocd = 0;
 	s->fr.data = s->g729;
-	if ((res = fread(s->g729, 1, 20, s->f)) != 20) {
+	if ((res = fread(s->g729, 1, 10, s->f)) != 10) {
 		if (res && (res != 10))
 			ast_log(LOG_WARNING, "Short read (%d) (%s)!\n", res, strerror(errno));
 		return NULL;
@@ -190,7 +190,7 @@ static int g729_seek(struct ast_filestre
 	fseek(fs->f, 0, SEEK_END);
 	max = ftell(fs->f);
 	
-	bytes = 20 * (sample_offset / 160);
+	bytes = 10 * (sample_offset / 80);
 	if (whence == SEEK_SET)
 		offset = bytes;
 	else if (whence == SEEK_CUR || whence == SEEK_FORCECUR)
@@ -219,7 +219,7 @@ static long g729_tell(struct ast_filestr
 {
 	off_t offset;
 	offset = ftell(fs->f);
-	return (offset/20)*160;
+	return (offset/10)*80;
 }
 
 int load_module()
