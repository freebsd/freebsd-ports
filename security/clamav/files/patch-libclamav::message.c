--- libclamav/message.c.orig	Wed Nov  5 11:59:53 2003
+++ libclamav/message.c	Tue Feb 10 14:39:23 2004
@@ -878,15 +878,20 @@
 			if(strcasecmp(line, "end") == 0)
 				break;
 
-			assert(strlen(line) <= 62);
 			if((line[0] & 0x3F) == ' ')
 				break;
 
 			len = *line++ - ' ';
 
-			assert((len >= 0) && (len <= 63));
-
-			ptr = decode(line, ptr, uudecode, (len & 3) == 0);
+			if(len < 0 || len > 63)
+				/*
+				 * In practice this should never occur since
+				 * the maximum length of a uuencoded line is
+				 * 62 characters
+				 */
+				cli_warnmsg("uudecode: buffer overflow stopped, attempting to ignore but decoding may fail");
+			else
+				ptr = decode(line, ptr, uudecode, (len & 3) == 0);
 			break;
 
 		case BINARY:
