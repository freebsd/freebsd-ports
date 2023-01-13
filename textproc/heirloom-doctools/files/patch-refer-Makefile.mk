--- refer/Makefile.mk.orig	2023-01-13 07:59:22 UTC
+++ refer/Makefile.mk
@@ -95,13 +95,13 @@ clean:
 mrproper: clean
 
 lookbib.1: lookbib.1.in
-	sed 's"/usr/ucblib/reftools/"$(ROOT)$(REFDIR)/"' lookbib.1.in > $@
+	sed 's"/usr/ucblib/reftools/"$(REFDIR)/"' lookbib.1.in > $@
 
 refer.1: refer.1.in
-	sed 's"/usr/ucblib/reftools/"$(ROOT)$(REFDIR)/"' refer.1.in > $@
+	sed 's"/usr/ucblib/reftools/"$(REFDIR)/"' refer.1.in > $@
 
 roffbib.1: roffbib.1.in
-	sed 's"/usr/ucblib/doctools/tmac/"$(ROOT)$(MACDIR)/"' roffbib.1.in > $@
+	sed 's"/usr/ucblib/doctools/tmac/"$(MACDIR)/"' roffbib.1.in > $@
 
 addbib.o: addbib.c
 deliv2.o: deliv2.c refer..c
