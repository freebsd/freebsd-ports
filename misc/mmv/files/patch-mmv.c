--- mmv.c.orig	2017-10-24 14:25:26 UTC
+++ mmv.c
@@ -73,7 +73,8 @@ Use -- as the end of options.\n";
 %s [-m|x|r|c|o|a|l%s] [-h] [-d|p] [-g|t] [-v|n] [from to]\n\
 \n\
 Use #[l|u]N in the ``to'' pattern to get the [lowercase|uppercase of the]\n\
-string matched by the N'th ``from'' pattern wildcard.\n\
+string matched by the N'th ``from'' pattern wildcard.  = can be used\n\
+instead of #.\n\
 \n\
 A ``from'' pattern containing wildcards should be quoted when given\n\
 on the command line. Also you may need to quote ``to'' pattern.\n\
@@ -977,6 +978,9 @@ static int parsepat()
 			lastname = p + 1;
 			break;
 		case '#':
+		case '=':
+		{
+			char index_char=c;
 			c = *(++p);
 			if (c == 'l' || c == 'u') {
 #ifdef IS_MSDOS
@@ -987,8 +991,8 @@ static int parsepat()
 #endif
 			}
 			if (!isdigit(c)) {
-				printf("%s -> %s : expected digit (not '%c') after #.\n",
-					from, to, c);
+				printf("%s -> %s : expected digit (not '%c') after %c.\n",
+					from, to, c, index_char);
 				return(-1);
 			}
 			for(x = 0; ;x *= 10) {
@@ -999,8 +1003,8 @@ static int parsepat()
 				p++;
 			}
 			if (x < 1 || x > totwilds) {
-				printf("%s -> %s : wildcard #%d does not exist.\n",
-					from, to, x);
+				printf("%s -> %s : wildcard %c%d does not exist.\n",
+					from, to, index_char, x);
 				return(-1);
 			}
 #ifdef IS_MSDOS
@@ -1008,6 +1012,7 @@ static int parsepat()
 				havedot = 1;
 #endif
 			break;
+		}
 		case ESC:
 			if ((c = *(++p)) == '\0') {
 				printf(TRAILESC, from, to, ESC);
@@ -2030,7 +2039,7 @@ static void makerep()
 	repbad = 0;
 	p = fullrep;
 	for (pat = to, l = 0; (c = *pat) != '\0'; pat++, l++) {
-		if (c == '#') {
+		if (c == '#' || c == '=') {
 			c = *(++pat);
 #ifndef IS_MSDOS
 			if (c == 'l') {
