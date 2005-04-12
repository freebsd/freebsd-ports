
$FreeBSD$

--- cmkdir.c.orig
+++ cmkdir.c
@@ -43,7 +43,7 @@
 	struct timeval tv;
 	u_long r;
 	int i;
-	int ciph=CFS_THREE_DES;
+	int ciph=CFS_BLOWFISH;
 	int cfmt=1;
 	int smsize=LARGESMSIZE;
 	unsigned char ekey[128];
