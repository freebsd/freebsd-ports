--- ntpq/ntpq.c.orig	Thu Oct  9 02:27:05 2003
+++ ntpq/ntpq.c	Sun Jan 25 13:49:33 2004
@@ -630,7 +630,11 @@
 	hints.ai_flags = AI_NUMERICHOST;
 
 	a_info = getaddrinfo(hname, service, &hints, &ai);
+#ifdef EAI_NODATA
 	if (a_info == EAI_NONAME || a_info == EAI_NODATA) {
+#else
+	if (a_info == EAI_NONAME) {
+#endif
 		hints.ai_flags = AI_CANONNAME;
 #ifdef AI_ADDRCONFIG
 		hints.ai_flags |= AI_ADDRCONFIG;
