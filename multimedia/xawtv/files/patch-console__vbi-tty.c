--- console/vbi-tty.c.orig	2020-05-15 23:32:25 UTC
+++ console/vbi-tty.c
@@ -19,7 +19,7 @@
 #include <sys/types.h>
 #include <sys/ioctl.h>
 
-#include <linux/fb.h>
+/*#include <linux/fb.h>*/
 
 #include "vbi-data.h"
 #include "vbi-tty.h"
@@ -65,7 +65,7 @@ static void tty_goto(int x, int y)
 }
 
 /* --------------------------------------------------------------------- */
-
+#ifdef WITH_LINUX_FB_H
 static int have_fb = 0;
 static int fb_fmt  = VBI_PIXFMT_RGBA32_LE;
 static int switch_last;
@@ -74,7 +74,7 @@ static void fb_clear(void)
 {
     fb_memset(fb_mem+fb_mem_offset,0,fb_fix.smem_len);
 }
-
+#endif
 /* --------------------------------------------------------------------- */
 
 struct vbi_tty {
@@ -133,6 +133,7 @@ vbi_render_page(struct vbi_tty *tty)
     vbi_fetch_vt_page(tty->vbi->dec,&tty->pg,tty->pgno,tty->subno,
 		      VBI_WST_LEVEL_1p5,25,1);
     vbi_fix_head(tty,tty->pg.text);
+#ifdef WITH_LINUX_FB_H
     if (have_fb) {
 	vbi_draw_vt_page_region(&tty->pg, fb_fmt,
 				fb_mem + fb_mem_offset,
@@ -142,13 +143,16 @@ vbi_render_page(struct vbi_tty *tty)
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
@@ -169,6 +173,7 @@ vbi_render_head(struct vbi_tty *tty, int pgno, int sub
     vbi_fetch_vt_page(tty->vbi->dec,&pg,pgno,subno,
 		      VBI_WST_LEVEL_1p5,1,1);
     vbi_fix_head(tty,pg.text);
+#ifdef WITH_LINUX_FB_H
     if (have_fb) {
 	vbi_draw_vt_page_region(&pg, fb_fmt,
 				fb_mem + fb_mem_offset,
@@ -177,13 +182,16 @@ vbi_render_head(struct vbi_tty *tty, int pgno, int sub
 				pg.columns, 1,
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
@@ -234,7 +242,7 @@ void vbi_tty(char *device, int debug, int sim)
     vbi = vbi_open(device,debug,sim);
     if (NULL == vbi)
 	exit(1);
-
+#ifdef WITH_LINUX_FB_H
     if (0 /* 0 == fb_probe() */ ) {
 	have_fb = 1;
 	fb_init(NULL,NULL,0);
@@ -242,14 +250,21 @@ void vbi_tty(char *device, int debug, int sim)
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
@@ -266,14 +281,18 @@ void vbi_tty(char *device, int debug, int sim)
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
@@ -291,7 +310,11 @@ void vbi_tty(char *device, int debug, int sim)
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
@@ -341,8 +364,10 @@ void vbi_tty(char *device, int debug, int sim)
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
