--- topaz/msgbuff.cc.orig	Wed Dec  4 23:02:26 2002
+++ topaz/msgbuff.cc	Fri Dec 27 04:36:46 2002
@@ -30,6 +30,8 @@
 #include "msgbuff.h"
 #include "kanji.h"
 
+using namespace std;
+
 extern int tabnumber;
 extern WINDOW *menuwin, *msgwin, *sepwin ,*titlewin;
 
