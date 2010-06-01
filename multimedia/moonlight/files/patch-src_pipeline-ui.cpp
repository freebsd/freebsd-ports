
$FreeBSD$

--- src/pipeline-ui.cpp.orig
+++ src/pipeline-ui.cpp
@@ -310,7 +310,7 @@
 		if (env_url != NULL)
 			dl->Open ("GET", env_url, NoPolicy);
 		else
-			dl->Open ("GET", CODEC_URL, NoPolicy);
+			dl->Open ("GET", "", NoPolicy);
 		
 		dl->Send ();
 
