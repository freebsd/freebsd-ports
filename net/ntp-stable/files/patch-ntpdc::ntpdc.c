--- ntpdc/ntpdc.c.orig	Sat Oct 11 00:52:22 2003
+++ ntpdc/ntpdc.c	Sun Jan 25 13:29:58 2004
@@ -449,7 +449,11 @@
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
