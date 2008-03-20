--- lib/Business/PayPal/EWP.pm.orig	2007-09-05 07:06:20.000000000 -0700
+++ lib/Business/PayPal/EWP.pm	2008-02-28 22:17:15.000000000 -0800
@@ -65,6 +65,7 @@
 	goto END;
     }
     Net::SSLeay::BIO_free($bio);
+    $bio = undef;
     # Reformat
     $formdata=~s/,/\n/g;
     # Encrypt and sign
