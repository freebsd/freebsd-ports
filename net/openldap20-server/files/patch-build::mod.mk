--- build/mod.mk.orig	Fri Jan  4 21:38:06 2002
+++ build/mod.mk	Sat Jul 12 19:30:28 2003
@@ -10,7 +10,7 @@
 LIBRARY = $(LIBBASE).la
 LIBSTAT = lib$(LIBBASE).a
 
-LTFLAGS = --only-$(LINKAGE)
+LTFLAGS = # --only-$(LINKAGE)
 
 COMPILE = $(LIBTOOL) $(LTFLAGS) --mode=compile $(CC) $(CFLAGS) $(MODDEFS) -c
 LTLIBLINK = $(LIBTOOL) $(LTFLAGS) --mode=link $(CC) -rpath $(moduledir) \
