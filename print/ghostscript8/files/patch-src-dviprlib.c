--- src/dviprlib.c.orig	Tue May 13 16:14:09 1997
+++ src/dviprlib.c	Tue May 24 21:41:09 2005
@@ -39,8 +39,8 @@
 
 
 /*--- forward declarations ---*/
-private int dviprt_read_S_cfg(P2(dviprt_cfg_t *,dviprt_cfg_i *));
-private int dviprt_read_QR_cfg(P2(dviprt_cfg_t *,dviprt_cfg_i *));
+private int dviprt_read_S_cfg(dviprt_cfg_t *,dviprt_cfg_i *);
+private int dviprt_read_QR_cfg(dviprt_cfg_t *,dviprt_cfg_i *);
      
 /*--- library functions ---*/
 int 
@@ -429,21 +429,21 @@
 
 /*--- forward declarations ---*/
 private int dviprt_set_select
-  (P4(dviprt_cfg_item_t *,uchar **,dviprt_cfg_t *,dviprt_cfg_i *));
+  (dviprt_cfg_item_t *,uchar **,dviprt_cfg_t *,dviprt_cfg_i *);
 private int dviprt_set_integer
-  (P4(dviprt_cfg_item_t *, uchar *, dviprt_cfg_t *,dviprt_cfg_i *));
+  (dviprt_cfg_item_t *, uchar *, dviprt_cfg_t *,dviprt_cfg_i *);
 private int dviprt_set_strings
-  (P4(dviprt_cfg_item_t *,uchar *,dviprt_cfg_t *,dviprt_cfg_i *));
+  (dviprt_cfg_item_t *,uchar *,dviprt_cfg_t *,dviprt_cfg_i *);
 private int dviprt_set_rpexpr
-  (P6(dviprt_cfg_item_t *,uchar *,int , dviprt_cfg_t *,dviprt_cfg_i *,int));
+  (dviprt_cfg_item_t *,uchar *,int , dviprt_cfg_t *,dviprt_cfg_i *,int);
 private int dviprt_set_code
-  (P4(dviprt_cfg_item_t *,uchar *,dviprt_cfg_t *,dviprt_cfg_i *));
+  (dviprt_cfg_item_t *,uchar *,dviprt_cfg_t *,dviprt_cfg_i *);
 
-private long dviprt_oct2long(P3(uchar *,uchar *,uchar **));
-private long dviprt_dec2long(P3(uchar *,uchar *,uchar **));
-private long dviprt_hex2long(P3(uchar *,uchar *,uchar **));
+private long dviprt_oct2long(uchar *,uchar *,uchar **);
+private long dviprt_dec2long(uchar *,uchar *,uchar **);
+private long dviprt_hex2long(uchar *,uchar *,uchar **);
      
-private int dviprt_printtokenerror(P4(dviprt_cfg_i *,char *,int ,int));
+private int dviprt_printtokenerror(dviprt_cfg_i *,char *,int ,int);
      
 /*--- macros ---*/
 #define strlcmp(tmplt,str,len) \
@@ -1433,7 +1433,11 @@
 char *dviprt_prtcodename[] = { CFG_PRTCODE_NAME, NULL };
 char *dviprt_encodename[] = { CFG_ENCODE_NAME, NULL };
 
+#if 0
 private FILE *dviprt_messagestream = stderr;
+#else  /* patch for glibc 2.1.x by Shin Fukui <shita@april.co.jp> */
+private FILE *dviprt_messagestream;
+#endif
 
 /*--- library functions ---*/
 int
@@ -1568,16 +1572,16 @@
 
 
 /*--- forward declarations ---*/
-private int dviprt_getmaximalwidth(P1(dviprt_print *));
-private int dviprt_flush_buffer(P2(dviprt_print *,uchar far *));
-private int dviprt_output_transpose(P3(dviprt_print *,uchar far *,uint ));
-private int dviprt_output_nontranspose(P3(dviprt_print *,uchar far *,uint ));
-private int dviprt_output_nontranspose_reverse(P3(dviprt_print *,uchar far *,uint ));
-private int dviprt_reverse_bits(P2(uchar far *,uint));
-private int dviprt_transpose8x8(P4(uchar far *,uint, uchar far *,uint));
-private int dviprt_output_expr(P4(dviprt_print *,int,uint,uint));
-private int dviprt_default_outputproc(P3(uchar far *,long ,void *));
-private long dviprt_getbuffersize(P1(dviprt_print *));
+private int dviprt_getmaximalwidth(dviprt_print *);
+private int dviprt_flush_buffer(dviprt_print *,uchar far *);
+private int dviprt_output_transpose(dviprt_print *,uchar far *,uint);
+private int dviprt_output_nontranspose(dviprt_print *,uchar far *,uint);
+private int dviprt_output_nontranspose_reverse(dviprt_print *,uchar far *,uint);
+private int dviprt_reverse_bits(uchar far *,uint);
+private int dviprt_transpose8x8(uchar far *,uint, uchar far *,uint);
+private int dviprt_output_expr(dviprt_print *,int,uint,uint);
+private int dviprt_default_outputproc(uchar far *,long ,void *);
+private long dviprt_getbuffersize(dviprt_print *);
      
 /*--- library functions ---*/
 long
@@ -1618,7 +1622,7 @@
 int
   dviprt_setstream
 #ifdef __PROTOTYPES__
-  (dviprt_print *pprint,int (*func)(P3(uchar far *,long ,void*)),void *pstream)
+  (dviprt_print *pprint,int (*func)(uchar far *,long ,void*),void *pstream)
 #else
 (pprint,func,pstream)
 dviprt_print *pprint;
@@ -2264,19 +2268,19 @@
 #define DVIPRT_SUPPORT_PCL 1
 
 /*--- forward declarations ---*/
-private long dviprt_null_getworksize(P2(dviprt_print *,long ));
-private long dviprt_null_encode(P3(dviprt_print *,long ,int ));
-private long dviprt_hex_getworksize(P2(dviprt_print *,long ));
-private long dviprt_hex_encode(P3(dviprt_print *,long ,int ));
+private long dviprt_null_getworksize(dviprt_print *,long );
+private long dviprt_null_encode(dviprt_print *,long ,int );
+private long dviprt_hex_getworksize(dviprt_print *,long );
+private long dviprt_hex_encode(dviprt_print *,long ,int );
 #if DVIPRT_SUPPORT_FAX
-private long dviprt_fax_getworksize(P2(dviprt_print *,long ));
-private long dviprt_fax_encode(P3(dviprt_print *,long ,int ));
+private long dviprt_fax_getworksize(dviprt_print *,long );
+private long dviprt_fax_encode(dviprt_print *,long ,int );
 #endif
 #if DVIPRT_SUPPORT_PCL
-private long dviprt_pcl1_getworksize(P2(dviprt_print *,long ));
-private long dviprt_pcl1_encode(P3(dviprt_print *,long ,int ));
-private long dviprt_pcl2_getworksize(P2(dviprt_print *,long ));
-private long dviprt_pcl2_encode(P3(dviprt_print *,long ,int ));
+private long dviprt_pcl1_getworksize(dviprt_print *,long );
+private long dviprt_pcl1_encode(dviprt_print *,long ,int );
+private long dviprt_pcl2_getworksize(dviprt_print *,long );
+private long dviprt_pcl2_encode(dviprt_print *,long ,int );
 #endif
      
 private dviprt_encoder dviprt_encoder_list[] = {
@@ -2468,9 +2472,9 @@
   int o_count;
   int o_bufcount;
 } FaxEncodeInfo;
-private int dviprt_fax_set_white(P2(int,FaxEncodeInfo *));
-private int dviprt_fax_set_black(P2(int,FaxEncodeInfo *));
-private int dviprt_fax_set_bitcount(P2(FaxEncode_t *,FaxEncodeInfo *));
+private int dviprt_fax_set_white(int,FaxEncodeInfo *);
+private int dviprt_fax_set_black(int,FaxEncodeInfo *);
+private int dviprt_fax_set_bitcount(FaxEncode_t *,FaxEncodeInfo *);
      
 private long 
 dviprt_fax_encode(dviprt_print *pprint,long s,int f)
