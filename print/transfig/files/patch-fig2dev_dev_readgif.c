--- fig2dev/dev/readgif.c.orig	Tue Apr  8 14:42:07 2003
+++ fig2dev/dev/readgif.c
@@ -197,7 +197,7 @@
 	/* make name for temp output file */
 	sprintf(pcxname, "%s/%s%06d.pix", TMPDIR, "xfig-pcx", getpid());
 	/* make command to convert gif to pcx into temp file */
-	sprintf(buf, "giftopnm | ppmtopcx > %s 2> /dev/null", pcxname);
+	sprintf(buf, "giftopnm -quiet | ppmtopcx -quiet > %s", pcxname);
 	if ((giftopcx = popen(buf,"w" )) == 0) {
 	    fprintf(stderr,"Cannot open pipe to giftoppm\n");
 	    return 0;
