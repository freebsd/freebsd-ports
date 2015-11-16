Fix for CVE-2015-8107
http://www.openwall.com/lists/oss-security/2015/11/16/4
--- lib/output.c.orig  2015-11-16 15:29:38 UTC
+++ lib/output.c
@@ -525,7 +525,7 @@ output_file (struct output * out, a2ps_j
                    expand_user_string (job, FIRST_FILE (job),
                                        (const uchar *) "Expand: requirement",
                                        (const uchar *) token));
-      output (dest, expansion);
+      output (dest, "%s", expansion);
       continue;
       }

