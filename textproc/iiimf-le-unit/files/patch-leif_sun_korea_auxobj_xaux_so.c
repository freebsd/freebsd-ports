--- leif/sun_le_korea/auxobj/xaux_so.c	Sat Mar 27 10:46:45 2004
+++ leif/sun_le_korea/auxobj/xaux_so.c	Wed Feb 16 20:46:40 2005
@@ -19,7 +19,7 @@
 
 #define	XAUX_CLASS_MAX		7
 
-#define	XAUX_EXT_DIR 		"/usr/lib/im/locale/ko_KR/"
+#define	XAUX_EXT_DIR 		(IMDIR "/locale/ko_KR/")
 
 CARD16	aux_utfname_palette[] = {
 	'c','o','m','.','s','u','n','.',
