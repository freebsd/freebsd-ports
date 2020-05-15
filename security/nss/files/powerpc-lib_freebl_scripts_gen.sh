--- lib/freebl/scripts/gen.sh.orig	2020-05-12 17:17:31 UTC
+++ lib/freebl/scripts/gen.sh
@@ -3,7 +3,7 @@
 # Run the scripts in this folder, generating the assembly,
 #
 
-perl sha512p8-ppc.pl linux64le sha512-p8.s
+perl sha512p8-ppc.pl linux32 sha512-p8.s
 
 # Add the license mention
 cat > hdr << "EOF"
