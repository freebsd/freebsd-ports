--- zaptel/zaptel.c.orig	Sun Jun 25 14:21:49 2006
+++ zaptel/zaptel.c	Fri Aug 11 11:56:20 2006
@@ -397,7 +397,7 @@
 
 int schluffen(void *q)
 {
-	int rc = tsleep(q, PZERO | PCATCH, "schluffen", 0);
+	int rc = tsleep(q, PZERO | PCATCH, "schluffen", 10);
 	switch(rc)
 	{
 		case EINTR:
