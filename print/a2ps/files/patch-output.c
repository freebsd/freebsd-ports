Fix for CVE-2015-8107
http://www.openwall.com/lists/oss-security/2015/11/16/4
--- lib/output.c.orig	1999-08-31 17:42:41 UTC
+++ lib/output.c	2015-11-18 07:08:31.672864000 +0100
@@ -525,7 +525,7 @@
 		     expand_user_string (job, FIRST_FILE (job),
 					 (const uchar *) "Expand: requirement",
 					 (const uchar *) token));
-	output (dest, expansion);
+	output (dest, "%s", expansion);
 	continue;
       }
 
