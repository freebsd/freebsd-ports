--- main.c
+++ main.c
@@ -30,7 +30,7 @@ Thanks to Sven Goethel for error resilience patches
 #define NDEBUG // turns off asserts
 #define REMOVE_BYTE_STUFFING	// removes series of 0x00
 
-#if defined(__ppc__) || defined(__ppc64__)
+#if (defined(__ppc__) || defined(__ppc64__)) && !defined(__clang__)
 	#define USE_GLOBAL_REGISTER // assign registers to bit buffers
 #elif defined(__i386__) || defined (__x86_64__)
 	// #define USE_GLOBAL_REGISTER // assign registers to bit buffers
@@ -2315,7 +2315,7 @@ int main (int argc, const char * argv[])
 	if (argc < 5) { USAGE }
 	delta_bright = atoi(argv[4]);
 #else
-	if (argc < 2) { USAGE }
+	if (argc < 3) { USAGE }
 #endif
 	fact_x = atof(argv[1]);
 	sscanf(argv[2], "%lld", &orim2vsize);
