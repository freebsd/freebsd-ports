diff -ur ../NuppelVideo-0.52a/rtjpeg_plugin.c ./rtjpeg_plugin.c
--- ../NuppelVideo-0.52a/rtjpeg_plugin.c	Tue Jul  3 15:34:02 2001
+++ ./rtjpeg_plugin.c	Mon Feb 10 18:42:01 2003
@@ -155,7 +155,7 @@
   while (pos > startpos && !foundit) {
     lseek(rtjpeg_file, pos, SEEK_SET);
     read(rtjpeg_file, buffer, 32768);
-    needlepos = (char *)memmem(buffer, 32768, "RTjjjjjjjjjjjjjjjjjjjjjjjj", FRAMEHEADERSIZE);
+//    needlepos = (char *)memmem(buffer, 32768, "RTjjjjjjjjjjjjjjjjjjjjjjjj", FRAMEHEADERSIZE);
     if (needlepos != NULL) {
       lseek(rtjpeg_file, pos+(needlepos - buffer) + FRAMEHEADERSIZE, SEEK_SET);
       read(rtjpeg_file, &frameheader, FRAMEHEADERSIZE);
@@ -273,7 +273,7 @@
       lseek(rtjpeg_file, pos, SEEK_SET);
       read(rtjpeg_file, buffer, 32768);
       //fprintf(stderr, "check for needle\n");
-      needlepos = (char *)memmem(buffer, 32768, "RTjjjjjjjjjjjjjjjjjjjjjjjj", FRAMEHEADERSIZE);
+//      needlepos = (char *)memmem(buffer, 32768, "RTjjjjjjjjjjjjjjjjjjjjjjjj", FRAMEHEADERSIZE);
       if (needlepos != NULL) {
         lseek(rtjpeg_file, pos+(needlepos - buffer) + FRAMEHEADERSIZE, SEEK_SET);
         read(rtjpeg_file, &frameheader, FRAMEHEADERSIZE);
