--- libfree/inet_ntop.c.orig	1997-04-13 22:23:41 UTC
+++ libfree/inet_ntop.c
@@ -57,7 +57,7 @@ inet_ntop(af, src, dst, size)
 	int af;
 	const void *src;
 	char *dst;
-	size_t size;
+	socklen_t size;
 {
 	switch (af) {
 	case AF_INET:
