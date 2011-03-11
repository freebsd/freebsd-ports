--- va/va_trace.c~
+++ va/va_trace.c
@@ -140,6 +140,17 @@ VAStatus vaUnlockSurface(VADisplay dpy,
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
 
 void va_TraceInit(VADisplay dpy)
 {
