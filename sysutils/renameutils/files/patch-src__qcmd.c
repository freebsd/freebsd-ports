--- src/qcmd.c.orig	2011-08-21 17:15:51 UTC
+++ src/qcmd.c
@@ -239,7 +239,7 @@
     editor_program = xstrdup(editor_program);
 
     if (ls_program == NULL)
-        ls_program = xstrdup("ls");
+        ls_program = xstrdup("gls");
 
     /* Parse format options */
     if (format_options != NULL && !format->parse_options(format_options))
