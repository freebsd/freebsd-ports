--- player/src/codec/mp3/mp3_file.cpp.orig      Wed Sep 29 00:24:31 2004
+++ player/src/codec/mp3/mp3_file.cpp   Wed Sep 29 00:28:47 2004
@@ -126,6 +126,7 @@
     descptr[1] = strdup(desc);
     CHECK_AND_FREE(ret);
   }
+  ret = ID3_v1_genre_description[NULL];
   ret = ID3_GetAlbum(&myTag);
   if (ret) {

