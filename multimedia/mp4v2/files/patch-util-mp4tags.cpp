--- util/mp4tags.cpp.orig	2012-05-20 22:11:55 UTC
+++ util/mp4tags.cpp
@@ -539,6 +539,7 @@ extern "C" int
                         else {
                             fprintf( stderr, "Art file %s not found\n", tags[i] );
                         }
+                        break;
                     }
                     case OPT_ALBUM_ARTIST:
                         MP4TagsSetAlbumArtist( mdata, tags[i] );
