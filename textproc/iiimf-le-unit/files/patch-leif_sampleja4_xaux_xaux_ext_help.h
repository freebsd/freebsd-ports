--- leif/sampleja4/xaux/xaux_ext_help.h	Fri Jun 27 11:41:21 2003
+++ leif/sampleja4/xaux/xaux_ext_help.h	Wed Feb 16 20:48:34 2005
@@ -52,6 +52,6 @@
 extern void HelpInvoke(char *);
 #endif /* USE_CDE_HELP */
 
-#define	DEFAULT_HELP_PATH "file:/usr/lib/im/locale/ja/sampleja4/help/"
+#define	DEFAULT_HELP_PATH ("file:" IMDIR "/locale/ja/sampleja4/help/")
 
 #endif	/* !XAUX_EXT_HELP_H */
