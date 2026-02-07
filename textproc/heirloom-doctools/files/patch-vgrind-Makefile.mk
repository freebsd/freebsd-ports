--- vgrind/Makefile.mk.orig	2023-01-13 07:57:50 UTC
+++ vgrind/Makefile.mk
@@ -34,5 +34,5 @@ clean:
 mrproper: clean
 
 vgrind.1: vgrind.1.in
-	sed -e 's"/usr/ucblib/tmac/"$(ROOT)$(MACDIR)/"' \
-	    -e 's"/usr/ucblib/"$(ROOT)$(LIBDIR)/"' vgrind.1.in > $@
+	sed -e 's"/usr/ucblib/tmac/"$(MACDIR)/"' \
+	    -e 's"/usr/ucblib/"$(LIBDIR)/"' vgrind.1.in > $@
