--- Makefile.PL.orig	Tue Dec 26 15:48:57 2000
+++ Makefile.PL	Mon Jan  8 21:06:36 2001
@@ -10,19 +10,7 @@
 }
 
 if ($] >= 5.007) {
-    print <<"EOT";
-
-Perl-5.7 provide experimental core support for Unicode strings.  You
-can compile HTML::Entities so that Unicode entities like &euro; and
-&#x20AC; are decoded into a string containing "\\x{20AC}".  If you
-select no to the question below such entities will be left alone and
-only entities in the Latin-1 range is decoded.
-
-EOT
-    my $ans = prompt("Do you want decoding on unicode entities?", "no");
-    if ($ans =~ /^y(es)?$/i) {
-	push(@define, "-DUNICODE_ENTITIES");
-    }
+    push(@define, "-DUNICODE_ENTITIES");
 }
 push(@extra, "DEFINE" => "@define") if @define;
 
