--- autoconf/make/link.mk.orig	Wed Apr 13 21:33:54 2005
+++ autoconf/make/link.mk	Wed Apr 13 21:34:15 2005
@@ -6,9 +6,9 @@
 mainobjs := src/main.o src/md5.o src/library.o src/db.o src/message.o src/mailbox.o src/spam.o src/tests.o
 
 $(package): $(mainobjs)
-	$(CC) $(CFLAGS) -o $@ $(mainobjs) $(LIBS)
+	$(CC) $(CFLAGS) -o $@ $(mainobjs) ${LDFLAGS} $(LIBS)
 
 $(package)-static: $(mainobjs)
-	$(CC) $(CFLAGS) -static -o $@ $(mainobjs) $(LIBS)
+	$(CC) $(CFLAGS) -static -o $@ $(mainobjs) ${LDFLAGS} $(LIBS)
 
 # EOF
