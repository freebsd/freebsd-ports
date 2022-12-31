--- texk/xdvik/jfm.h.orig	2015-07-19 18:49:42 UTC
+++ texk/xdvik/jfm.h
@@ -0,0 +1,54 @@
+/**********************************************
+ *  Copyright (C) Atsuo Kawaguchi, 1987.
+ *         (atsuo@sanken.osaka-u.junet)
+ *  Modified by Y. Hayashi from jxdvi-NEWS
+ *	   (hayashi@me.aoyama.ac.jp)
+ **********************************************/
+/* Lisense is shown in jfm.c */
+
+#ifndef JFM_H_
+#define JFM_H_
+
+#define	J_ID 0		/* id */
+#define	J_NT 1		/* number of words in the char_type table */
+#define	J_LF 2		/* length of entire file */
+#define	J_LH 3		/* length of header */
+#define	J_BC 4		/* smallest char_type */
+#define	J_EC 5		/* largest char_type */
+#define	J_NW 6		/* number of width table */
+#define	J_NH 7		/* number of height table */
+#define	J_ND 8		/* number of depth table */
+#define	J_NI 9		/* number of italic correctiuon table */
+#define	J_NL 10		/* number of glue/kern talbe */
+#define	J_NK 11
+#define	J_NG 12
+#define	J_NP 13
+
+struct jfm_char_type {
+    unsigned short	code;		/* JIS code */
+    unsigned short	index;		/* index to char_info */
+};
+
+struct jfm_char_info {
+    unsigned char	width_ix;		/* index to width */
+    unsigned char	height_depth_ix;	/* index to height & depth */
+    unsigned char	italic_ix_tag;		/* index to italic & tag */
+    unsigned char	remainder_ix;		/* index to remainder */
+};
+
+struct jfm {
+    char	*fontname;			/* font name (min10, etc.) */
+    short	table[(J_NP+1)];		/* table */
+    unsigned long check_sum;			/* header */
+    unsigned long design_size;		
+    struct jfm_char_type *type;
+    struct jfm_char_info *info;
+    unsigned long *width;
+    unsigned long *height;
+    unsigned long *depth;
+    unsigned long *italic;
+};
+
+struct jfm *read_jfm(FILE *fp, char *fontname);
+
+#endif /* JFM_H_ */
