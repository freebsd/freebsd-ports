--- src/data/file.cc.old	Fri Jan  7 14:35:43 2005
+++ src/data/file.cc	Fri Jan  7 14:36:35 2005
@@ -19,8 +19,9 @@
 		  (flags & in && flags & out ? O_RDWR :
 		   (flags & in  ? O_RDONLY : 0) |
 		   (flags & out ? O_WRONLY : 0)) |
-		  
+#if defined(Linux) 
 		  (flags & largefile ? O_LARGEFILE : 0) |
+#endif
 		  (flags & create    ? O_CREAT     : 0) |
 		  (flags & truncate  ? O_TRUNC     : 0) |
 		  (flags & nonblock  ? O_NONBLOCK  : 0),
