--- src/xitk/oxine/mediamarks.c.orig	Tue Sep 20 23:58:50 2005
+++ src/xitk/oxine/mediamarks.c	Wed Sep 21 00:13:23 2005
@@ -439,34 +439,19 @@
 
 static void parse_m3u(const char *mrl, list_t *items) {
   FILE *file;
-  char **line;
-  int *n;
-  int a;
+  char line[1024];
 
   file = fopen(mrl, "r");
-  if(!file) return ;
+  if(!file) return;
 
-  n = ho_new(size_t);
-  line = ho_new(char *);
-
-  *line = NULL;
-  *n = 0;
-  a = getline(line, n, file);
-  if(a<=0) return;
-
-  while((a = getline(line, n, file))>0) {
-    char *str;
+  while(fgets(line, sizeof(line) - 1, file) != NULL) {
     playitem_t *item;
 
-    if(*line[0] == '#') continue;
-    str = strndup(*line, a-1);
+    if(line[0] == '#') continue;
     /* printf("%s\n", str); */
-    item = playitem_new (TYPE_REG, basename(str), str, list_new());
-    ho_free(str);
+    item = playitem_new (TYPE_REG, basename(line), line, list_new());
     playitem_append(item, items);
   }
-  ho_free(line);
-  ho_free(n);
   fclose(file);
 }
 
