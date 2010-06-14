--- src/msmtp.c.orig	2010-06-14 10:41:20.000000000 +0000
+++ src/msmtp.c	2010-06-14 10:43:01.000000000 +0000
@@ -3344,6 +3344,7 @@
     {
         printf("%s\n", account->auth_mech);
     }
+#ifdef HAVE_TLS    
     if (account->tls_sha1_fingerprint)
     {
         msmtp_fingerprint_string(fingerprint_string,
@@ -3354,6 +3355,7 @@
         msmtp_fingerprint_string(fingerprint_string,
                 account->tls_md5_fingerprint, 16);
     }
+#endif /* HAVE_TLS */
     printf("user                  = %s\n"
             "password              = %s\n"
             "ntlmdomain            = %s\n"
