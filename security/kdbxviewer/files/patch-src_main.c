--- src/main.c.orig	2022-09-06 17:00:52 UTC
+++ src/main.c
@@ -159,7 +159,7 @@ void print_key_table(cx9r_kt_group *g, int level) {
 
 // Process commandline
 int main(int argc, char **argv) {
-	long unsigned int len = PATHLEN, opt, flags = 0;
+	size_t len = PATHLEN, opt, flags = 0;
 	char *kdbxfilename = malloc(len), *filename = malloc(len), command = 0,
 		*password = NULL, *self = argv[0] + strlen(argv[0]),
 		*configfilename = strcat(getenv("HOME"), CONFIGFILENAME);
@@ -246,14 +246,14 @@ int main(int argc, char **argv) {
 		*filename = 0;
 		if ((configfile = fopen(configfilename, "r")) != NULL)
 			while (getline(&filename, &len, configfile) != -1) {
-				*(filename+strlen(filename)-1) = 0;
+				filename[strcspn(filename, "\n")] = '\0';
 				// Check the latest found file
-				if ((kdbxfile = fopen(filename, "r")) != NULL) strcpy(kdbxfilename, filename);
+				if ((kdbxfile = fopen(filename, "r")) != NULL) kdbxfilename = strdup(filename);
 				*filename = 0;
 			}
 		if (*kdbxfilename == 0)
 			abort(-7, "No database specified on commandline or in configfile\n");
-		else strcpy(filename, kdbxfilename);
+		else filename = strdup(kdbxfilename);
 	}
 
 	// Set default mode depending on search
