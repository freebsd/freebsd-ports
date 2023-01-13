--- troff/troff.d/Makefile.mk.orig	2023-01-13 07:58:22 UTC
+++ troff/troff.d/Makefile.mk
@@ -40,8 +40,8 @@ clean:
 mrproper: clean
 
 troff.1: troff.1.in
-	sed -e 's"/usr/ucblib/doctools/font/"$(ROOT)$(FNTDIR)/"' \
-	    -e 's"/usr/ucblib/doctools/tmac/"$(ROOT)$(MACDIR)/"' \
+	sed -e 's"/usr/ucblib/doctools/font/"$(FNTDIR)/"' \
+	    -e 's"/usr/ucblib/doctools/tmac/"$(MACDIR)/"' \
 	    troff.1.in > $@
 
 draw.o: draw.c
