--- t/03-chained-certs.t.orig	2018-02-22 09:33:03 UTC
+++ t/03-chained-certs.t
@@ -29,7 +29,7 @@ use Config;
 my (%key, %csr, %crt);
 do {
     my $OPENSSL = do {
-        if (defined(my $prefix = ExtUtils::PkgConfig->variable('openssl', 'prefix'))) {
+        if (defined(my $prefix = $ENV{OPENSSLBASE})) {
             my $OPENSSL = $prefix . '/bin/openssl' . $Config{exe_ext};
             if (-x $OPENSSL) {
                 diag "Using `$OPENSSL' to generate a keypair";
