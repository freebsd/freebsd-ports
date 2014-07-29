--- console/vbi-tty.c.orig	Tue Feb 10 22:41:06 2004
+++ console/vbi-tty.c	Tue Feb 10 22:42:03 2004
@@ -19,7 +19,7 @@
 #include <sys/types.h>
 #include <sys/ioctl.h>
 
-#include <linux/fb.h>
+/*#include <linux/fb.h>*/
 
 #include "vbi-data.h"
 #include "vbi-tty.h"
@@ -65,7 +65,7 @@
 }
 
 /* --------------------------------------------------------------------- */
-
+#ifdef WITH_LINUX_FB_H
 static int have_fb = 0;
 static int fb_fmt  = VBI_PIXFMT_RGBA32_LE;
 static int switch_last;
@@ -74,7 +74,7 @@
 {
     fb_memset(fb_mem+fb_mem_offset,0,fb_fix.smem_len);
 }
-
+#endif
 /* --------------------------------------------------------------------- */
 
 struct vbi_tty {
@@ -133,6 +133,7 @@
     vbi_fetch_vt_page(tty->vbi->dec,&tty->pg,tty->pgno,tty->subno,
 		      VBI_WST_LEVEL_1p5,25,1);
     vbi_fix_head(tty,tty->pg.text);
+#ifdef WITH_LINUX_FB_H
     if (have_fb) {
 	vbi_draw_vt_page_region(&tty->pg, fb_fmt,
 				fb_mem + fb_mem_offset,
@@ -142,13 +143,16 @@
 				0,1);
 	
     } else {
+#endif
 	len = vbi_export_txt(data,nl_langinfo(CODESET),25*41*8,
 			     &tty->pg,&vbi_fullrect,VBI_ANSICOLOR);
 	tty_goto(0,0);
 	fwrite(data,len,1,stderr);
 	tty_goto(42,0);
 	free(data);
+#ifdef WITH_LINUX_FB_H
     }
+#endif
 }
 
 static void
@@ -166,6 +170,7 @@
     vbi_fetch_vt_page(tty->vbi->dec,&pg,pgno,subno,
 		      VBI_WST_LEVEL_1p5,1,1);
     vbi_fix_head(tty,pg.text);
+#ifdef WITH_LINUX_FB_H
     if (have_fb) {
 	vbi_draw_vt_page_region(&pg, fb_fmt,
 				fb_mem + fb_mem_offset,
@@ -175,13 +180,16 @@
 				0,1);
 	
     } else {
+#endif
 	len = vbi_export_txt(data,nl_langinfo(CODESET),41*8,
 			     &pg,&head,VBI_ANSICOLOR);
 	tty_goto(0,0);
 	fwrite(data,len,1,stderr);
 	tty_goto(42,0);
 	free(data);
+#ifdef WITH_LINUX_FB_H
     }
+#endif
 }
 
 static void
@@ -232,7 +240,7 @@
     vbi = vbi_open(device,debug,sim);
     if (NULL == vbi)
 	exit(1);
-
+#ifdef WITH_LINUX_FB_H
     if (0 /* 0 == fb_probe() */ ) {
 	have_fb = 1;
 	fb_init(NULL,NULL,0);
@@ -240,14 +248,21 @@
 	fb_switch_init();
 	switch_last = fb_switch_state;
     } else {
+#endif
 	if (-1 != ioctl(0,TIOCGWINSZ,&win) && win.ws_row < 26) {
 	    fprintf(stderr,"Terminal too small (need 26 rows, have %d)\n",
 		    win.ws_row);
 	    exit(1);
 	}
+#ifdef WITH_LINUX_FB_H
     }
+#endif
     tty_raw();
+#ifdef WITH_LINUX_FB_H
     have_fb ? fb_clear() : tty_clear();
+#else
+    tty_clear();
+#endif
 
     tty = malloc(sizeof(*tty));
     memset(tty,0,sizeof(*tty));
@@ -264,14 +279,18 @@
 	rc = select(vbi->fd+1,&set,NULL,NULL,&tv);
 	if (-1 == rc) {
 	    tty_restore();
+#ifdef WITH_LINUX_FB_H
 	    if (have_fb)
 		fb_cleanup();
+#endif
 	    perror("select");
 	    exit(1);
 	}
 	if (0 == rc) {
+#ifdef WITH_LINUX_FB_H
 	    if (have_fb)
 		fb_cleanup();
+#endif
 	    tty_restore();
 	    fprintf(stderr,"oops: timeout\n");
 	    exit(1);
@@ -289,7 +308,11 @@
 		    break;
 		case 'L' & 0x1f:
 		    /* refresh */
+#ifdef WITH_LINUX_FB_H
 		    have_fb ? fb_clear() : tty_clear();
+#else
+		    tty_clear();
+#endif
 		    vbi_render_page(tty);
 		    break;
 		case 'i':
@@ -339,8 +362,10 @@
 	    vbi_hasdata(vbi);
 	}
     }
+#ifdef WITH_LINUX_FB_H
     if (have_fb)
 	fb_cleanup();
+#endif
     tty_goto(0,0);
     tty_restore();
 }
