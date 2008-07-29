--- bsdtss.h.orig	2004-07-03 00:53:00.000000000 -0700
+++ bsdtss.h	2008-07-24 13:55:53.489372983 -0700
@@ -29,7 +29,7 @@
 #include <stdio.h>
 
 #define DECLARE_TSS(x,ytype,shouldinit,y) \
-	static pthread_key_t _##x##_tss_key=(pthread_key_t)NULL; \
+	static pthread_key_t _##x##_tss_key=(pthread_key_t)0; \
 	\
 	static void _##x##_tss_init(void)\
 	{\
@@ -52,7 +52,7 @@
 	}
 
 #define DECLARE_TSS_WITH_INIT(x,ytype,fn) \
-	static pthread_key_t _##x##_tss_key=(pthread_key_t)NULL; \
+	static pthread_key_t _##x##_tss_key=(pthread_key_t)0; \
 	\
 	static void _##x##_tss_init(void)\
 	{\
