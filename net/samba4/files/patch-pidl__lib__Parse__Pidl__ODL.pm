--- pidl/lib/Parse/Pidl/ODL.pm.orig	2012-10-02 08:24:41.000000000 +0000
+++ pidl/lib/Parse/Pidl/ODL.pm	2013-06-13 09:21:02.000000000 +0000
@@ -70,7 +70,7 @@
 					next;
 				}
 				my $podl = Parse::Pidl::IDL::parse_file($idl_path, $opt_incdirs);
-				if (defined(@$podl)) {
+				if (defined($podl)) {
 					require Parse::Pidl::Typelist;
 					my $basename = basename($idl_path, ".idl");
 
