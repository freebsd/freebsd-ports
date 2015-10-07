--- epag-3.09/ert.c.orig	2000-07-08 13:33:09.000000000 +0900
+++ epag-3.09/ert.c	2012-02-13 01:28:55.000000000 +0900
@@ -1,6 +1,8 @@
 /* $Id: ert.c,v 1.3 1998/11/20 10:51:12 nari Exp $ */
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 
 /*
  * EPSON Remoteのコマンドを出力するコマンド
