This patch fixes a segfault that can occur when a Yahoo user receives new
mail.  This patch is from gaim CVS, and will be integrated in the next
release.

--- src/protocols/yahoo/yahoo.c	2002/11/12 00:50:21	1.43.2.7
+++ src/protocols/yahoo/yahoo.c	2002/11/23 18:50:47	1.43.2.8
@@ -259,19 +259,20 @@
 		pair->key = strtol(key, NULL, 10);
 		accept = x; /* if x is 0 there was no key, so don't accept it */
 
-		if (accept)
+		if (len - pos + 1 <= 0) {
+			/* Truncated. Garbage or something. */
+			accept = 0;
+		}
+
+		if (accept) {
 			value = g_malloc(len - pos + 1);
-		x = 0;
-		while (pos + 1 < len) {
-			if (data[pos] == 0xc0 && data[pos + 1] == 0x80)
-				break;
-			if (accept)
+			x = 0;
+			while (pos + 1 < len) {
+				if (data[pos] == 0xc0 && data[pos + 1] == 0x80)
+					break;
 				value[x++] = data[pos++];
-		}
-		if (accept)
+			}
 			value[x] = 0;
-		pos += 2;
-		if (accept) {
 			pair->value = g_strdup(value);
 			g_free(value);
 			pkt->hash = g_slist_append(pkt->hash, pair);
@@ -279,6 +280,11 @@
 		} else {
 			g_free(pair);
 		}
+		pos += 2;
+
+		/* Skip over garbage we've noticed in the mail notifications */
+		if (data[0] == '9' && data[pos] == 0x01)
+			pos++;
 	}
 }
 
