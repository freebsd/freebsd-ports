--- src/protocols/yahoo/yahoo.c.orig	Sat Jan 10 07:04:09 2004
+++ src/protocols/yahoo/yahoo.c	Fri Feb  6 11:43:13 2004
@@ -131,8 +131,15 @@
 		while (pos + 1 < len) {
 			if (data[pos] == 0xc0 && data[pos + 1] == 0x80)
 				break;
+			if (x >= sizeof(key)-1) {
+				x++;
+				continue;
+			}
 			key[x++] = data[pos++];
 		}
+		if (x >= sizeof(key)-1) {
+			x = 0;
+		}
 		key[x] = 0;
 		pos += 2;
 		pair->key = strtol(key, NULL, 10);
@@ -873,13 +880,17 @@
 static char *yahoo_decode(const char *text)
 {
 	char *converted;
-	char *p, *n, *new;
-	
+	char *n, *new;
+	const char *end, *p;
+	int i;
+
 	n = new = g_malloc(strlen (text) + 1);
+	end = text + strlen(text);
 
-	for (p = (char *)text; *p; p++, n++) {
+	for (p = text; p < end; p++, n++) {
 		if (*p == '\\') {
-			sscanf(p + 1, "%3o\n", (int *)n);
+			sscanf(p + 1, "%3o\n", &i);
+			*n = i;
 			p += 3;
 		}
 		else
@@ -887,7 +898,7 @@
 	}
 
 	*n = '\0';
-	
+
 	converted = g_convert(new, n - new, OUT_CHARSET, "iso-8859-1", NULL, NULL, NULL);
 	g_free(new);
 
@@ -1906,29 +1917,29 @@
 	GaimConnection *gc = data;
 	GaimAccount *account = gaim_connection_get_account(gc);
 	struct yahoo_data *yd = gc->proto_data;
-	char buf[1024], buf2[256], *i = buf, *r = buf2;
-	int len, o = 0;
+	char buf[1024], *i = buf;
+	int len;
+	GString *s;
 
-	len = read(source, buf, sizeof(buf));
-	if (len <= 0  || strncmp(buf, "HTTP/1.0 302", strlen("HTTP/1.0 302"))) {
+	len = read(source, buf, sizeof(buf)-1);
+	if (len <= 0  || (strncmp(buf, "HTTP/1.0 302", strlen("HTTP/1.0 302") &&
+			  strncmp(buf, "HTTP/1.1 302", strlen("HTTP/1.1 302"))))) {
 		gaim_connection_error(gc, _("Unable to read"));
 		return;
 	}
-	
-	while ((i = strstr(i, "Set-Cookie: ")) && 0 < 2) {
-		i += strlen("Set-Cookie: "); 
-		for (;*i != ';'; r++, i++) {
-			*r = *i;
-		}
-		*r=';';
-		r++;
-		*r=' ';
-		r++;
-		o++;
-	}
-	/* Get rid of that "; " */
-	*(r-2) = '\0';
-	yd->auth = g_strdup(buf2);
+
+	s = g_string_sized_new(len);
+	buf[sizeof(buf)-1] = '\0';
+
+	while ((i = strstr(i, "Set-Cookie: "))) {
+		i += strlen("Set-Cookie: ");
+		for (;*i != ';'; i++)
+			g_string_append_c(s, *i);
+
+		g_string_append(s, "; ");
+	}
+
+	yd->auth = g_string_free(s, FALSE);
 	gaim_input_remove(gc->inpa);
 	close(source);
 	/* Now we have our cookies to login with.  I'll go get the milk. */
@@ -1974,15 +1985,17 @@
 	const char *c = buf;
 	char *d;
 	char name[64], value[64];
+	int count = sizeof(name)-1;
 	while ((c < (buf + len)) && (c = strstr(c, "<input "))) {
 		c = strstr(c, "name=\"") + strlen("name=\"");
-		for (d = name; *c!='"'; c++, d++) 
+		for (d = name; *c!='"' && count; c++, d++, count--) 
 			*d = *c;
 		*d = '\0';
+		count = sizeof(value)-1;
 		d = strstr(c, "value=\"") + strlen("value=\"");
 		if (strchr(c, '>') < d)
 			break;
-		for (c = d, d = value; *c!='"'; c++, d++)
+		for (c = d, d = value; *c!='"' && count; c++, d++, count--)
 			*d = *c;
 		*d = '\0';
 		g_hash_table_insert(hash, g_strdup(name), g_strdup(value));
@@ -2705,15 +2718,12 @@
 		return;
 	/* It seems to work better without this */
 
+	/* if (gc->account->perm_deny != 4)
+		return; */
+
+	if (!who || who[0] == '\0')
+		return;
 
-	/* 
-	 * if (gc->account->perm_deny != 4)
-	 *	return;
- 	 *
-	 * if (!who || who[0] == '\0')
-	 *		return;
-	 */
-    
 	pkt = yahoo_packet_new(YAHOO_SERVICE_IGNORECONTACT, YAHOO_STATUS_AVAILABLE, 0);
 	yahoo_packet_hash(pkt, 1, gaim_connection_get_display_name(gc));
 	yahoo_packet_hash(pkt, 7, who);
