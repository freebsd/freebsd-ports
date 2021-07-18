--- t/04-taint.t.orig	2018-02-21 04:39:06 UTC
+++ t/04-taint.t
@@ -24,7 +24,7 @@ do {
     untaint $ENV{PATH};
 
     my $OPENSSL = do {
-        if (defined(my $prefix = ExtUtils::PkgConfig->variable('openssl', 'prefix'))) {
+        if (defined(my $prefix = $ENV{OPENSSLBASE})) {
             my $OPENSSL = $prefix . '/bin/openssl' . $Config{exe_ext};
             if (-x $OPENSSL) {
                 untaint $OPENSSL;
