--- embed/ephy-web-view.c.orig	2009-10-13 15:30:12.000000000 +0200
+++ embed/ephy-web-view.c	2009-10-13 15:30:52.000000000 +0200
@@ -1129,7 +1129,10 @@ ephy_web_view_load_url (EphyWebView *vie
   else
     effective_url = ephy_embed_utils_normalize_address (url);
 
-  webkit_web_view_open (WEBKIT_WEB_VIEW (view), effective_url);
+  if (g_str_has_prefix (effective_url, "javascript:"))  
+    webkit_web_view_execute_script (WEBKIT_WEB_VIEW (view), effective_url);
+  else
+    webkit_web_view_open (WEBKIT_WEB_VIEW (view), effective_url);
 
   if (soup_uri)
     soup_uri_free (soup_uri);
