--- src/send.c	10 Mar 2002 14:09:59 -0000	1.26
+++ src/send.c	13 Mar 2002 00:41:07 -0000
@@ -234,7 +234,7 @@
 	}
 
 	r = pclose(pipefp);
-	if (r != 0) {
+	if (r > 0) {
 		g_warning(_("external command failed: %s\n"), command);
 		return -1;
 	}
