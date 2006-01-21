--- Mk/ov.os.mk.orig	Sat Sep  3 12:22:17 2005
+++ Mk/ov.os.mk	Sun Sep  4 01:51:57 2005
@@ -16,10 +16,11 @@
 else
 
 
-	INST_PATH=/usr/local/lib/openvanilla/
+	INST_PATH=${PREFIX}/lib/openvanilla/
 	OBJS=$(patsubst %, %.lo, $(SOURCES))
 	GOALS=$(IMID).la
 	#CFLAGS=-I/usr/local/include/ -I../../Headers/
+	LIBS=-L/usr/local/lib
 
 $(GOALS): $(OBJS)
 	$(LIBTOOL) --tag=CXX --mode=link $(CPP) $(LDFLAGS) $(LIBS) -module -rpath $(INST_PATH) -avoid-version -o $(GOALS)  $(OBJS)
