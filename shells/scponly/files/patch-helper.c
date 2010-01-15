--- helper.c.orig	2010-01-05 21:06:05.000000000 -0800
+++ helper.c	2010-01-05 21:06:18.000000000 -0800
@@ -230,7 +230,7 @@
 						return 1;
 					}
 				}
-#elif
+#else
 				/*
 				 * make sure that processing doesn't continue if we can't validate a rsync check
 				 * and if the getopt flag is set.
