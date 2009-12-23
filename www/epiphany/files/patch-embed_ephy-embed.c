From 009be331694b442dd859f49c7f02bdef498621ff Mon Sep 17 00:00:00 2001
From: Gustavo Noronha Silva <gns@gnome.org>
Date: Sun, 25 Oct 2009 20:22:46 +0000
Subject: Reimplement content type checking

This brings back proper content type reporting, and the 'Open' button
in the download dialog.

Bug #598167
---

--- embed/ephy-embed.c.orig	2009-10-17 23:11:58.000000000 +0200
+++ embed/ephy-embed.c	2009-11-02 12:56:33.000000000 +0100
@@ -645,27 +645,38 @@ confirm_action_from_mime (WebKitWebView 
   GAppInfo *helper_app;
   const char *suggested_filename;
   int default_response;
+  WebKitNetworkResponse *response;
+  SoupMessage *message;
 
   parent_window = gtk_widget_get_toplevel (GTK_WIDGET(web_view));
   if (!GTK_WIDGET_TOPLEVEL (parent_window))
     parent_window = NULL;
 
-  /* FIXME: we still have no way of getting the content type from
-   * webkit yet; we need to have a proper WebKitNetworkRequest
-   * implementation to do this here; see
-   * https://bugs.webkit.org/show_bug.cgi?id=18608
-   */
   helper_app = NULL;
   mime_description = NULL;
   mime_permission = EPHY_MIME_PERMISSION_SAFE;
+
+  response = webkit_download_get_network_response (download);
+  message = webkit_network_response_get_message (response);
+
+  if (message) {
+    const char *content_type = soup_message_headers_get_content_type (message->response_headers, NULL);
+
+    if (content_type) {
+      mime_description = g_content_type_get_description (content_type);
+      helper_app = g_app_info_get_default_for_type (content_type, FALSE);
+
+      if (helper_app) {
+        action = DOWNLOAD_ACTION_OPEN;
+      }
+    }
+  }
+
   if (mime_description == NULL) {
     mime_description = g_strdup (C_("file type", "Unknown"));
     action = DOWNLOAD_ACTION_OPEN_LOCATION;
   }
 
-  /* OPEN will never happen here, for now; see comment about
-   * WebKitNetworkRequest above!
-   */
   action_label = (action == DOWNLOAD_ACTION_OPEN) ? GTK_STOCK_OPEN : STOCK_DOWNLOAD;
   suggested_filename = webkit_download_get_suggested_filename (download);
 
@@ -757,11 +768,6 @@ download_status_changed_cb (GObject *obj
     return;
   }
 
-  /* FIXME: when we are able to obtain the MIME information from
-   * WebKit, we will want to decide earlier whether we want to open or
-   * open the location to where the file was downloaded. See
-   * perform_auto_download, too.
-   */
   g_object_ref (download); /* balanced in confirm_action_response_cb */
   confirm_action_from_mime (web_view, download, DOWNLOAD_ACTION_DOWNLOAD);
 }
