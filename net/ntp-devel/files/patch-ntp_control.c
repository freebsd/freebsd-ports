--- ntpd/ntp_control.c.orig	Sat Jul 15 10:46:05 2000
+++ ntpd/ntp_control.c	Fri Apr  6 10:41:43 2001
@@ -1782,7 +1782,7 @@
 	 * Delete leading commas and white space
 	 */
 	while (reqpt < reqend && (*reqpt == ',' ||
-	    isspace((int)*reqpt)))
+	    isspace((unsigned char)*reqpt)))
 		reqpt++;
 	if (reqpt >= reqend)
 		return (0);
@@ -1805,7 +1805,8 @@
 				tp++;
 			}
 			if ((*tp == '\0') || (*tp == '=')) {
-				while (cp < reqend && isspace((int)*cp))
+				while (cp < reqend &&
+				    isspace((unsigned char)*cp))
 					cp++;
 				if (cp == reqend || *cp == ',') {
 					buf[0] = '\0';
@@ -1819,15 +1820,18 @@
 					cp++;
 					tp = buf;
 					while (cp < reqend &&
-					    isspace((int)*cp))
+					    isspace((unsigned char)*cp))
 						cp++;
-					while (cp < reqend && *cp !=
-					    ',')
+					while (cp < reqend && *cp != ',') {
 						*tp++ = *cp++;
+						if (tp >= buf + sizeof(buf))
+							return (0);
+					}
 					if (cp < reqend)
 						cp++;
 					*tp = '\0';
-					while (isspace((int)(*(tp-1))))
+					while (tp != buf &&
+					    isspace((unsigned char)(*(tp-1))))
 						*(--tp) = '\0';
 					reqpt = cp;
 					*data = buf;
