--- ./xbmc/MusicInfoTagLoaderWMA.cpp.orig	2009-10-12 11:16:56.000000000 +0200
+++ ./xbmc/MusicInfoTagLoaderWMA.cpp	2010-12-01 12:17:34.239816992 +0100
@@ -538,7 +538,7 @@
                                 "Unable to create album art for %s "
                                 "(extension=%s, size=%u)",
                       tag.GetURL().c_str(), strExtension.c_str(),
-                      picture.dwDataLen);
+                      (unsigned int)picture.dwDataLen);
           }
         }
       }
