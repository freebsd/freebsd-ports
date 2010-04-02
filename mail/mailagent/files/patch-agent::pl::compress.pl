--- agent/pl/compress.pl.ORIG	2010-04-02 11:34:22.000000000 +0900
+++ agent/pl/compress.pl	2010-04-02 12:06:36.000000000 +0900
@@ -63,9 +63,8 @@
 	unless (open(COMPSPEC, "$cf'compspec")) {
 		# Configure a set of defaults if the user hasn't specified them manually
 		# Fields are: tag extension compression_prog uncompress_prog cat_prog
-		# The following legacy line removed as modern systems lack compress:
-		# compress	.Z	compress	uncompress	zcat
 		&add_compressor(<<'EOT');
+compress	.Z	compress	uncompress	zcat
 gzip		.gz		gzip		gunzip		gunzip -c
 bzip2		.bz2	bzip2		bunzip2		bzcat
 EOT
