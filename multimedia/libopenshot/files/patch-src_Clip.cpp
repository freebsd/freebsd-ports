--- src/Clip.cpp.orig	2026-07-22 19:42:15 UTC
+++ src/Clip.cpp
@@ -1535,6 +1535,7 @@ QSize Clip::scale_size(QSize source_size, ScaleType so
             source_size.scale(target_width, target_height, Qt::KeepAspectRatioByExpanding);;
             break;
         }
+        default: ;
     }
 
     return source_size;
