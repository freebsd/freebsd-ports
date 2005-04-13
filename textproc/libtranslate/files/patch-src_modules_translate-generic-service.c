--- src/modules/translate-generic-service.c.orig	Mon Apr 11 23:08:47 2005
+++ src/modules/translate-generic-service.c	Mon Apr 11 23:15:54 2005
@@ -484,7 +484,7 @@
 
   if (SOUP_STATUS_IS_SUCCESSFUL(message->status_code))
     {
-      const char *charset = NULL;
+      char *charset = NULL;
       
       if (flags & TRANSFER_CONVERT)
 	{
@@ -493,14 +493,31 @@
 	  content_type = translate_generic_service_get_header(message, &info, "Content-Type");
 	  if (content_type)
 	    {
-	      charset = translate_ascii_strcasestr(content_type, "charset=");
-	      if (charset)
-		charset += 8;
+	      const char *tmp;
+	      
+	      tmp = translate_ascii_strcasestr(content_type, "charset=");
+	      if (tmp)
+		{
+		  int len;
+
+		  tmp += 8;
+		  if (*tmp == '\'' || *tmp == '"')
+		    tmp++;
+
+		  len = strlen(tmp);
+		  if (len > 0 && (tmp[len - 1] == '\'' || tmp[len - 1] == '"'))
+		    len--;
+
+		  charset = g_strndup(tmp, len);
+		}
 	    }
 	}
 
       if (charset)
-	response = g_convert(message->response.body, message->response.length, "UTF-8", charset, NULL, NULL, err);
+	{
+	  response = g_convert(message->response.body, message->response.length, "UTF-8", charset, NULL, NULL, err);
+	  g_free(charset);
+	}
       else
 	{
 	  if ((flags & TRANSFER_CONVERT) && ! g_utf8_validate(message->response.body, message->response.length, NULL))
