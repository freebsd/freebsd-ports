--- libfree/inet_ntop.c.orig	Sat Feb 21 21:25:08 2004
+++ libfree/inet_ntop.c	Sat Feb 21 21:25:21 2004
@@ -57,7 +57,7 @@
 	int af;
 	const void *src;
 	char *dst;
-	size_t size;
+	socklen_t size;
 {
 	switch (af) {
 	case AF_INET:
