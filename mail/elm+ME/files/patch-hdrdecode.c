--- lib/hdrdecode.c	Sat Jul  9 18:03:15 2005
+++ lib/hdrdecode.c	Sun Sep 10 04:57:10 2006
@@ -173,9 +173,16 @@
     char *encoded = NULL;
     struct string *ret = NULL;
     charset_t set;
+	char *front, *end;
+	struct string *fstr, *estr;
 
-    if ('=' != *p++)
+	/* Pasear: front, end are used to solve buffer: abc""=?...?=" problem */
+	front = p;
+	while (*p && '=' != *p) ++p;
+	if (front != p && '=' == *p && '"' == *(p-1)) *(p-1) = '\0';
+    if ('=' != *p)
 	goto fail;
+	*p = '\0'; ++p;
     if ('?' != *p++)
 	goto fail;
     sn = p;
@@ -209,8 +216,8 @@
     p++;
     if ('=' != *p++)
 	goto fail;
-    if (*p)
-	goto fail;
+	if ('"' == *p) ++p;
+	end = p;
 
     set = MIME_name_to_charset(sn,CHARSET_create);
 
@@ -225,6 +232,18 @@
 	break;
     }
 
+	/* Pasear */
+	if (ret){
+		estr = ret;
+		fstr = new_string2(system_charset,us_str(front));
+		fstr = ret = cat_strings(fstr, ret, 0);
+		free_string(&estr);
+		estr = new_string2(system_charset,us_str(end));
+		ret = cat_strings(ret, estr, 0);
+		free_string(&estr);
+		free_string(&fstr);
+	}
+
  fail:
     if (!ret) {
 	DPRINT(Debug,20,(&Debug, 
@@ -341,20 +360,31 @@
     struct string * ret = new_string(defcharset);
     char **tokenized = rfc822_tokenize(buffer);
     unsigned char * last_char = NULL;
-    int i;
+    int i, encoded;
+	char* p;
 
     for (i = 0; tokenized[i]; i++) {
 
 	struct string * ok = NULL;
 	int nostore = 0;
 
+	/* Pasear: detect if it is a encoded string */
+	encoded = 0;
+	if ('"' == tokenized[i][0]){
+		p = tokenized[i];
+		while (*p && *p != '=') ++p;
+		if (*p && *p == '=' && *(p+1) && *(p+1) == '?' )
+			encoded = 1;
+	}
+
+
 	if ('(' == tokenized[i][0]) {
 	    /* we need add last space */
 	    if (last_char) 
 		add_ascii_to_string(ret,last_char);
 	    ok = hdr_comment(tokenized[i],defcharset,demime);
 	    nostore = 1;
-	} else if ('"' == tokenized[i][0]) {
+	} else if (!encoded && '"' == tokenized[i][0]) {
 	    /* we need add last space */
 	    if (last_char) 
 		add_ascii_to_string(ret,last_char);
