--- strobe.orig	2010-03-13 19:26:31.000000000 +0100
+++ strobe.c	2010-03-13 19:27:06.000000000 +0100
@@ -1297,7 +1297,7 @@
 	exit (1);
     }
     port_descs=(struct port_desc_s **) Smalloc(sizeof(struct port_descs_s *) * 65536);
-    memset(port_descs, 0, 65536);
+    memset(port_descs, 0, sizeof(struct port_descs_s *) * 65536);
     while (fgets (lbuf, sizeof (lbuf), fh))
     {
 	char *p;
