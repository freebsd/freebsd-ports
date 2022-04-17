--- include/nfsc/libnfs.h
+++ include/nfsc/libnfs.h
@@ -29,7 +29,7 @@
 
 #include <stdint.h>
 #if defined(__ANDROID__) || defined(AROS) || defined(__PPU__) \
- || ( defined(__APPLE__) && defined(__MACH__) )
+ || ( defined(__APPLE__) && defined(__MACH__) ) || defined(__FreeBSD__)
 #include <sys/time.h>
 #else
 #include <time.h>
