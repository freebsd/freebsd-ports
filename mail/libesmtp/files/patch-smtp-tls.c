--- smtp-tls.c.orig	Mon Jan 19 02:36:32 2004
+++ smtp-tls.c	Mon Jan 19 02:41:25 2004
@@ -450,6 +450,20 @@
   return 1;
 }
 
+#if defined(__FreeBSD__)
+void *
+memrchr(const void *v, int c, size_t size)
+{
+	const unsigned char *p = (const unsigned char *) v + size;
+
+	while (size-- > 0) {
+		if (*--p == c)
+			return (void *) p;
+	}
+	return NULL;
+}
+#endif
+
 /* Perform a domain name comparison where the reference may contain
    wildcards.  This implements the comparison from RFC 2818.
    Each component of the domain name is matched separately, working from
