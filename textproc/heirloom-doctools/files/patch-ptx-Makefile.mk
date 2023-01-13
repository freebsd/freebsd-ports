--- ptx/Makefile.mk.orig	2023-01-13 07:59:44 UTC
+++ ptx/Makefile.mk
@@ -24,6 +24,6 @@ mrproper: clean
 
 ptx.1: ptx.1.in
 	sed -e "s'/usr/5bin/sort'`which sort`'" \
-	    -e 's"/usr/ucblib/doctools/tmac/"$(ROOT)$(BINDIR)/"' \
-	    -e 's"/usr/ucblib/"$(ROOT)$(LIBDIR)/"' \
+	    -e 's"/usr/ucblib/doctools/tmac/"$(MACDIR)/"' \
+	    -e 's"/usr/ucblib/"$(LIBDIR)/"' \
 	    ptx.1.in > $@
