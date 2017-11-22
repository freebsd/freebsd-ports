--- source4/lib/http/http.c.orig	2017-01-11 07:55:15 UTC
+++ source4/lib/http/http.c
@@ -112,7 +112,19 @@ static enum http_read_status http_parse_
 		return HTTP_ALL_DATA_READ;
 	}
 
+#ifdef FREEBSD
+	int s0, s1, s2, s3; s0 = s1 = s2 = s3 = 0;
+	n = sscanf(line, "%n%*[^:]%n: %n%*[^\r\n]%n\r\n", &s0, &s1, &s2, &s3);
+
+	if(n >= 0) {
+		key = calloc(sizeof(char), s1-s0+1);
+		value = calloc(sizeof(char), s3-s2+1);
+
+		n = sscanf(line, "%[^:]: %[^\r\n]\r\n", key, value);
+	}
+#else
 	n = sscanf(line, "%m[^:]: %m[^\r\n]\r\n", &key, &value);
+#endif
 	if (n != 2) {
 		DEBUG(0, ("%s: Error parsing header '%s'\n", __func__, line));
 		status = HTTP_DATA_CORRUPTED;
@@ -138,7 +150,7 @@ error:
 static bool http_parse_response_line(struct http_read_response_state *state)
 {
 	bool	status = true;
-	char	*protocol;
+	char	*protocol = NULL;
 	char	*msg = NULL;
 	char	major;
 	char	minor;
@@ -158,12 +170,22 @@ static bool http_parse_response_line(str
 		return false;
 	}
 
+#ifdef FREEBSD
+	int s0, s1, s2, s3; s0 = s1 = s2 = s3 = 0;
+	n = sscanf(line, "%n%*[^/]%n/%c.%c %d %n%*[^\r\n]%n\r\n",
+		   &s0, &s1, &major, &minor, &code, &s2, &s3);
+
+	if(n == 3) {
+		protocol = calloc(sizeof(char), s1-s0+1);
+		msg = calloc(sizeof(char), s3-s2+1);
+
+		n = sscanf(line, "%[^/]/%c.%c %d %[^\r\n]\r\n",
+			protocol, &major, &minor, &code, msg);
+	}
+#else
 	n = sscanf(line, "%m[^/]/%c.%c %d %m[^\r\n]\r\n",
 		   &protocol, &major, &minor, &code, &msg);
-
-	DEBUG(11, ("%s: Header parsed(%i): protocol->%s, major->%c, minor->%c, "
-		   "code->%d, message->%s\n", __func__, n, protocol, major, minor,
-		   code, msg));
+#endif
 
 	if (n != 5) {
 		DEBUG(0, ("%s: Error parsing header\n",	__func__));
@@ -171,6 +193,10 @@ static bool http_parse_response_line(str
 		goto error;
 	}
 
+	DEBUG(11, ("%s: Header parsed(%i): protocol->%s, major->%c, minor->%c, "
+		   "code->%d, message->%s\n", __func__, n, protocol, major, minor,
+		   code, msg));
+
 	if (major != '1') {
 		DEBUG(0, ("%s: Bad HTTP major number '%c'\n", __func__, major));
 		status = false;
