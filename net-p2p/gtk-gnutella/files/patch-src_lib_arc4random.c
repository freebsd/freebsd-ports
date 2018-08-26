--- src/lib/arc4random.c.orig	2017-10-22 16:12:09 UTC
+++ src/lib/arc4random.c
@@ -298,9 +298,11 @@ arc4random64(void)
 void G_COLD
 arc4random_stir_once(void)
 {
+#ifdef arc4random_stir
 	static once_flag_t done;
 
 	once_flag_run(&done, arc4random_stir);
+#endif
 }
 
 /***
