--- iiimgcf/imaux.c	Thu Jul 29 20:44:21 2004
+++ iiimgcf/imaux.c	Wed Feb 16 20:40:51 2005
@@ -36,7 +36,7 @@
 
 static void iiim_aux_download (IIIMCF_downloaded_object obj);
 
-#define AUX_BASE_DIR		"/usr/lib/im/"
+#define AUX_BASE_DIR		IMDIR
 
 #define IS_SPACE(len, ptr)	((0 < (len)) &&				\
 				 (('\t' == *(p)) || (' ' == *(p))))
