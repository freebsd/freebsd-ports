--- lex7000/src/gdevlx7.c.orig	Fri Dec 31 17:22:48 2004
+++ lex7000/src/gdevlx7.c	Fri Dec 31 17:24:39 2004
@@ -615,14 +615,14 @@
    dprintf2("Current resolution is %f width x %f height dpi\n",
 	 pdev->x_pixels_per_inch, pdev->y_pixels_per_inch );
 #endif
-   pbuf = (byte *)gs_malloc(rpbufsize, 1, "lxmgen_print_page(pbuf)");
+   pbuf = (byte *)gs_malloc(pdev->memory, rpbufsize, 1, "lxmgen_print_page(pbuf)");
    if (pbuf == NULL)
       return_error(gs_error_VMerror);
 
-   outbuf = (byte *)gs_malloc(OUT_BUF_SIZE, 1, "lxmgen_print_page(outbuf)");
+   outbuf = (byte *)gs_malloc(pdev->memory, OUT_BUF_SIZE, 1, "lxmgen_print_page(outbuf)");
    if (outbuf == NULL)
    {
-      gs_free((char*)pbuf,pbufsize, 1, "lxmgen_print_page(pbuf)");
+      gs_free(pdev->memory, (char*)pbuf,pbufsize, 1, "lxmgen_print_page(pbuf)");
       return_error(gs_error_VMerror);
    }
    /* initialize begin of outbuf ... */
@@ -799,8 +799,8 @@
 
    /* eject page */
    lex_eject(prn_stream);
-   gs_free((char*)pbuf,rpbufsize, 1, "lxmgen_print_page(pbuf)");
-   gs_free((char*)outbuf,OUT_BUF_SIZE, 1, "lxmgen_print_page(outbuf)");
+   gs_free(pdev->memory, (char*)pbuf,rpbufsize, 1, "lxmgen_print_page(pbuf)");
+   gs_free(pdev->memory, (char*)outbuf,OUT_BUF_SIZE, 1, "lxmgen_print_page(outbuf)");
 
 #ifdef DEBUG
    dprintf1("[%s] print_page() end\n",pdev->dname);
