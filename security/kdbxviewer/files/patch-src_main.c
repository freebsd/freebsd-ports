--- src/main.c.orig	2021-10-10 14:14:08 UTC
+++ src/main.c
@@ -198,7 +198,7 @@ int main(int argc, char **argv) {
 		case 'i':
 		case 'h':
 		case 'V':
-			if (command != 0) abort(-1, "%sMultiple commands not allowed\n", ERRC);
+			if (command != 0) abort(-1, "%sMultiple commands not allowed%s\n", ERRC, NORMAL);
 			command = opt;
 			break;
 		case 'v':
@@ -215,15 +215,15 @@ int main(int argc, char **argv) {
 			searchall = TRUE;
 		case 's':
 			if (search != NULL)
-				abort(-2, "%sSuperfluous search term: %s\n", ERRC, optarg);
+				abort(-2, "%sSuperfluous search term: %s%s\n", ERRC, optarg, NORMAL);
 			search = optarg;
 			break;
 		case 'd':
 			if ((kdbxfile = fopen(optarg, "r")) == NULL)
-				abort(-3, "%sCan't open database file: %s\n", ERRC, optarg);
+				abort(-3, "%sCan't open database file: %s%s\n", ERRC, optarg, NORMAL);
 			kdbxfilename = optarg;
 		default:
-			abort(-4, "%sUnrecognized argument -%s\n", ERRC, argv[optind]);
+			abort(-4, "%sUnrecognized argument -%s%s\n", ERRC, argv[optind], NORMAL);
 		}
 	}
 
@@ -238,10 +238,10 @@ int main(int argc, char **argv) {
 
 	if (optind < argc) // Must be [-s] argument, unless already given
 		if (search == NULL) search = argv[optind++];
-		else abort(-5, "%sSuperfluous argument: %s\n", ERRC, argv[optind]);
+		else abort(-5, "%sSuperfluous argument: %s%s\n", ERRC, argv[optind], NORMAL);
 
 	if (optind < argc)
-		abort(-6, "%sSuperfluous argument: %s\n", ERRC, argv[optind]);
+		abort(-6, "%sSuperfluous argument: %s%s\n", ERRC, argv[optind], NORMAL);
 
 	if (*kdbxfilename == 0) { // Try configfile for database filename
 		*filename = 0;
@@ -253,22 +253,22 @@ int main(int argc, char **argv) {
 				*filename = 0;
 			}
 		if (*kdbxfilename == 0)
-			abort(-7, "%sNo database specified on commandline or in configfile\n",
-				ERRC);
+			abort(-7, "%sNo database specified on commandline or in configfile%s\n",
+				ERRC, NORMAL);
 		else strcpy(filename, kdbxfilename);
 	}
 
 	// Set default mode depending on search
 	if (search != NULL) { // Search requested
 		if (command == 'i' || command == 'x')
-			abort(-8, "%sCannot Search with -i/--interactive or -x/--xml\n", ERRC);
+			abort(-8, "%sCannot Search with -i/--interactive or -x/--xml%s\n", ERRC, NORMAL);
 		if (command == 0) command = 't';
 	} else { // No search
 		if (command == 0) command = 'i';
 	}
 
 	// Open the database
-	warn("%skdbxviewer", RESET);
+	warn("%skdbxviewer", NORMAL);
 	if (password == NULL) {
 		warn(" - Opening KDBX database %s%s\n%sPassword: %s", FIELD, kdbxfilename, PWC, NORMAL);
 		password = getpass("");
