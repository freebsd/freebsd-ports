--- t/locale.t.orig	Thu Apr 27 21:59:24 2006
+++ t/locale.t	Thu Apr 27 21:59:32 2006
@@ -34,7 +34,7 @@
 }
 print "ok 2\n";
 
-setlocale(&LC_ALL, "en_US");
+setlocale(&LC_ALL, "en_US.US-ASCII");
 my $english = new Number::Format();
 print "not " unless ($english->format_price(123456.789) eq 'USD 123,456.79');
 print "ok 3\n";
