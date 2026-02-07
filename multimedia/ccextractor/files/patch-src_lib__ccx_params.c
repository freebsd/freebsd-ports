--- src/lib_ccx/params.c.orig	2026-01-20 10:01:34 UTC
+++ src/lib_ccx/params.c
@@ -10,7 +10,7 @@
 #include "ccx_common_common.h"
 #include "ccx_decoders_708.h"
 #include "compile_info.h"
-#include "../lib_hash/sha2.h"
+#include <sha256.h>
 #include <string.h>
 #include <stdio.h>
 #if __has_include(<utf8proc.h>)
@@ -34,8 +34,8 @@
 #define DEFAULT_FONT_PATH "/System/Library/Fonts/Helvetica.ttc"
 #define DEFAULT_FONT_PATH_ITALICS "/System/Library/Fonts/Helvetica-Oblique.ttf"
 #else // Assume Linux
-#define DEFAULT_FONT_PATH "/usr/share/fonts/truetype/noto/NotoSans-Regular.ttf"
-#define DEFAULT_FONT_PATH_ITALICS "/usr/share/fonts/truetype/noto/NotoSans-Italic.ttf"
+#define DEFAULT_FONT_PATH "%%LOCALBASE%%/share/fonts/noto/NotoSans-Regular.ttf"
+#define DEFAULT_FONT_PATH_ITALICS "%%LOCALBASE%%/share/fonts/noto/NotoSans-Italic.ttf"
 #endif
 
 extern void ccxr_init_logger();
@@ -735,7 +735,7 @@ char *calculateSHA256(char *location)
 	int size_read, bytes_read, fh = 0;
 	SHA256_CTX ctx256;
 
-	CC_SHA256_Init(&ctx256);
+	SHA256_Init(&ctx256);
 
 #ifdef _WIN32
 	fh = OPEN(location, O_RDONLY | O_BINARY);
@@ -751,7 +751,7 @@ char *calculateSHA256(char *location)
 	while ((bytes_read = read(fh, sha256_buf, 16384)) > 0)
 	{
 		size_read += bytes_read;
-		CC_SHA256_Update(&ctx256, (unsigned char *)sha256_buf, bytes_read);
+		SHA256_Update(&ctx256, (unsigned char *)sha256_buf, bytes_read);
 	}
 	close(fh);
 	SHA256_End(&ctx256, sha256_buf);
