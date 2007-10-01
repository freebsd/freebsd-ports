--- modules/printbackends/cups/gtkcupsutils.c.orig	2007-07-16 15:45:18.000000000 -0400
+++ modules/printbackends/cups/gtkcupsutils.c	2007-10-01 14:27:17.000000000 -0400
@@ -627,9 +627,7 @@ _post_send (GtkCupsRequest *request)
   httpClearFields(request->http);
   httpSetField(request->http, HTTP_FIELD_CONTENT_LENGTH, length);
   httpSetField(request->http, HTTP_FIELD_CONTENT_TYPE, "application/ipp");
-#ifdef HAVE_HTTP_AUTHSTRING
-  httpSetField(request->http, HTTP_FIELD_AUTHORIZATION, request->http->authstring);
-#endif
+  httpSetField (request->http, HTTP_FIELD_AUTHORIZATION, httpGetAuthString (request->http));
 
   if (httpPost(request->http, request->resource))
     {
@@ -966,9 +964,7 @@ _get_send (GtkCupsRequest *request)
     }
 
   httpClearFields(request->http);
-#ifdef HAVE_HTTP_AUTHSTRING
-  httpSetField(request->http, HTTP_FIELD_AUTHORIZATION, request->http->authstring);
-#endif
+  httpSetField(request->http, HTTP_FIELD_AUTHORIZATION, httpGetAuthString (request->http));
 
   if (httpGet(request->http, request->resource))
     {
