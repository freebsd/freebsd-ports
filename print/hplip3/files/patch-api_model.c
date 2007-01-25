--- api/model.c.orig    2006-10-18 20:58:33.000000000 +0200
+++ api/model.c 2007-01-19 15:58:49.000000000 +0100
@@ -269,7 +269,7 @@ static int DelList()
 /* Parse *.inc file. */
 static int ParseInc(char *incFile)
 {
-   FILE *fp;
+   FILE *fp = NULL;
    struct list_head *p;
    LabelRecord *pl;
    char rcbuf[255];
