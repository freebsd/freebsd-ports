--- ssh-agent.c	Sat Mar 15 00:37:09 2003
+++ ssh-agent.c	Wed Sep 17 00:42:15 2003
@@ -767,7 +767,7 @@ process_message(SocketEntry *e)
 static void
 new_socket(sock_type type, int fd)
 {
-	u_int i, old_alloc;
+	u_int i, old_alloc, new_alloc;
 
 	if (fcntl(fd, F_SETFL, O_NONBLOCK) < 0)
 		error("fcntl O_NONBLOCK: %s", strerror(errno));
@@ -778,25 +778,26 @@ new_socket(sock_type type, int fd)
 	for (i = 0; i < sockets_alloc; i++)
 		if (sockets[i].type == AUTH_UNUSED) {
 			sockets[i].fd = fd;
-			sockets[i].type = type;
 			buffer_init(&sockets[i].input);
 			buffer_init(&sockets[i].output);
 			buffer_init(&sockets[i].request);
+			sockets[i].type = type;
 			return;
 		}
 	old_alloc = sockets_alloc;
-	sockets_alloc += 10;
+	new_alloc = sockets_alloc + 10;
 	if (sockets)
-		sockets = xrealloc(sockets, sockets_alloc * sizeof(sockets[0]));
+		sockets = xrealloc(sockets, new_alloc * sizeof(sockets[0]));
 	else
-		sockets = xmalloc(sockets_alloc * sizeof(sockets[0]));
-	for (i = old_alloc; i < sockets_alloc; i++)
+		sockets = xmalloc(new_alloc * sizeof(sockets[0]));
+	for (i = old_alloc; i < new_alloc; i++)
 		sockets[i].type = AUTH_UNUSED;
-	sockets[old_alloc].type = type;
+	sockets_alloc = new_alloc;
 	sockets[old_alloc].fd = fd;
 	buffer_init(&sockets[old_alloc].input);
 	buffer_init(&sockets[old_alloc].output);
 	buffer_init(&sockets[old_alloc].request);
+	sockets[old_alloc].type = type;
 }
 
 static int
