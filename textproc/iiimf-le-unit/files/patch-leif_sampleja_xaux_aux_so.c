--- leif/sampleja/xaux/aux_so.c	Fri Mar 16 00:52:22 2001
+++ leif/sampleja/xaux/aux_so.c	Wed Feb 16 20:42:40 2005
@@ -72,7 +72,7 @@
 #define HTT_AUX_PROP_NAME	"htt_aux_sample_prop"
 #define HTT_AUX_PROP1_NAME	"htt_aux_sample_prop1"
 
-#define	AUX_EXT			"/usr/lib/im/locale/ja/sampleja/aux_ext"
+#define	AUX_EXT			(IMDIR "/locale/ja/sampleja/aux_ext")
 
 typedef struct _aux_icid {
 	aux_t *			aux;
