--- modules/yahoo2/libyahoo2/yahoo_httplib.c.orig	Fri Jan 16 14:39:20 2004
+++ modules/yahoo2/libyahoo2/yahoo_httplib.c	Sun Feb  8 00:33:04 2004
@@ -200,12 +200,16 @@
 				str[bpos++] = instr[ipos++];
 		if(!instr[ipos])
 			break;
-		ipos++;
 		
-		entity[0]=instr[ipos++];
-		entity[1]=instr[ipos++];
-		sscanf(entity, "%2x", &dec);
-		str[bpos++] = (char)dec;
+		if(instr[ipos+1] && instr[ipos+2]) {
+			ipos++;
+			entity[0]=instr[ipos++];
+			entity[1]=instr[ipos++];
+			sscanf(entity, "%2x", &dec);
+			str[bpos++] = (char)dec;
+		} else {
+			str[bpos++] = instr[ipos++];
+		}
 	}
 	str[bpos]='\0';
 
