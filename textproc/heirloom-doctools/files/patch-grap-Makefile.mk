--- grap/Makefile.mk.orig	2023-01-13 08:00:09 UTC
+++ grap/Makefile.mk
@@ -28,7 +28,7 @@ clean:
 mrproper: clean
 
 grap.1: grap.1.in
-	sed 's"/usr/ucblib/"$(ROOT)$(LIBDIR)/"' grap.1.in > $@
+	sed 's"/usr/ucblib/"$(LIBDIR)/"' grap.1.in > $@
 
 coord.o: coord.c grap.h y.tab.h
 for.o: for.c grap.h y.tab.h
