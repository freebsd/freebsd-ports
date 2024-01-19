--- console/scantv.c.orig	2020-05-15 23:32:25 UTC
+++ console/scantv.c
@@ -261,7 +261,11 @@ main(int argc, char **argv)
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
