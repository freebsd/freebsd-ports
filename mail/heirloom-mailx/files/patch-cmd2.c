--- cmd2.c	2006/03/04 00:32:16	1.12
+++ cmd2.c	2010/05/09 21:50:54	1.13
@@ -803,16 +803,17 @@
 	int h = hash(name);
 
 	for (ip = tab->i_head[h]; ip; ip = ip->i_link) {
-		if (asccasecmp(ip->i_field, name)) {
+		if (asccasecmp(ip->i_field, name) == 0) {
 			free(ip->i_field);
 			if (iq != NULL)
 				iq->i_link = ip->i_link;
 			else
-				tab->i_head[h] = NULL;
+				tab->i_head[h] = ip->i_link;
 			free(ip);
 			tab->i_count--;
 			break;
 		}
+		iq = ip;
 	}
 }
 
