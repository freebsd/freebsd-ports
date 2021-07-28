--- lib/output.c.orig	1999-08-31 17:42:41 UTC
+++ lib/output.c
@@ -525,7 +525,7 @@ output_file (struct output * out, a2ps_job * job,
 		     expand_user_string (job, FIRST_FILE (job),
 					 (const uchar *) "Expand: requirement",
 					 (const uchar *) token));
-	output (dest, expansion);
+	output (dest, "%s", expansion);
 	continue;
       }
 
