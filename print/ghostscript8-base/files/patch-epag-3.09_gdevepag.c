--- epag-3.09/gdevepag.c.orig	2000-07-08 04:33:09 UTC
+++ epag-3.09/gdevepag.c
@@ -102,30 +102,30 @@ typedef struct _epagBubble{
 } EpagBubble;
 
 /* The device descriptors */
-private dev_proc_open_device(epag_open);
-private dev_proc_close_device(epag_close);
-private dev_proc_print_page(epag_print_page);
-private void epag_printer_initialize(gx_device_printer *pdev, FILE *fp,int);
-private dev_proc_print_page(epag_print_page);
-private dev_proc_get_params(epag_get_params);
-private dev_proc_put_params(epag_put_params);
-private void epag_paper_set(gx_device_printer *pdev, FILE *fp);
-private void epag_bubble_flush_all(EpagPageCont *cont);
-private void epag_page_cont_init(gx_device_printer *pdev,FILE *fp,EpagPageCont *cont);
-private void epag_page_close(EpagPageCont *cont);
-private int epag_read_image(EpagPageCont *cont);
-private void epag_process_line(EpagPageCont *cont);
-private int epag_is_black(EpagPageCont *cont, int bx);
-private void epag_rect_add(EpagPageCont *cont,int start,int end);
-private void  epag_bubble_gen(EpagPageCont *cont,
+static dev_proc_open_device(epag_open);
+static dev_proc_close_device(epag_close);
+static dev_proc_print_page(epag_print_page);
+static void epag_printer_initialize(gx_device_printer *pdev, FILE *fp,int);
+static dev_proc_print_page(epag_print_page);
+static dev_proc_get_params(epag_get_params);
+static dev_proc_put_params(epag_put_params);
+static void epag_paper_set(gx_device_printer *pdev, FILE *fp);
+static void epag_bubble_flush_all(EpagPageCont *cont);
+static void epag_page_cont_init(gx_device_printer *pdev,FILE *fp,EpagPageCont *cont);
+static void epag_page_close(EpagPageCont *cont);
+static int epag_read_image(EpagPageCont *cont);
+static void epag_process_line(EpagPageCont *cont);
+static int epag_is_black(EpagPageCont *cont, int bx);
+static void epag_rect_add(EpagPageCont *cont,int start,int end);
+static void  epag_bubble_gen(EpagPageCont *cont,
 			      int x0, int x1, int y0, int y1);
-private void epag_bubble_flush(EpagPageCont *cont,EpagBubble *bbl);
-private void epag_bubble_image_out(EpagPageCont *cont,EpagBubble *bbl);
+static void epag_bubble_flush(EpagPageCont *cont,EpagBubble *bbl);
+static void epag_bubble_image_out(EpagPageCont *cont,EpagBubble *bbl);
 
 /*
  *   デバイスの宣言
  */
-private gx_device_procs prn_epag_procs =
+static gx_device_procs prn_epag_procs =
 prn_params_procs(epag_open, gdev_prn_output_page, epag_close,
 		 epag_get_params, epag_put_params);
 gx_device_printer far_data gs_epag_device =
@@ -140,13 +140,13 @@ prn_device(prn_epag_procs, "epag", 
 static char *epson_remote_start = "\033\001@EJL \r\n";
 
 /* Open the printer, adjusting the margins if necessary. */
-private int
+static int
 epag_open(gx_device *pdev)
 {
   return gdev_prn_open(pdev);
 }
 
-private int
+static int
 epag_close(gx_device *pdev)
 {
   gdev_prn_open_printer(pdev, 1);
@@ -163,7 +163,7 @@ epag_close(gx_device *pdev)
   return gdev_prn_close(pdev);
 }
 
-private int 
+static int 
 epag_print_page(gx_device_printer *pdev, FILE *fp)
 {
   EpagPageCont cont;
@@ -205,7 +205,7 @@ static char can_inits[] ={
   GS, '2', 'a', 'b', 'P',          /* イメージ描画後下へ */
 };
 
-private void
+static void
 epag_printer_initialize(gx_device_printer *pdev, FILE *fp, int copies)
 {
   double xDpi,yDpi;
@@ -260,7 +260,7 @@ epag_printer_initialize(gx_device_printe
     fprintf(fp,"%c%dcoO",GS, copies < 256 ? copies : 255);
 }
 
-private int
+static int
 epag_get_params(gx_device *pdev, gs_param_list *plist)
 {
   int code;
@@ -286,7 +286,7 @@ epag_get_params(gx_device *pdev, gs_para
 }
 
 /* Put properties. */
-private int
+static int
 epag_put_params(gx_device *pdev, gs_param_list *plist)
 {
   param_read_int(plist, "cRowBuf", &epag_cont.cRowBuf);
@@ -380,7 +380,7 @@ void epag_paper_set(gx_device_printer *p
 /*
  * epag_bubble_flush_all: 残っている bubbleを全て出力する。
  */
-private void epag_bubble_flush_all(EpagPageCont *cont)
+static void epag_bubble_flush_all(EpagPageCont *cont)
 {
   int i;
   
@@ -392,7 +392,7 @@ private void epag_bubble_flush_all(EpagP
 /*
  * epag_page_cont_init: EpagPageContの初期化、バッファ確保等
  */
-private void epag_page_cont_init(gx_device_printer *pdev,FILE *fp,
+static void epag_page_cont_init(gx_device_printer *pdev,FILE *fp,
 				 EpagPageCont *cont)
 {
   int bpl;
@@ -417,15 +417,15 @@ private void epag_page_cont_init(gx_devi
   cont->maxY = epag_cont.cRowBuf / cont->bh * cont->bh ;
   if(cont->maxY < cont->bh) cont->maxY = cont->bh;
   
-  cont->bp  = gs_malloc(bpl , cont->maxY, "epag_skip_blank_init(bp)");
-  cont->bp2 = gs_malloc(bpl*3/2+1 , cont->maxY, "epag_skip_blank_init(bp2)");
+  cont->bp  = (byte *)gs_malloc(gs_lib_ctx_get_non_gc_memory_t(), bpl , cont->maxY, "epag_skip_blank_init(bp)");
+  cont->bp2 = (byte *)gs_malloc(gs_lib_ctx_get_non_gc_memory_t(), bpl*3/2+1 , cont->maxY, "epag_skip_blank_init(bp2)");
 
   cont->h = cont->r = 0;
 
-  cont->bubbleTbl=gs_malloc(sizeof(EpagBubble *),cont->maxBx,"bubbleTbl");
+  cont->bubbleTbl = (byte *)gs_malloc(gs_lib_ctx_get_non_gc_memory_t(), sizeof(EpagBubble *),cont->maxBx,"bubbleTbl");
   for(i=0;i<cont->maxBx;i++)
     cont->bubbleTbl[i] = NULL;
-  cont->bubbleBuffer=gs_malloc(sizeof(EpagBubble),cont->maxBx,"bubbleBuffer");
+  cont->bubbleBuffer=gs_malloc(gs_lib_ctx_get_non_gc_memory_t(), sizeof(EpagBubble),cont->maxBx,"bubbleBuffer");
   bbtbl = (EpagBubble *)cont->bubbleBuffer;
   for(i=0;i<cont->maxBx-1;i++)
     bbtbl[i].next = &bbtbl[i+1];
@@ -433,15 +433,15 @@ private void epag_page_cont_init(gx_devi
   cont->freeBubbleList = &bbtbl[0];
 }
 
-private void
+static void
 epag_page_close(EpagPageCont *cont)
 {
-  gs_free(cont->bp, bpl, cont->maxY, "epag_skip_blank_init(bp)");
-  gs_free(cont->bp2, bpl*3/2+1, cont->maxY, "epag_skip_blank_init(bp2)");
-  gs_free(cont->bubbleBuffer, sizeof(EpagBubble), cont->maxBx,"bubbleBuffer");
+  gs_free(gs_lib_ctx_get_non_gc_memory_t(), cont->bp, bpl, cont->maxY, "epag_skip_blank_init(bp)");
+  gs_free(gs_lib_ctx_get_non_gc_memory_t(), cont->bp2, bpl*3/2+1, cont->maxY, "epag_skip_blank_init(bp2)");
+  gs_free(gs_lib_ctx_get_non_gc_memory_t(), cont->bubbleBuffer, sizeof(EpagBubble), cont->maxBx,"bubbleBuffer");
 }
 
-private int
+static int
 epag_read_image(EpagPageCont *cont)
 {
   int bh = cont->bh;
@@ -473,7 +473,7 @@ epag_read_image(EpagPageCont *cont)
 /*
  *    bh行分のラスターデータを処理する
  */
-private void
+static void
 epag_process_line(EpagPageCont *cont)
 {
   int bh = cont->bh;
@@ -502,7 +502,7 @@ epag_process_line(EpagPageCont *cont)
   else epag_rect_add(cont, 0, cont->maxBx-1);
 }
 
-private int
+static int
 epag_is_black(EpagPageCont *cont, int bx)
 {
   int bh  = cont->bh;
@@ -520,7 +520,7 @@ epag_is_black(EpagPageCont *cont, int bx
   return 0;
 }
 
-private void
+static void
 epag_rect_add(EpagPageCont *cont,int start,int end)
 {
   int x0 = start * cont->bw;
@@ -544,7 +544,7 @@ epag_rect_add(EpagPageCont *cont,int sta
   }
 }
 
-private void
+static void
 epag_bubble_gen(EpagPageCont *cont, int x0, int x1, int y0, int y1)
 {
   EpagBubble *bbl;
@@ -569,7 +569,7 @@ epag_bubble_gen(EpagPageCont *cont, int 
   }
 }
 
-private void epag_bubble_flush(EpagPageCont *cont,EpagBubble *bbl)
+static void epag_bubble_flush(EpagPageCont *cont,EpagBubble *bbl)
 {
   int bx,bx0,bx1;
   
@@ -588,7 +588,7 @@ private void epag_bubble_flush(EpagPageC
 
 /* イメージを出力 */
 
-private void
+static void
 epag_bubble_image_out(EpagPageCont *cont,EpagBubble *bbl)
 {
   FILE *fp = cont->fp;
