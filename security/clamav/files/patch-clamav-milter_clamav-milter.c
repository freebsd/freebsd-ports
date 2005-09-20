
$FreeBSD$

--- clamav-milter/clamav-milter.c.orig
+++ clamav-milter/clamav-milter.c
@@ -3439,9 +3439,9 @@
 {
 	fd_set rfds;
 	struct timeval tv;
+	int ret;
 
 	assert(sock >= 0);
-	int ret;
 
 	if(readTimeout == 0) {
 		do
