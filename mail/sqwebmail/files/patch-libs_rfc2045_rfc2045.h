--- libs/rfc2045/rfc2045.h.orig	2025-10-06 09:00:04 UTC
+++ libs/rfc2045/rfc2045.h
@@ -3224,7 +3224,7 @@ void rfc822::mime_decoder<out_iter, src_type>::decode(
 
 	if (decode_header)
 	{
-		typename rfc2045::entity::line_iter<crlf>::headers<
+		typename rfc2045::entity::line_iter<crlf>::template headers<
 			src_type> parser{e, src	};
 
 		parser.name_lc=header_name_lc;
