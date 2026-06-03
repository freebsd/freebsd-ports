--- src/Clip.cpp.orig	2026-04-02 23:34:37 UTC
+++ src/Clip.cpp
@@ -1441,6 +1441,7 @@ QSize Clip::scale_size(QSize source_size, ScaleType so
             source_size.scale(target_width, target_height, Qt::KeepAspectRatioByExpanding);;
             break;
         }
+        default: ;
     }
 
     return source_size;
