--- src/sendmail.cc
+++ src/sendmail.cc
@@ -84,7 +84,7 @@
   str[varlen] = '=';
   memcpy(str+varlen+1, val, vallen);
   str[varlen+vallen+1] = 0;
-  return putenv(str);
+  return putenv(strdup(str));
 }
 #endif
 
