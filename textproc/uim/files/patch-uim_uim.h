--- uim/uim.h.orig	2017-08-14 00:07:27 UTC
+++ uim/uim.h
@@ -531,7 +531,7 @@ struct uim_code_converter {
  *
  * @return 0 on success, otherwise -1
  */
-int
+long
 uim_init(void);
 
 /**
