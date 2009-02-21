--- uim/uim.h.orig	2008-09-07 23:05:06.000000000 +0900
+++ uim/uim.h	2009-01-24 11:20:11.000000000 +0900
@@ -431,7 +431,7 @@ struct uim_code_converter {
  *
  * @return 0 on success, otherwise -1
  */
-int
+long
 uim_init(void);
 
 /**
