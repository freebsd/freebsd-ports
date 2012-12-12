Index: src/db_file.c
diff -u -p src/db_file.c.orig src/db_file.c
--- src/db_file.c.orig	2010-08-09 02:39:31.000000000 +0900
+++ src/db_file.c	2012-10-30 02:25:43.671508126 +0900
@@ -674,7 +674,7 @@ int db_writelong(AIDE_OFF_TYPE i,FILE* f
     dofprintf(" ");
   }
   
-#if SIZEOF_OFF64_T == SIZEOF_LONG_LONG
+#if AIDE_OFF_TYPE == off64_t && SIZEOF_OFF64_T == SIZEOF_LONG_LONG || AIDE_OFF_TYPE == off_t && SIZEOF_OFF_T == SIZEOF_LONG_LONG
   return dofprintf("%lli",(long long)i);
 #else
   return dofprintf("%li",i);
