--- programs/xfs/config.cpp.orig	Tue Jan 18 22:31:25 2005
+++ programs/xfs/config.cpp	Tue Jan 18 22:32:13 2005
@@ -8,8 +8,10 @@
 XCOMM in decipoints
 default-point-size = 120
 default-resolutions = 75,75,100,100
+#ifdef FONTCACHE
 
 XCOMM font cache control, specified in KB
 cache-hi-mark = 2048
 cache-low-mark = 1433
 cache-balance = 70
+#endif
