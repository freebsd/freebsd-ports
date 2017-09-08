--- include/ctrs.h.orig	2017-08-06 18:26:36 UTC
+++ include/ctrs.h
@@ -16,21 +16,27 @@ struct my_ctrs {
  * Caller has to make sure that the buffer is large enough.
  */
 static const char *
-norm2(char *buf, double val, char *fmt)
+norm2(char *buf, double val, char *fmt, int normalize)
 {
 	char *units[] = { "", "K", "M", "G", "T" };
 	u_int i;
-
-	for (i = 0; val >=1000 && i < sizeof(units)/sizeof(char *) - 1; i++)
-		val /= 1000;
+	if (normalize)
+		for (i = 0; val >=1000 && i < sizeof(units)/sizeof(char *) - 1; i++)
+			val /= 1000;
+	else
+		i=0;
 	sprintf(buf, fmt, val, units[i]);
 	return buf;
 }
 
 static __inline const char *
-norm(char *buf, double val)
+norm(char *buf, double val, int normalize)
 {
-	return norm2(buf, val, "%.3f %s");
+	
+	if (normalize)
+		return norm2(buf, val, "%.3f %s", normalize);
+	else
+		return norm2(buf, val, "%.0f %s", normalize);
 }
 
 static __inline int
