--- modules/printbackends/cups/gtkcupsutils.c.orig	2007-09-30 18:40:09.000000000 -0400
+++ modules/printbackends/cups/gtkcupsutils.c	2007-09-30 18:40:45.000000000 -0400
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
