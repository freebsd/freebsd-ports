--- src/wrapper.c.orig	2018-03-08 04:25:02 UTC
+++ src/wrapper.c
@@ -177,8 +177,8 @@ main (int argc, char *argv[])
 
 	int total_read = 0;
 	int total_read_cache = 0;
-	char *page_raw;      //2ページ分のバッファ
-	char *page_raw_cache;//2ページ分のキャッシュ
+	char *page_raw = NULL;      //2ページ分のバッファ
+	char *page_raw_cache = NULL;//2ページ分のキャッシュ
 
 	static BOOL first_fwrite = TRUE;
 	static BOOL cache_exist = FALSE;
