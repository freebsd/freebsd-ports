--- src/vmod_awsrest.c.orig	2016-10-26 23:24:27 UTC
+++ src/vmod_awsrest.c
@@ -116,8 +116,8 @@ void vmod_v4_generic(const struct vrt_ct
 	
 	////////////////
 	//get data
-	char *method;
-	char *requrl;
+	const char *method;
+	const char *requrl;
 	struct http *hp;
 	struct gethdr_s gs;
 	
