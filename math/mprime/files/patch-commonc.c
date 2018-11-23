--- commonc.c.orig	2016-09-14 03:33:00 UTC
+++ commonc.c
@@ -3247,13 +3247,13 @@ void tempFileName (
 /* From now on, we will use k and c to generate the filename.  To reduce */
 /* upgrading problems, old save file names are renamed. */
 
-	if (w->k != 1.0 || abs(w->c) != 1) {
+	if (w->k != 1.0 || labs(w->c) != 1) {
 		char	v258_filename[32];
 		strcpy (v258_filename, buf);
 		buf[1] = 0;
 		if (w->k != 1.0) sprintf (buf+strlen(buf), "%g", fmod (w->k, 1000000.0));
 		sprintf (buf+strlen(buf), "_%ld", p);
-		if (abs(w->c) != 1) sprintf (buf+strlen(buf), "_%d", abs(w->c) % 1000);
+		if (labs(w->c) != 1) sprintf (buf+strlen(buf), "_%ld", labs(w->c) % 1000);
 		rename (v258_filename, buf);
 		if (buf[0] == 'p') {
 			v258_filename[0] = buf[0] = 'q';
