--- util/util.make.orig	Sun Jun 22 23:10:08 2003
+++ util/util.make	Sun Jun 22 23:16:12 2003
@@ -92,4 +92,4 @@
 phi.o:		phi.c
 
 rand.o:		rand.c		rand.h
-	$(CC) $(CFLAGS) -DRAND_FILE=\"`pwd`/../util/randfile\" -c rand.c
+	$(CC) $(CFLAGS) -DRAND_FILE=\"${PREFIX}/share/fbm/randfile\" -c rand.c
