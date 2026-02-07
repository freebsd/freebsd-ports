diff -ur ../../xbuffy-3.3.bl.3/xbuffy.c ./xbuffy.c
--- ../../xbuffy-3.3.bl.3/xbuffy.c	Wed Jul  1 19:53:44 1998
+++ ./xbuffy.c	Tue May  8 13:14:21 2001
@@ -177,11 +177,7 @@
     int num = 0;
     Arg args[5];
     int nargs;
-    static BoxInfo_t *tempNews = 0;
     BoxInfo_t *currentBox;
-    int found;
-    static char *mailHeader = NULL;
-    int headerSize;
     Boolean beenTouched;
     Boolean isIcon = FALSE;
 
