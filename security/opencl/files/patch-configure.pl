--- configure.pl.orig	Fri May 10 10:03:25 2002
+++ configure.pl	Fri May 10 10:03:35 2002
@@ -1705,7 +1705,7 @@
 DOCDIR        = \$(INSTALLROOT)/$doc_dir/OpenCL-\$(VERSION)
 
 OWNER         = root
-GROUP         = root
+GROUP         = wheel
 DATA_MODE     = 644
 EXEC_MODE     = 755
 
