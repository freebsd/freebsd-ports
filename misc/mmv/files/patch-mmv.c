--- mmv.c	Thu Oct  5 10:36:36 2006
+++ mmv.c	Thu Oct  5 10:38:31 2006
@@ -73,7 +73,8 @@
 %s [-m|x|r|c|o|a|l%s] [-h] [-d|p] [-g|t] [-v|n] [from to]\n\
 \n\
 Use #[l|u]N in the ``to'' pattern to get the [lowercase|uppercase of the]\n\
-string matched by the N'th ``from'' pattern wildcard.\n\
+string matched by the N'th ``from'' pattern wildcard.  = can be used\n\
+instead of #.\n\
 \n\
 A ``from'' pattern containing wildcards should be quoted when given\n\
 on the command line. Also you may need to quote ``to'' pattern.\n\
@@ -976,6 +977,9 @@
 			lastname = p + 1;
 			break;
 		case '#':
+		case '=':
+		{
+			char index_char=c;
 			c = *(++p);
 			if (c == 'l' || c == 'u') {
 #ifdef IS_MSDOS
@@ -986,8 +990,8 @@
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
@@ -998,8 +1002,8 @@
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
@@ -1007,6 +1011,7 @@
 				havedot = 1;
 #endif
 			break;
+		}
 		case ESC:
 			if ((c = *(++p)) == '\0') {
 				printf(TRAILESC, from, to, ESC);
@@ -2029,7 +2034,7 @@
 	repbad = 0;
 	p = fullrep;
 	for (pat = to, l = 0; (c = *pat) != '\0'; pat++, l++) {
-		if (c == '#') {
+		if (c == '#' || c == '=') {
 			c = *(++pat);
 #ifndef IS_MSDOS
 			if (c == 'l') {
