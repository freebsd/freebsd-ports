--- apps/geoipexport.c.orig	Tue Dec 17 13:35:21 2002
+++ apps/geoipexport.c	Thu Dec 26 20:41:20 2002
@@ -37,7 +37,7 @@
 
 char * _num_to_addr (unsigned long num) {
 	char * addr = malloc(15);
-	sprintf(addr, "%u.%u.%u.%u",
+	sprintf(addr, "%u.%u.%u.%lu",
 					 (int)floor(num/16777216),
 					 ((int)floor(num/65536)) % 256,
 					 ((int)floor(num/256)) % 256,
@@ -76,9 +76,9 @@
 int main (int argc, char *argv[]) {
   FILE *f;
   GeoIPBitReader *gibr;
-	int databaseType, record, val;
-	int exportType;
-	ulong beginIp = 0, endIp = 0;
+	int databaseType, record, val = 0;
+	int exportType = 0;
+	unsigned long beginIp = 0, endIp = 0;
 
   if (argc < 4) {
     usage();
@@ -127,7 +127,7 @@
 				full_csv_export(databaseType, beginIp, endIp - 1, val, f);
 			}
 			beginIp = endIp;
-			printf("setting beginIp to %d\n",beginIp);
+			printf("setting beginIp to %lu\n",beginIp);
 		} else {
 			/* record = netmask - 1 */
 			endIp += (1 << (31 - record));
