--- ./src/sg_ses.c.orig	2013-05-08 06:21:30.000000000 -0700
+++ ./src/sg_ses.c	2013-09-17 15:31:55.127287996 -0700
@@ -210,10 +210,10 @@
 static struct join_row_t join_arr[MX_JOIN_ROWS];
 static struct join_row_t * join_arr_lastp = join_arr + MX_JOIN_ROWS - 1;
 
-static unsigned char enc_stat_rsp[MX_ALLOC_LEN];
-static unsigned char elem_desc_rsp[MX_ALLOC_LEN];
-static unsigned char add_elem_rsp[MX_ALLOC_LEN];
-static unsigned char threshold_rsp[MX_ALLOC_LEN];
+static unsigned char enc_stat_rsp[MX_ALLOC_LEN] __attribute__ ((aligned (4096)));
+static unsigned char elem_desc_rsp[MX_ALLOC_LEN] __attribute__ ((aligned (4096)));
+static unsigned char add_elem_rsp[MX_ALLOC_LEN] __attribute__ ((aligned (4096)));
+static unsigned char threshold_rsp[MX_ALLOC_LEN] __attribute__ ((aligned (4096)));
 static int enc_stat_rsp_len;
 static int elem_desc_rsp_len;
 static int add_elem_rsp_len;
