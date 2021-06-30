--- t/02-smime.more.t.orig	2018-01-10 05:31:23 UTC
+++ t/02-smime.more.t
@@ -11,7 +11,7 @@ use Config;
 my ($key, $crt);
 do {
     my $OPENSSL = do {
-        if (defined(my $prefix = ExtUtils::PkgConfig->variable('openssl', 'prefix'))) {
+        if (defined(my $prefix = $ENV{OPENSSLBASE})) {
             my $OPENSSL = $prefix . '/bin/openssl' . $Config{exe_ext};
             if (-x $OPENSSL) {
                 diag "Using `$OPENSSL' to generate a keypair";
