--- src/wrapper.c.orig	2015-10-23 07:16:10 UTC
+++ src/wrapper.c
@@ -176,8 +176,8 @@ main (int argc, char *argv[])
 
 	int total_read = 0;
 	int total_read_cache = 0;
-	char *page_raw;      //2ページ分のバッファ
-	char *page_raw_cache;//2ページ分のキャッシュ
+	char *page_raw = NULL;      //2ページ分のバッファ
+	char *page_raw_cache = NULL;//2ページ分のキャッシュ
 
 	static BOOL first_fwrite = TRUE;
 	static BOOL cache_exist = FALSE;
