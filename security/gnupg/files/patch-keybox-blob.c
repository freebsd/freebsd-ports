--- kbx/keybox-blob.c.orig	2010-07-23 22:18:31.450982300 +0900
+++ kbx/keybox-blob.c	2010-07-23 22:18:53.264465242 +0900
@@ -898,6 +898,7 @@
               rc = gpg_error_from_syserror ();
               goto leave;
             }
+	    names = tmp;
         }
       names[blob->nuids++] = p;
       if (!i && (p=x509_email_kludge (p)))
