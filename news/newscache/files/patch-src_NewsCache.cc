NewsCache.cc:2265:62: error: invalid operands to binary expression ('__bind<int &, sockaddr *, unsigned int>' and 'int')
        if (bind(sock, (struct sockaddr *) &nproxy, sizeof(nproxy)) < 0) {
            ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ^ ~

--- src/NewsCache.cc.orig	2018-08-31 22:11:06 UTC
+++ src/NewsCache.cc
@@ -2262,7 +2262,7 @@ void nntpd()
 		}
 	}			/* end create socket and set some socket options */
 
-	if (bind(sock, (struct sockaddr *) &nproxy, sizeof(nproxy)) < 0) {
+	if (::bind(sock, (struct sockaddr *) &nproxy, sizeof(nproxy)) < 0) {
 		slog.
 		    p(Logger::
 		      Error) << "can't bind socket: " << strerror(errno) <<
