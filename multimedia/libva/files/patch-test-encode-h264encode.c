--- test/encode/h264encode.c~
+++ test/encode/h264encode.c
@@ -144,7 +144,7 @@ static int save_coded_buf(VABufferID cod
         printf("(SKipped)");
     printf("                                    ");
 
-    return;
+    return 0;
 }
 
 
@@ -188,7 +188,7 @@ static int display_surface(int frame_id,
         }	
     }	
 
-    return;
+    return 0;
 }
 
 enum {
