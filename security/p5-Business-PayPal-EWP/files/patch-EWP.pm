--- lib/Business/PayPal/EWP.pm.old	Thu May 12 10:42:19 2005
+++ lib/Business/PayPal/EWP.pm	Thu May 12 10:42:39 2005
@@ -65,6 +65,7 @@
 	goto END;
     }
     Net::SSLeay::BIO_free($bio);
+    $bio = undef;
     # Reformat
     $formdata=~s/,/\n/g;
     # Encrypt and sign
