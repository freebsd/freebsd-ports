--- src/import.c.orig	2010-05-31 23:01:37.000000000 +0200
+++ src/import.c	2014-07-22 16:11:44.000000000 +0200
@@ -695,7 +695,7 @@
 
                 // After having all the parts unencrypted, we import all certificates first.
                 for (i=0; i<n_bags; i++) {
-                        gnutls_pkcs12_bag * pkcs12_bag = g_array_index (pkcs_bag_array, gnutls_pkcs12_bag_t *, i);
+                        gnutls_pkcs12_bag_t * pkcs12_bag = g_array_index (pkcs_bag_array, gnutls_pkcs12_bag_t *, i);
                         guint num_elements_in_bag = gnutls_pkcs12_bag_get_count (*pkcs12_bag);
                         
                         for (i=0; i < num_elements_in_bag; i++) {
@@ -722,7 +722,7 @@
                 
                 // Then, we import all PKCS8 private keys.
                 for (i=0; i<n_bags; i++) {
-                        gnutls_pkcs12_bag * pkcs12_bag = g_array_index (pkcs_bag_array, gnutls_pkcs12_bag_t *, i);
+                        gnutls_pkcs12_bag_t * pkcs12_bag = g_array_index (pkcs_bag_array, gnutls_pkcs12_bag_t *, i);
                         guint num_elements_in_bag = gnutls_pkcs12_bag_get_count (*pkcs12_bag);
                         
                         for (i=0; i < num_elements_in_bag; i++) {
@@ -796,7 +796,7 @@
                 // Then we import the CRLs
 
                 for (i=0; i<n_bags; i++) {
-                        gnutls_pkcs12_bag * pkcs12_bag = g_array_index (pkcs_bag_array, gnutls_pkcs12_bag_t *, i);
+                        gnutls_pkcs12_bag_t * pkcs12_bag = g_array_index (pkcs_bag_array, gnutls_pkcs12_bag_t *, i);
                         guint num_elements_in_bag = gnutls_pkcs12_bag_get_count (*pkcs12_bag);
                         
                         for (i=0; i < num_elements_in_bag; i++) {
