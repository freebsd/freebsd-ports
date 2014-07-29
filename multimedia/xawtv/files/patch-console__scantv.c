--- console/scantv.c.orig	Wed Feb 11 23:14:16 2004
+++ console/scantv.c	Wed Feb 11 23:15:04 2004
@@ -245,7 +245,11 @@
 		fprintf(stderr,"no station\n");
 		continue;
 	    }
+#ifdef __FreeBSD__	/* Actually it won't work for FreeBSD... */
+	    name = NULL;
+#else
 	    name = get_vbi_name(vbi);
+#endif
 	    fprintf(stderr, "%s\n", name ? name : "???");
 	    if (NULL == name) {
 		sprintf(dummy,"unknown (%s)",chanlist[i].name);
