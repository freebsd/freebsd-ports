--- util/config.go.orig	2019-01-31 14:41:03 UTC
+++ util/config.go
@@ -26,6 +26,8 @@
 var Upgrade bool
 // WebHostURL is the public route to the semaphore server
 var WebHostURL *url.URL
+// FreeBSD's Semaphore Version Information (patched with REINPLACE_CMD call at the do-build stage)
+var Version = "%%PORTVERSION%%"
 
 const (
 	longPos  = "yes"

