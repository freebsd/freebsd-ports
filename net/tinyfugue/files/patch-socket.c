--- src/socket.c.orig	2007-01-13 23:12:39 UTC
+++ src/socket.c
@@ -494,6 +494,8 @@ do { \
     do_hook(H_DISCONNECT, "%% Connection to %s closed: %s: %s", "%s %s: %s", \
 	where, what, why)
 
+#define ROUND_UP_LENGTH(len)	((len + 7) & -8)
+
 #if HAVE_SSL
 static void ssl_err(const char *str)
 {
@@ -1478,8 +1480,8 @@ static int openconn(Sock *sock)
 	for (ai = xsock->addrs; ai; ai = ai->ai_next) {
 	    ai->ai_addr = (struct sockaddr*)((char*)ai + sizeof(*ai));
 	    if (ai->ai_next != 0) {
-		ai->ai_next =
-		    (struct addrinfo*)((char*)ai->ai_addr + ai->ai_addrlen);
+		ai->ai_next = 
+		    (struct addrinfo*)((char*)ai->ai_addr + ROUND_UP_LENGTH(ai->ai_addrlen));
 	    }
 	}
 	xsock->addr = xsock->addrs;
@@ -1783,13 +1785,21 @@ static void waitforhostname(int fd, const char *name, 
 	iov[0].iov_len = sizeof(hdr);
 	niov = 1;
 	for (ai = res; ai && niov < NIOV; ai = ai->ai_next) {
-	    hdr.size += sizeof(*ai) + ai->ai_addrlen;
+	    static const char zeros[ 8 ] = { 0, 0, 0, 0, 0, 0, 0, 0 };
+	    size_t padded = ROUND_UP_LENGTH(ai->ai_addrlen);
+	    hdr.size += sizeof(*ai) + padded;
 	    iov[niov].iov_base = (char*)ai;
 	    iov[niov].iov_len = sizeof(*ai);
 	    niov++;
 	    iov[niov].iov_base = (char*)ai->ai_addr;
 	    iov[niov].iov_len = ai->ai_addrlen;
 	    niov++;
+	    if (padded != ai->ai_addrlen) {
+		/* padding */
+		iov[niov].iov_base = (char*)zeros;
+		iov[niov].iov_len = padded - ai->ai_addrlen;
+		niov++;
+	    }
 	}
 	writev(fd, iov, niov);
 	if (res) freeaddrinfo(res);
