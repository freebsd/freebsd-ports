--- epag/gdevepag.c.orig	Sat Jul  8 13:33:09 2000
+++ epag/gdevepag.c	Thu May 26 00:12:48 2005
@@ -417,15 +417,15 @@
   cont->maxY = epag_cont.cRowBuf / cont->bh * cont->bh ;
   if(cont->maxY < cont->bh) cont->maxY = cont->bh;
   
-  cont->bp  = gs_malloc(bpl , cont->maxY, "epag_skip_blank_init(bp)");
-  cont->bp2 = gs_malloc(bpl*3/2+1 , cont->maxY, "epag_skip_blank_init(bp2)");
+  cont->bp  = gs_malloc(pdev->memory, bpl , cont->maxY, "epag_skip_blank_init(bp)");
+  cont->bp2 = gs_malloc(pdev->memory, bpl*3/2+1 , cont->maxY, "epag_skip_blank_init(bp2)");
 
   cont->h = cont->r = 0;
 
-  cont->bubbleTbl=gs_malloc(sizeof(EpagBubble *),cont->maxBx,"bubbleTbl");
+  cont->bubbleTbl=gs_malloc(pdev->memory, sizeof(EpagBubble *),cont->maxBx,"bubbleTbl");
   for(i=0;i<cont->maxBx;i++)
     cont->bubbleTbl[i] = NULL;
-  cont->bubbleBuffer=gs_malloc(sizeof(EpagBubble),cont->maxBx,"bubbleBuffer");
+  cont->bubbleBuffer=gs_malloc(pdev->memory, sizeof(EpagBubble),cont->maxBx,"bubbleBuffer");
   bbtbl = (EpagBubble *)cont->bubbleBuffer;
   for(i=0;i<cont->maxBx-1;i++)
     bbtbl[i].next = &bbtbl[i+1];
@@ -436,9 +436,11 @@
 private void
 epag_page_close(EpagPageCont *cont)
 {
-  gs_free(cont->bp, bpl, cont->maxY, "epag_skip_blank_init(bp)");
-  gs_free(cont->bp2, bpl*3/2+1, cont->maxY, "epag_skip_blank_init(bp2)");
-  gs_free(cont->bubbleBuffer, sizeof(EpagBubble), cont->maxBx,"bubbleBuffer");
+  gx_device* pdev;
+
+  gs_free(pdev->memory, cont->bp, bpl, cont->maxY, "epag_skip_blank_init(bp)");
+  gs_free(pdev->memory, cont->bp2, bpl*3/2+1, cont->maxY, "epag_skip_blank_init(bp2)");
+  gs_free(pdev->memory, cont->bubbleBuffer, sizeof(EpagBubble), cont->maxBx,"bubbleBuffer");
 }
 
 private int
