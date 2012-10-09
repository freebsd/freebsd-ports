--- va/va_trace.c.orig	2012-10-04 15:30:51.000000000 +0200
+++ va/va_trace.c	2012-10-09 23:12:35.888197737 +0200
@@ -137,6 +137,18 @@
                          VASurfaceID surface
                          );
 
+static size_t
+strnlen(const char *s, size_t maxlen)
+{
+	size_t len;
+
+	for (len = 0; len < maxlen; len++, s++) {
+		if (!*s)
+			break;
+	}
+	return (len);
+}
+
 #define FILE_NAME_SUFFIX(env_value)                      \
 do {                                                    \
     int tmp = strnlen(env_value, sizeof(env_value));    \
