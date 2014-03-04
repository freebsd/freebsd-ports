CVE-2014-0092
CVE-2014-1959

--- ./lib/x509/verify.c.orig	2012-05-24 11:19:05.000000000 -0500
+++ ./lib/x509/verify.c	2014-03-04 16:43:13.053087407 -0600
@@ -141,7 +141,7 @@
   if (result < 0)
     {
       gnutls_assert ();
-      goto cleanup;
+      goto fail;
     }
 
   result =
@@ -150,7 +150,7 @@
   if (result < 0)
     {
       gnutls_assert ();
-      goto cleanup;
+      goto fail;
     }
 
   result =
@@ -158,7 +158,7 @@
   if (result < 0)
     {
       gnutls_assert ();
-      goto cleanup;
+      goto fail;
     }
 
   result =
@@ -166,7 +166,7 @@
   if (result < 0)
     {
       gnutls_assert ();
-      goto cleanup;
+      goto fail;
     }
 
   /* If the subject certificate is the same as the issuer
@@ -206,6 +206,7 @@
   else
     gnutls_assert ();
 
+fail:
   result = 0;
 
 cleanup:
@@ -330,7 +331,7 @@
   gnutls_datum_t cert_signed_data = { NULL, 0 };
   gnutls_datum_t cert_signature = { NULL, 0 };
   gnutls_x509_crt_t issuer = NULL;
-  int issuer_version, result;
+  int issuer_version, result = 0;
 
   if (output)
     *output = 0;
@@ -363,7 +364,7 @@
   if (issuer_version < 0)
     {
       gnutls_assert ();
-      return issuer_version;
+      return 0;
     }
 
   if (!(flags & GNUTLS_VERIFY_DISABLE_CA_SIGN) &&
@@ -385,6 +386,7 @@
   if (result < 0)
     {
       gnutls_assert ();
+      result = 0;
       goto cleanup;
     }
 
@@ -393,6 +395,7 @@
   if (result < 0)
     {
       gnutls_assert ();
+      result = 0;
       goto cleanup;
     }
 
@@ -410,6 +413,7 @@
   else if (result < 0)
     {
       gnutls_assert();
+      result = 0;
       goto cleanup;
     }
 
@@ -644,8 +648,10 @@
       /* note that here we disable this V1 CA flag. So that no version 1
        * certificates can exist in a supplied chain.
        */
-      if (!(flags & GNUTLS_VERIFY_ALLOW_ANY_X509_V1_CA_CRT))
+      if (!(flags & GNUTLS_VERIFY_ALLOW_ANY_X509_V1_CA_CRT)) {
         flags &= ~(GNUTLS_VERIFY_ALLOW_X509_V1_CA_CRT);
+        flags |= GNUTLS_VERIFY_DO_NOT_ALLOW_X509_V1_CA_CRT;
+      }
       if ((ret =
            _gnutls_verify_certificate2 (certificate_list[i - 1],
                                         &certificate_list[i], 1, flags,
