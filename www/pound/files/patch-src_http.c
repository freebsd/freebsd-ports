--- src/http.c.orig	2024-08-20 06:46:04 UTC
+++ src/http.c
@@ -241,6 +241,14 @@ isws (int c)
 {
   return c == ' ' || c == '\t';
 }
+
+static char const *
+trimwsl (char const *s)
+{
+  while (*s && isws (*s))
+    s++;
+  return s;
+}
 
 static int
 submatch_realloc (struct submatch *sm, GENPAT re)
@@ -1162,7 +1170,7 @@ get_line (BIO *in, char *const buf, int bufsize)
       case 0:
 	if (BIO_should_retry (in))
 	  continue;
-	return COPY_EOF;
+	return i == 0 ? COPY_EOF : COPY_OK;
       case -1:
 	return COPY_READ_ERR;
       default:
@@ -1312,15 +1320,11 @@ get_content_length (char const *arg, int mode)
   CONTENT_LENGTH n;
 
   if (mode == CL_HEADER)
-    {
-      while (isws (*arg))
-	arg++;
-    }
+    arg = trimwsl (arg);
 
   if (strtoclen (arg, mode == CL_HEADER ? 10 : 16, &n, &p))
     return NO_CONTENT_LENGTH;
-  while (isws (*p))
-    p++;
+  p = (char*) trimwsl (p);
   if (*p)
     {
       if (!(mode == CL_CHUNK && *p == ';'))
@@ -3219,6 +3223,30 @@ static int
 }
 
 static int
+set_header_from_bio (BIO *bio, struct http_request *req,
+		     char const *hdr, struct stringbuf *sb)
+{
+  char buf[MAXBUF];
+  int rc;
+  char *str;
+
+  if ((rc = get_line (bio, buf, sizeof (buf))) == COPY_OK)
+    {
+      stringbuf_reset (sb);
+      stringbuf_printf (sb, "%s: %s", hdr, trimwsl (buf));
+      if ((str = stringbuf_finish (sb)) == NULL
+	  || http_header_list_append (&req->headers, str, H_REPLACE))
+	{
+	  return -1;
+	}
+    }
+  else if (rc != COPY_EOF)
+    logmsg (LOG_ERR, "(%"PRItid") error reading data: %s",
+	    POUND_TID (), copy_status_string (rc));
+  return 0;
+}
+
+static int
 add_ssl_headers (POUND_HTTP *phttp)
 {
   int res = 0;
@@ -3248,72 +3276,40 @@ add_ssl_headers (POUND_HTTP *phttp)
   if (phttp->lstn->clnt_check > 0 && phttp->x509 != NULL
       && (bio = BIO_new (BIO_s_mem ())) != NULL)
     {
+      int i;
+
+      BIO_set_mem_eof_return (bio, 0);
       X509_NAME_print_ex (bio, X509_get_subject_name (phttp->x509), 8,
 			  XN_FLAG_ONELINE & ~ASN1_STRFLGS_ESC_MSB);
-      if (get_line (bio, buf, sizeof (buf)) != COPY_OK)
+      if (set_header_from_bio (bio, &phttp->request, "X-SSL-Subject", &sb))
 	{
 	  res = -1;
 	  goto end;
 	}
 
-      stringbuf_printf (&sb, "X-SSL-Subject: %s", buf);
-      if ((str = stringbuf_finish (&sb)) == NULL
-	  || http_header_list_append (&phttp->request.headers, str, H_REPLACE))
-	{
-	  res = -1;
-	  goto end;
-	}
-      stringbuf_reset (&sb);
-
       X509_NAME_print_ex (bio, X509_get_issuer_name (phttp->x509), 8,
 			  XN_FLAG_ONELINE & ~ASN1_STRFLGS_ESC_MSB);
-      if (get_line (bio, buf, sizeof (buf)) != COPY_OK)
+      if (set_header_from_bio (bio, &phttp->request, "X-SSL-Issuer", &sb))
 	{
 	  res = -1;
 	  goto end;
 	}
 
-      stringbuf_printf (&sb, "X-SSL-Issuer: %s", buf);
-      if ((str = stringbuf_finish (&sb)) == NULL
-	  || http_header_list_append (&phttp->request.headers, str, H_REPLACE))
-	{
-	  res = -1;
-	  goto end;
-	}
-      stringbuf_reset (&sb);
-
       ASN1_TIME_print (bio, X509_get_notBefore (phttp->x509));
-      if (get_line (bio, buf, sizeof (buf)) != COPY_OK)
+      if (set_header_from_bio (bio, &phttp->request, "X-SSL-notBefore", &sb))
 	{
 	  res = -1;
 	  goto end;
 	}
 
-      stringbuf_printf (&sb, "X-SSL-notBefore: %s", buf);
-      if ((str = stringbuf_finish (&sb)) == NULL
-	  || http_header_list_append (&phttp->request.headers, str, H_REPLACE))
-	{
-	  res = -1;
-	  goto end;
-	}
-      stringbuf_reset (&sb);
-
       ASN1_TIME_print (bio, X509_get_notAfter (phttp->x509));
-      if (get_line (bio, buf, sizeof (buf)) != COPY_OK)
+      if (set_header_from_bio (bio, &phttp->request, "X-SSL-notAfter", &sb))
 	{
 	  res = -1;
 	  goto end;
 	}
 
-      stringbuf_printf (&sb, "X-SSL-notAfter: %s", buf);
-      if ((str = stringbuf_finish (&sb)) == NULL
-	  || http_header_list_append (&phttp->request.headers, str, H_REPLACE))
-	{
-	  res = -1;
-	  goto end;
-	}
       stringbuf_reset (&sb);
-
       stringbuf_printf (&sb, "X-SSL-serial: %ld",
 			ASN1_INTEGER_get (X509_get_serialNumber (phttp->x509)));
       if ((str = stringbuf_finish (&sb)) == NULL
@@ -3326,9 +3322,13 @@ add_ssl_headers (POUND_HTTP *phttp)
 
       PEM_write_bio_X509 (bio, phttp->x509);
       stringbuf_add_string (&sb, "X-SSL-certificate: ");
+      i = 0;
       while (get_line (bio, buf, sizeof (buf)) == COPY_OK)
 	{
+	  if (i > 0)
+	    stringbuf_add_string (&sb, "\r\n\t");
 	  stringbuf_add_string (&sb, buf);
+	  i++;
 	}
       if ((str = stringbuf_finish (&sb)) == NULL
 	  || http_header_list_append (&phttp->request.headers, str, H_REPLACE))
@@ -3580,7 +3580,7 @@ http_response_validate (struct http_request *req)
 static int
 http_response_validate (struct http_request *req)
 {
-  char *str = req->request;
+  char const *str = req->request;
   int http_ver;
 
   if (!(strncmp (str, "HTTP/1.", 7) == 0 &&
@@ -3589,9 +3589,7 @@ http_response_validate (struct http_request *req)
     return 0;
   req->version = http_ver - '0';
 
-  for (str += 8; isws (*str); str++)
-    if (!*str)
-      return 0;
+  str = trimwsl (str + 8);
 
   switch (str[0])
     {
