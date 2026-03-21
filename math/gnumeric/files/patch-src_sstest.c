--- src/sstest.c.orig	2026-02-11 02:07:03 UTC
+++ src/sstest.c
@@ -898,7 +898,7 @@ static gboolean
 /* ------------------------------------------------------------------------- */
 
 static gboolean
-check_help_expression (const char *text, GnmFunc const *fd, bool localized)
+check_help_expression (const char *text, GnmFunc const *fd, gboolean localized)
 {
 	GnmConventions const *convs = gnm_conventions_default;
 	GnmParsePos pp;
