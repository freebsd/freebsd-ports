--- src/timer.c.orig	Mon May 17 23:58:51 2004
+++ src/timer.c	Tue May 18 00:18:15 2004
@@ -298,14 +298,14 @@
 				}
 				else
 				{
-					tmpbytes = atoll (strtok (NULL, " "));
+					tmpbytes = strtoll (strtok (NULL, " "), NULL, 10);
 					ibytes += tmpbytes;
 					row[i] = get_bytes (tmpbytes,
 							    ibytebuf);
 				}
 				break;
 			case 9:	/* OBytes */
-				tmpbytes = atoll (strtok (NULL, " "));
+				tmpbytes = strtoll (strtok (NULL, " "), NULL, 10);
 				obytes += tmpbytes;
 				row[i] = get_bytes (tmpbytes, obytebuf);
 				break;
@@ -1148,8 +1148,8 @@
 		}
 		else
 		{
-			gtk_clist_set_text (GTK_CLIST (clist), j, 3, get_bytes(atoll(strtok(get_answer (fd)," ")), buf));
-			gtk_clist_set_text (GTK_CLIST (clist), j, 4, get_bytes(atoll(strtok(NULL, " ")), buf));
+			gtk_clist_set_text (GTK_CLIST (clist), j, 3, get_bytes(strtoll(strtok(get_answer (fd)," "), NULL, 10), buf));
+			gtk_clist_set_text (GTK_CLIST (clist), j, 4, get_bytes(strtoll(strtok(NULL, " "), NULL, 10), buf));
 		}
 
 		send_command (fd, "online-time pppoe");
