--- src/radiusd.h.old	Tue Sep  5 05:50:25 2000
+++ src/radiusd.h	Thu Jan 25 14:53:27 2001
@@ -123,6 +123,7 @@
 	int			acct_port;
 	int			striprealm;
 	int			dohints;
+	int			loglocal;
 	struct realm		*next;
 } REALM;
 
