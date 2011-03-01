--- a/scan.c
+++ b/scan.c
@@ -2866,8 +2866,8 @@ int main (int argc, char **argv)
 		bad_usage(argv[0]);
 		return -1;
 		}
-	if  (((adapter > 7) && (adapter != 999)) || (adapter < 0)) {
-		info("Invalid adapter: out of range (0..7)\n");
+	if  (((adapter > 255) && (adapter != 999)) || (adapter < 0)) {
+		info("Invalid adapter: out of range (0..255)\n");
 		bad_usage(argv[0]);
 		return -1;
 		}
