Workaround for a sscanf(3) bug in the FreeBSD 5-CURRENT.

$FreeBSD$

--- util.c	2001/06/02 10:41:42	1.1
+++ util.c	2001/06/02 11:14:20
@@ -36,10 +36,19 @@
   double loc = 0;
   float sub;
   int i = 0;
+  int len;
+  char *tmp;
+
+  len = strlen(str);
+  if (str[len - 1] == 'e') {
+      tmp = alloca(len);
+      strlcpy(tmp, str, len);
+  } else
+      tmp = str;
 
   while(1)
     {
-      sscanf(&str[i], "%f", &sub);
+      sscanf(&tmp[i], "%f", &sub);
       loc += sub*factor;
 
       // Skip all spaces and tabs
