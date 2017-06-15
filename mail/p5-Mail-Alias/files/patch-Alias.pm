--- Alias.pm.orig	2016-11-22 14:55:19 UTC
+++ Alias.pm
@@ -82,7 +82,7 @@ sub format {
  my $pkg = "Mail::Alias::" . $fmt;
 
  croak "Unknown format '$fmt'"
-  unless defined @{$pkg . "::ISA"};
+  unless @{$pkg . "::ISA"};
 
  bless $me, $pkg;
 }
