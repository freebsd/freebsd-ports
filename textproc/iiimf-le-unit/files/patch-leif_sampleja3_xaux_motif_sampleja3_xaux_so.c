--- leif/sampleja3/xaux_motif/sampleja3_xaux_so.c	Fri Mar 16 00:52:22 2001
+++ leif/sampleja3/xaux_motif/sampleja3_xaux_so.c	Wed Feb 16 20:43:20 2005
@@ -63,7 +63,7 @@
                         'L','o','o','k','u','p','A','u','x',
 };
 
-#define		XAUX_EXT_DIR	"/usr/lib/im/locale/ja/sampleja3/xaux/motif/"
+#define		XAUX_EXT_DIR	(IMDIR "/locale/ja/sampleja3/xaux/motif/")
 
 xaux_class_t xaux_classes[AUX_CLASS_MAX + 1] = {
 	{
