https://bugs.webkit.org/show_bug.cgi?id=50173

--- Source/WebKit/gtk/webkit/webkitwebview.cpp.orig	2011-06-14 02:10:55.000000000 +0200
+++ Source/WebKit/gtk/webkit/webkitwebview.cpp	2011-08-27 10:48:52.000000000 +0200
@@ -4939,6 +4939,8 @@
 
     priv->mainResource = adoptGRef(webResource);
     priv->mainResourceIdentifier = identifier;
+
+    g_object_ref(webView);
 }
 
 void webkit_web_view_add_resource(WebKitWebView* webView, const char* identifier, WebKitWebResource* webResource)
@@ -4955,6 +4957,8 @@
         priv->mainResource = 0;
     } else
       g_hash_table_remove(priv->subResources.get(), identifier);
+
+      g_object_unref(webView);
 }
 
 WebKitWebResource* webkit_web_view_get_resource(WebKitWebView* webView, char* identifier)
