Fixes wrong title level.

--- docs/MANUAL.rst.orig	2011-08-15 14:21:24.000000000 +0400
+++ docs/MANUAL.rst	2011-08-15 14:22:03.000000000 +0400
@@ -380,7 +380,7 @@
 default.
 
 Certificate checking
-^^^^^^^^^^^^^^^^^^^^
+--------------------
 
 Unfortunately, by default we will not verify the certificate of an IMAP
 TLS/SSL server we connect to, so connecting by SSL is no guarantee
@@ -397,7 +397,7 @@
 certificate and CA certificate.
 
 StartTLS
-^^^^^^^^
+--------
 
 If you have not configured your account to connect via SSL anyway,
 OfflineImap will still attempt to set up an SSL connection via the
