--- libGeoIP/GeoIPUpdate.c.orig	Tue Nov 19 13:03:24 2002
+++ libGeoIP/GeoIPUpdate.c	Tue Nov 19 13:05:44 2002
@@ -45,7 +45,8 @@
 	char * f_str;
 	f_str = malloc(strlen(str)+1);
 	strcpy(f_str,str);
-	(*f)(f_str);
+	if (f != NULL)
+		(*f)(f_str);
 }
 
 short int GeoIP_update_database (char * license_key, int verbose, void (*f)( char *)) {
@@ -73,7 +74,8 @@
 	if ((cur_db_fh = fopen (GeoIPDBFileName, "rb")) == NULL) {
 		f_str = malloc(strlen(NoCurrentDB) + strlen(GeoIPDBFileName) - 1);
 		sprintf(f_str,NoCurrentDB, GeoIPDBFileName);
-		(*f)(f_str);
+		if (f != NULL)
+			(*f)(f_str);
 	} else {
 		MD5Init(&context);
 		while ((len = fread (buffer, 1, 1024, cur_db_fh)) > 0)
@@ -84,7 +86,8 @@
 			sprintf (&hex_digest[2*i], "%02x", digest[i]);
 		f_str = malloc(strlen(MD5Info) + strlen(hex_digest) - 1);
 		sprintf(f_str, MD5Info, hex_digest);
-		(*f)(f_str);
+		if (f != NULL)
+			(*f)(f_str);
 	}
 
 	hostlist = gethostbyname(GeoIPUpdateHost);
@@ -165,7 +168,8 @@
 	if (verbose == 1) {
 		f_str = malloc(strlen(SavingGzip) + strlen(file_path_gz) - 1);
 		sprintf(f_str,SavingGzip,file_path_gz);
-		(*f)(f_str);
+		if (f != NULL)
+			(*f)(f_str);
 	}
 	comp_fh = fopen(file_path_gz, "wb");
 
