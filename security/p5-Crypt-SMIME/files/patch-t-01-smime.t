--- t/01-smime.t.orig	2016-12-01 08:42:33 UTC
+++ t/01-smime.t
@@ -11,7 +11,7 @@ use Config;
 my (%key, %csr, %crt, %p12);
 do {
     my $OPENSSL = do {
-        if (defined(my $prefix = ExtUtils::PkgConfig->variable('openssl', 'prefix'))) {
+        if (defined(my $prefix = $ENV{OPENSSLBASE})) {
             my $OPENSSL = $prefix . '/bin/openssl' . $Config{exe_ext};
             if (-x $OPENSSL) {
                 diag "Using `$OPENSSL' to generate a keypair";
