--- troff/nroff.d/Makefile.mk.orig	2023-01-13 07:58:41 UTC
+++ troff/nroff.d/Makefile.mk
@@ -31,8 +31,8 @@ clean:
 mrproper: clean
 
 nroff.1: nroff.1.in
-	sed -e 's"/usr/ucblib/doctools/tmac/"$(ROOT)$(MACDIR)/"' \
-	    -e 's"/usr/ucblib/doctools/nterm/"$(ROOT)$(TABDIR)/"' \
+	sed -e 's"/usr/ucblib/doctools/tmac/"$(MACDIR)/"' \
+	    -e 's"/usr/ucblib/doctools/nterm/"$(TABDIR)/"' \
 	    nroff.1.in > $@
 
 draw.o: ../tdef.h ../ext.h
