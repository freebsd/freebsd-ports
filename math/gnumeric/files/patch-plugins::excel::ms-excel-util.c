--- plugins/excel/ms-excel-util.c.orig	Mon May  7 18:58:07 2001
+++ plugins/excel/ms-excel-util.c	Tue May 22 17:03:18 2001
@@ -383,3 +383,3 @@
 	charset = nl_langinfo (CODESET);
-#elif
+#else
 	{
