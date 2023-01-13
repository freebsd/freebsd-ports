--- soelim/Makefile.mk.orig	2023-01-13 07:59:03 UTC
+++ soelim/Makefile.mk
@@ -21,4 +21,4 @@ clean:
 mrproper: clean
 
 soelim.1: soelim.1.in
-	sed 's"/usr/ucblib/doctools/tmac/"$(ROOT)$(MACDIR)/"' soelim.1.in > $@
+	sed 's"/usr/ucblib/doctools/tmac/"$(MACDIR)/"' soelim.1.in > $@
