--- pgp.c.orig	Thu Aug 11 23:22:41 2005
+++ pgp.c	Thu Aug 25 08:01:22 2005
@@ -381,16 +381,21 @@
 	}
 	
         /* treat empty result as sign of failure */
-	rewind (pgpout);
-        if ((c = fgetc (pgpout)) == EOF)
+	if (pgpout)
+	{
+	  rewind (pgpout);
+	  c = fgetc (pgpout);
+	  ungetc (c, pgpout);
+	}
+        if (!clearsign && (!pgpout || c == EOF))
 	{
           mutt_error _("Could not decrypt PGP message");
+	  mutt_sleep (1);
           pgp_void_passphrase ();
           rc = -1;
           
           goto out;
         }
-	ungetc (c, pgpout);
       }
       
       /*
