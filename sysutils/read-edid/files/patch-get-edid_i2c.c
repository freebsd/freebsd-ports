--- get-edid/i2c.c.orig	2014-11-21 11:52:13 UTC
+++ get-edid/i2c.c
@@ -15,7 +15,7 @@
 
 //Ideas (but not too much actual code) taken from i2c-tools. Thanks guys.
 
-int quiet;
+extern int quiet;
 
 #define display(...) if (quiet == 0) { fprintf(stderr, __VA_ARGS__); }
 
@@ -24,7 +24,13 @@ int open_i2c_dev(int i2cbus) {
 	char filename[16];
 	unsigned long funcs;
 
-	sprintf(filename, "/dev/i2c-%d", i2cbus);
+	sprintf(filename,
+#if defined(__linux__)
+	        "/dev/i2c-%d",
+#elif defined(__FreeBSD__)
+	        "/dev/iic%d",
+#endif
+	        i2cbus);
 	i2cfile = open(filename, O_RDWR);
 
 	if (i2cfile < 0 && errno == ENOENT) {
