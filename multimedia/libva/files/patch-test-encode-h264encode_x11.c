--- test/encode/h264encode_x11.c~
+++ test/encode/h264encode_x11.c
@@ -93,7 +93,7 @@ static int display_surface(int frame_id,
         }	
     }	
 
-    return;
+    return 0;
 }
 
 #include "h264encode_common.c"
