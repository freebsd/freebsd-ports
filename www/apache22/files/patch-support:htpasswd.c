--- support/htpasswd.c.orig	Tue Jun 18 11:58:36 2002
+++ support/htpasswd.c	Mon Jul  8 16:30:14 2002
@@ -236,6 +236,7 @@
     strcpy(record, user);
     strcat(record, ":");
     strcat(record, cpw);
+    strcat(record, "\n");
     return 0;
 }
 
@@ -375,7 +376,7 @@
         }
     }
 
-    if (*mask & (APHTP_NEWFILE | APHTP_NOFILE)) {
+    if ((*mask & APHTP_NEWFILE) && (*mask & APHTP_NOFILE)) {
         apr_file_printf(errfile, "%s: -c and -n options conflict\n", argv[0]);
         exit(ERR_SYNTAX);
     }
@@ -592,6 +593,7 @@
                  */
                 apr_file_printf(errfile, "Updating ");
                 putline(ftemp, record);
+                found++;
             }
         }
     }
