--- a/main.c
+++ b/main.c
@@ -2315,7 +2315,7 @@ int main (int argc, const char * argv[])
 	if (argc < 5) { USAGE }
 	delta_bright = atoi(argv[4]);
 #else
-	if (argc < 2) { USAGE }
+	if (argc < 3) { USAGE }
 #endif
 	fact_x = atof(argv[1]);
 	sscanf(argv[2], "%lld", &orim2vsize);
