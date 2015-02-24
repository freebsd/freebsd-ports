--- X509.xs.orig	2013-12-01 17:14:25 UTC
+++ X509.xs
@@ -181,7 +181,7 @@ static HV* hv_exts(X509* x509, int no_na
   sv_2mortal((SV*)RETVAL);
   c = X509_get_ext_count(x509);
 
-  if ( ! c > 0 ) {
+  if ( c <= 0 ) {
     croak("No extensions found\n");
   }
 
@@ -860,7 +860,7 @@ extension(x509, i)
 
   c = X509_get_ext_count(x509);
 
-  if (!c > 0) {
+  if (c <= 0) {
     croak("No extensions found\n");
   } else if (i >= c || i < 0) {
     croak("Requested extension index out of range\n");
