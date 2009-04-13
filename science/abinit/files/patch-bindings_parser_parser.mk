--- bindings/parser/parser.mk~	2009-03-11 14:12:20.000000000 +0900
+++ bindings/parser/parser.mk	2009-04-13 11:53:44.000000000 +0900
@@ -25,7 +25,7 @@
 	$(RANLIB) libbindings.a
 
 ab_dtset_py.o: dtset_py.h ab_dtset_c.h
-	$(CC) $(CPPFLAGS) $(PYTHON_CPPFLAGS) -I. $(CFLAGS) -c $(abinit_srcdir)/bindings/parser/ab_dtset_py.c
+	$(CC) $(CPPFLAGS) $(CFLAGS_EXTRA) $(PYTHON_CPPFLAGS) -I. $(CFLAGS) -c $(abinit_srcdir)/bindings/parser/ab_dtset_py.c
 
 
 python: ab_dtset_py.o
