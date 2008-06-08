diff -urN -x .svn ../../branches/vendor/bsdproxy/write_data.c ./write_data.c
--- ../../branches/vendor/bsdproxy/write_data.c	2008-06-08 22:30:53.000000000 +0300
+++ ./write_data.c	2008-06-08 23:01:18.000000000 +0300
@@ -19,7 +19,7 @@
   int            rm = 0;
   int            qe = 0;
   GSList         *l;
-  char           *ct[2] = { "CLIENT", "SERVER" }; 
+  const char     *ct[2] = { "CLIENT", "SERVER" }; 
 
   /* 
      if this is the first data we're reading over this connection,
