--- leif/sampleja3/xaux_common/xaux_ext_common.h	Fri Mar 16 00:52:22 2001
+++ leif/sampleja3/xaux_common/xaux_ext_common.h	Wed Feb 16 20:48:29 2005
@@ -97,7 +97,7 @@
 extern void HelpInvoke(char *);
 #endif
 
-#define	DEFAULT_HELP_PATH "file:/usr/lib/im/locale/ja/sampleja3/help/"
+#define	DEFAULT_HELP_PATH ("file:" IMDIR "/locale/ja/sampleja3/help/")
 
 #endif	/* !XAUX_EXT_COMMON_H */
 
