--- stat.fmt.c.orig	Mon Feb 17 00:12:33 1997
+++ stat.fmt.c	Sat Dec 17 16:08:52 2005
@@ -98,12 +98,11 @@
 	}
 
 	if( (Sbuf.st_mode & S_IFMT) == S_IFLNK) {
-		if( (count = readlink(filename, Lbuf, sizeof Lbuf)) == FAIL) {
+		if( (count = readlink(filename, Lbuf, sizeof Lbuf-1)) == FAIL) {
 			fprintf(stderr, "Can't readlink %s\n", filename);
 			return(FAIL);
 		}
-		if( count < LBUFSIZ)
-			Lbuf[count] = '\0';
+		Lbuf[count] = '\0';
 		printf("  File: \"%s\" -> \"%s\"\n", filename, Lbuf);
 	} else
 		printf("  File: \"%s\"\n", filename);
@@ -279,6 +278,8 @@
 					break;
 		case	S_IFSOCK:	buf[5 + 0] = 's';
 					break;
+		case	S_IFIFO:	buf[5 + 0] = 'p';
+					break;
 		default		:	buf[5 + 0] = '?';
 	}
 }
@@ -328,6 +329,10 @@
 
 		case	S_IFSOCK:
 			strcpy(buf, "Socket");
+			break;
+
+		case	S_IFIFO:
+			strcpy(buf, "FIFO");
 			break;
 
 		default:
