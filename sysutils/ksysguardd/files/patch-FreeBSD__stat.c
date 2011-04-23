--- ./FreeBSD/stat.c.orig	2011-04-01 12:52:43.000000000 +0200
+++ ./FreeBSD/stat.c	2011-04-23 02:14:24.221891829 +0200
@@ -252,7 +252,7 @@
 	int irq;
 
 	sscanf(cmd + 18, "%d", &irq);
-	if (irq > 255 - msi_offset)
+	if (irq > 255)
 		irq -= msi_offset - 1;
 	fprintf(CurrentClient, "%ld\n", intr[intr_map[irq - 1]]);
 }
@@ -261,7 +261,7 @@
 	int irq;
 
 	sscanf(cmd + 18, "%d", &irq);
-	if (irq > 255 - msi_offset)
+	if (irq > 255)
 		irq -= msi_offset - 1;
 	fprintf(CurrentClient, "%s\t0\t0\t1/s\n", intrname[intr_map[irq - 1]]);
 }
