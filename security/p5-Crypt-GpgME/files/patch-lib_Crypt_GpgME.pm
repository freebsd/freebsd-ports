The trustlist feature, which only worked for a short period in 2003, was
removed in GpgME 2.0.0.

--- lib/Crypt/GpgME.pm.orig	2009-11-17 22:51:18 UTC
+++ lib/Crypt/GpgME.pm
@@ -226,10 +226,6 @@ Returns a new Crypt::GpgME instance. Throws an excepti
 
     my $key = $ctx->signers_enum($seq);
 
-=head2 trustlist
-
-    my @trustlist = $ctx->trustlist($pattern, $maxlevel);
-
 =head2 verify
 
     my ($result, $plain) = $ctx->verify($sig);
