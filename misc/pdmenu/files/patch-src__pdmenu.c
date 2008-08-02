--- src/pdmenu.c.orig	2008-07-23 01:56:11.000000000 +0900
+++ src/pdmenu.c	2008-07-30 01:31:58.000000000 +0900
@@ -230,8 +230,10 @@
   strcpy(FG[8],UNSEL_MENU_FG_DEFAULT);
   strcpy(BG[8],UNSEL_MENU_BG_DEFAULT);
  
+#if (defined(SLANG_VERSION) && (SLANG_VERSION >= 20000))
   /* Enable utf-8 in slang. */
   SLutf8_enable(-1);
+#endif
 
   /* Parse parameters and load pdmenurc file. */
   m=GetConfig(argc,argv);
