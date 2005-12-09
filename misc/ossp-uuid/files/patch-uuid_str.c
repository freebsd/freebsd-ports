--- uuid_str.c.orig	Tue Mar 29 21:39:51 2005
+++ uuid_str.c	Thu Dec  8 18:46:13 2005
@@ -690,8 +690,10 @@
 {
     char *rv;
     int n;
+    va_list ap_tmp;
 
-    n = str_vsnprintf(NULL, 0, fmt, ap);
+    va_copy(ap_tmp, ap);
+    n = str_vsnprintf(NULL, 0, fmt, ap_tmp);
     if ((rv = (char *)malloc(n+1)) == NULL)
         return NULL;
     str_vsnprintf(rv, n+1, fmt, ap);
@@ -720,6 +722,7 @@
 {
     int rv;
     size_t n;
+    va_list ap_tmp;
 
     if (str == NULL)
         return -1;
@@ -729,7 +732,8 @@
     }
     else {
         n = strlen(*str);
-        rv = str_vsnprintf(NULL, 0, fmt, ap);
+        va_copy(ap_tmp, ap);
+        rv = str_vsnprintf(NULL, 0, fmt, ap_tmp);
         if ((*str = (char *)realloc(*str, n+rv+1)) == NULL)
             return -1;
         str_vsnprintf((*str)+n, rv+1, fmt, ap);
