--- embed/ephy-embed-utils.c.orig	2009-10-13 15:28:59.000000000 +0200
+++ embed/ephy-embed-utils.c	2009-10-13 15:29:30.000000000 +0200
@@ -91,6 +91,7 @@ ephy_embed_utils_address_has_web_scheme 
 			  g_str_has_prefix (address, "file:") ||
 			  g_str_has_prefix (address, "data:") ||
 			  g_str_has_prefix (address, "about:") ||
+			  g_str_has_prefix (address, "javascript:") ||
 			  g_str_has_prefix (address, "gopher:"));
 
 	return has_web_scheme;
