--- uim/uim.h.orig	2013-06-30 04:26:09 UTC
+++ uim/uim.h
@@ -430,7 +430,7 @@ struct uim_code_converter {
  *
  * @return 0 on success, otherwise -1
  */
-int
+long
 uim_init(void);
 
 /**
