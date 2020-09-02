--- tui.c.orig	2020-09-02 08:06:29 UTC
+++ tui.c
@@ -102,7 +102,6 @@ WINDOW * main_win;
 WINDOW * input_win;
 SCREEN * sstderr;
 SCREEN * sstdout;
-srange * ranges;
 
 /**
  * \brief Called to start UI
