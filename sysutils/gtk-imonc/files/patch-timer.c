--- src/timer.c.orig	Wed Jan 12 12:36:24 2005
+++ src/timer.c	Thu Feb 17 21:10:06 2005
@@ -293,14 +293,14 @@
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
@@ -1165,8 +1165,8 @@
 		}
 		else
 		{
-			gtk_clist_set_text (GTK_CLIST (clist), j, 3, get_bytes(atoll(strtok(get_answer (fd)," ")), buf));
-			gtk_clist_set_text (GTK_CLIST (clist), j, 4, get_bytes(atoll(strtok(NULL, " ")), buf));
+			gtk_clist_set_text (GTK_CLIST (clist), j, 3, get_bytes(strtoll(strtok(get_answer (fd)," "), NULL, 10), buf));
+			gtk_clist_set_text (GTK_CLIST (clist), j, 4, get_bytes(strtoll(strtok(NULL, " "), NULL, 10), buf));
 		}
 
 		send_command (fd, "online-time pppoe");
