--- src/util.c.orig	Wed Mar 31 17:56:09 2004
+++ src/util.c	Sat Apr  3 00:18:30 2004
@@ -247,26 +247,71 @@
 /**************************************************************************
  * Quoted Printable Functions
  **************************************************************************/
+static void hex(const char **p, const char *end, unsigned char *n)
+{
+	int i, c;
+
+	for (i = 0, c = 0; i < 2 && *p < end; ++i, ++*p) {
+		c <<= 4;
+		switch (**p) {
+		case '0': break;
+		case '1': c += 1; break;
+		case '2': c += 2; break;
+		case '3': c += 3; break;
+		case '4': c += 4; break;
+		case '5': c += 5; break;
+		case '6': c += 6; break;
+		case '7': c += 7; break;
+		case '8': c += 8; break;
+		case '9': c += 9; break;
+		case 'a': c += 10; break;
+		case 'b': c += 11; break;
+		case 'c': c += 12; break;
+		case 'd': c += 13; break;
+		case 'e': c += 14; break;
+		case 'f': c += 15; break;
+		case 'A': c += 10; break;
+		case 'B': c += 11; break;
+		case 'C': c += 12; break;
+		case 'D': c += 13; break;
+		case 'E': c += 14; break;
+		case 'F': c += 15; break;
+		default:
+			  if (i == 0) {
+				  *n = **p;
+				  ++*p;
+				  return;
+			  }
+			  c >>= 4;
+			  goto done;
+		}
+	}
+done:
+	*n = (c > UCHAR_MAX) ? '?' : c;
+	return;
+}
+  
 void
 gaim_quotedp_decode(const char *str, char **ret_str, int *ret_len)
 {
-	char *n, *new;
-	const char *end, *p;
-	int i;
-
-	n = new = g_malloc(strlen (str) + 1);
-	end = str + strlen(str);
+	const char *p, *end;
+	unsigned char *n, *new;
+	size_t len;
+
+	len = strlen (str);
+	n = new = g_malloc(len + 1);
+	p = str;
+	end = &p[len];
 
-	for (p = str; p < end; p++, n++) {
+	while (p < end) {
 		if (*p == '=') {
-			sscanf(p + 1, "%2x\n", &i);
-			*n = i;
-			p += 2;
+			++p;
+			hex(&p, end, n);
+		} else {
+			*n = *p == '_' ? ' ' : *p;
+			++p;
 		}
-		else if (*p == '_')
-			*n = ' ';
-		else
-			*n = *p;
+		++n;
 	}
 
 	*n = '\0';
@@ -2119,9 +2164,14 @@
 static size_t
 parse_content_len(const char *data, size_t data_len)
 {
-	size_t content_len = 0;
+	int content_len = 0;
+	char *tmp;
 
-	sscanf(data, "Content-Length: %d", (int *)&content_len);
+	tmp = g_malloc(data_len + 1);
+	memcpy(tmp, data, data_len);
+	tmp[data_len] = '\0';
+	sscanf(tmp, "Content-Length: %d", &content_len);
+	g_free(tmp);
 
 	return content_len;
 }
