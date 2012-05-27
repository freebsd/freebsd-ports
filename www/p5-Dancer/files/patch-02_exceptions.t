--- t/25_exceptions/02_exceptions.t.orig	2012-05-27 13:36:12.711337363 +0900
+++ t/25_exceptions/02_exceptions.t	2012-05-27 13:36:35.595803613 +0900
@@ -130,7 +130,7 @@
         };
     };
     ok(! $@);
-    is($e, 'wrong login (login was douglas)');
+    like($e, qr/wrong login \(login was douglas\)/);
     # check stringification works in other cases
     ok($e eq 'wrong login (login was douglas)');
     ok('wrong login (login was douglas)' eq $e);
