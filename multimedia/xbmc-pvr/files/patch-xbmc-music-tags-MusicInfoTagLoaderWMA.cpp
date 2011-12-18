--- xbmc/music/tags/MusicInfoTagLoaderWMA.cpp.orig
+++ xbmc/music/tags/MusicInfoTagLoaderWMA.cpp
@@ -538,7 +538,7 @@
                                 "Unable to create album art for %s "
                                 "(extension=%s, size=%u)",
                       tag.GetURL().c_str(), strExtension.c_str(),
-                      picture.dwDataLen);
+                      (unsigned int)picture.dwDataLen);
           }
         }
       }
