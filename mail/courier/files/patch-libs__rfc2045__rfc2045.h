--- libs/rfc2045/rfc2045.h.orig	2025-10-05 18:47:55.000000000 +0200
+++ libs/rfc2045/rfc2045.h	2025-10-24 13:26:29.985150000 +0200
@@ -3224,7 +3224,7 @@
 
 	if (decode_header)
 	{
-		typename rfc2045::entity::line_iter<crlf>::headers<
+		typename rfc2045::entity::line_iter<crlf>::template headers<
 			src_type> parser{e, src	};
 
 		parser.name_lc=header_name_lc;
