--- Input/mpg123/mpg123.c.orig	Sat Feb  7 18:21:05 2004
+++ Input/mpg123/mpg123.c	Sat Feb  7 18:23:32 2004
@@ -635,6 +635,7 @@
 				     gchar ** genre, guint * tracknum)
 {
     FILE *file;
+	int result_seek, result_read;
     struct id3v1tag_t id3v1tag;
     struct id3tag_t id3tag;
 
@@ -669,12 +670,12 @@
 	if (!id3) {
 
 
-	    int result_seek = fseek(file, -1 * sizeof(id3v1tag), SEEK_END);
+	    result_seek = fseek(file, -1 * sizeof(id3v1tag), SEEK_END);
 	    if (result_seek)
 		return;
 
 
-	    int result_read = fread(&id3v1tag, 1, sizeof(id3v1tag), file);
+	    result_read = fread(&id3v1tag, 1, sizeof(id3v1tag), file);
 	    if (result_read != sizeof(id3v1tag))
 		return;
 	    if (strncmp(id3v1tag.tag, "TAG", 3) != 0)
@@ -1111,6 +1112,8 @@
 
 static void play_file(char *filename)
 {
+	pthread_attr_t pta;
+
     memset(&fr, 0, sizeof(struct frame));
     memset(&temp_fr, 0, sizeof(struct frame));
 
@@ -1124,7 +1127,6 @@
     output_opened = FALSE;
     dopause = FALSE;
 
-    pthread_attr_t pta;
     (void) pthread_attr_init(&pta);
     (void) pthread_attr_setschedpolicy(&pta, PTHREAD_INHERIT_SCHED);
     (void) pthread_attr_setscope(&pta, PTHREAD_SCOPE_SYSTEM);
