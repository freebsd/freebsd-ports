--- support/htpasswd.c	2002/06/18 02:58:36	1.48
+++ support/htpasswd.c	2002/06/19 17:31:19	1.49
@@ -375,7 +375,7 @@
         }
     }
 
-    if (*mask & (APHTP_NEWFILE | APHTP_NOFILE)) {
+    if ((*mask & APHTP_NEWFILE) && (*mask & APHTP_NOFILE)) {
         apr_file_printf(errfile, "%s: -c and -n options conflict\n", argv[0]);
         exit(ERR_SYNTAX);
     }
