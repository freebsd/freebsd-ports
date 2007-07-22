
$FreeBSD$

--- zaptel/zt_zone.c
+++ zaptel/zt_zone.c
@@ -326,7 +326,7 @@
 	int x;
 	int space;
 	int res;
-	int addr;
+	unsigned long addr;
 	
 	/* XXX Unnecessary XXX */
 	memset(samples, 0, sizeof(samples));
@@ -334,7 +334,7 @@
 	memset(next, 0, sizeof(next));
 	memset(&th, 0, sizeof(th));
 
-	bcopy((void *)data, &addr, 4);
+	bcopy((void *)data, &addr, sizeof(addr));
 	data = addr;
 	if(copyin( (caddr_t)addr, &th,  sizeof(th)))
 		printf("copyin failed\n");
