--- src/check.c.orig	Thu Feb  3 17:10:35 2005
+++ src/check.c	Thu Feb  3 17:27:11 2005
@@ -1121,8 +1121,8 @@
 uc_check_link_already_checked_with_insert (UCLinkProperties * prop,
 					   gchar * url)
 {
-  UCLinkProperties *prop_tmp = NULL;
   gboolean already_checked = FALSE;
+  UCLinkProperties *prop_tmp = NULL;
 
   prop_tmp = uc_check_link_already_checked (url);
 
@@ -2107,16 +2107,18 @@
 			      UCHTMLTag * tag, UCLinkProperties * old_prop,
 			      gboolean * accept, guint retry)
 {
+  gboolean already_checked = FALSE;
+  gboolean cancel = FALSE;
+  gboolean blocked_domain = FALSE;
+  gboolean no_check = FALSE;
   UCLinkProperties *prop = NULL;
+  UCHTTPCheckReturn ret;
   UCStatusCode *sc = NULL;
   gchar *protocol = NULL;
   gchar *hostname = NULL;
   protocol = NULL;
-  gboolean cancel = FALSE;
-  gboolean blocked_domain = FALSE;
-  gboolean already_checked = FALSE;
-  gboolean no_check = FALSE;
-  UCHTTPCheckReturn ret = UC_HTTP_CHECK_RETURN_OK;
+
+  ret = UC_HTTP_CHECK_RETURN_OK;
 
   protocol = uc_url_get_protocol (tag->value);
   if (uc_check_protocol_accepted (protocol))
