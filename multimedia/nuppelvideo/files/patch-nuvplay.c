diff -ur ../NuppelVideo-0.52a/nuvplay.c ./nuvplay.c
--- ../NuppelVideo-0.52a/nuvplay.c	Wed Jul  4 17:28:41 2001
+++ ./nuvplay.c	Mon Feb 10 18:38:06 2003
@@ -272,7 +272,7 @@
  if (rtjpeg_fileheader.audioblocks!=0 && playaudio!=0) {
    if (writeaudiotofile) {
      // write to file, file MUST NOT exist
-     audf = (writeaudiotofile==1) ? open(audiofilename, O_EXCL|O_CREAT|O_WRONLY|O_SYNC, 0600) : 1;
+     audf = (writeaudiotofile==1) ? open(audiofilename, O_EXCL|O_CREAT|O_WRONLY|O_FSYNC, 0600) : 1;
      if (audf==-1) {
        if (errno!=EEXIST)
          fprintf(stderr, "cannot write to file '%s', no audio is played\n", audiofilename);
