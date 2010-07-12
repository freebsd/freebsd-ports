--- src/apcupsd.c.orig
+++ src/apcupsd.c
@@ -154,7 +154,7 @@ static int fill_items(int sock, PAPCUPSD_S apc) {
 //
 // Conky update function for apcupsd data
 //
-void update_apcupsd(void) {
+int update_apcupsd(void) {
 
 	int i;
 	APCUPSD_S apc;
@@ -225,5 +225,5 @@ void update_apcupsd(void) {
 	// "atomically" copy the data into working set
 	//
 	memcpy(info.apcupsd.items, apc.items, sizeof(info.apcupsd.items));
-	return;
+	return 0;
 }
