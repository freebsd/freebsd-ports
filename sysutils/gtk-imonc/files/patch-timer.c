--- gtk-imonc/timer.c.orig	Fri Aug 16 21:52:15 2002
+++ gtk-imonc/timer.c	Sat Oct 26 15:43:20 2002
@@ -183,12 +183,12 @@
 				row[i] = chargebuf;
 				break;
 			case 8: /* IBytes */
-				tmpbytes = atoll (strtok (NULL, " "));
+				tmpbytes = atoi (strtok (NULL, " "));
 				ibytes += tmpbytes;
 				row[i] = get_bytes (tmpbytes, ibytebuf);
 				break;
 			case 9: /* OBytes */
-				tmpbytes = atoll (strtok (NULL, " "));
+				tmpbytes = atoi (strtok (NULL, " "));
 				obytes += tmpbytes;
 				row[i] = get_bytes (tmpbytes, obytebuf);
 				break;
@@ -773,8 +773,8 @@
 		gtk_clist_set_text (GTK_CLIST (clist), j, 2, get_answer (fd));
 		
 		send_command (fd, "quantity pppoe");
-		gtk_clist_set_text (GTK_CLIST (clist), j, 3, get_bytes (atoll (strtok (get_answer (fd), " ")), buf));
-		gtk_clist_set_text (GTK_CLIST (clist), j, 4, get_bytes (atoll (strtok (NULL, " ")), buf));
+		gtk_clist_set_text (GTK_CLIST (clist), j, 3, get_bytes (atoi (strtok (get_answer (fd), " ")), buf));
+		gtk_clist_set_text (GTK_CLIST (clist), j, 4, get_bytes (atoi (strtok (NULL, " ")), buf));
 		
 		send_command (fd, "online-time pppoe");
 		gtk_clist_set_text (GTK_CLIST (clist), j, 5, get_answer (fd));
@@ -814,8 +814,8 @@
 
 		sprintf (buf, "quantity %i", i);
 		send_command (fd, buf);
-		gtk_clist_set_text (GTK_CLIST (clist), (j+i-1), 3, get_bytes (atoll (strtok (get_answer (fd), " ")), buf));
-		gtk_clist_set_text (GTK_CLIST (clist), (j+i-1), 4, get_bytes (atoll (strtok (NULL, " ")), buf));
+		gtk_clist_set_text (GTK_CLIST (clist), (j+i-1), 3, get_bytes (atoi (strtok (get_answer (fd), " ")), buf));
+		gtk_clist_set_text (GTK_CLIST (clist), (j+i-1), 4, get_bytes (atoi (strtok (NULL, " ")), buf));
 
 		sprintf (buf, "online-time %i", i);
 		send_command (fd, buf);
@@ -892,7 +892,7 @@
 		return buf;
 	} 
 
-	sprintf (buf, "%lu", (ulong) bytes);
+	sprintf (buf, "%lu", (long) bytes);
 	return buf;
 
 } /* get_bytes (bytes, *buf) */
