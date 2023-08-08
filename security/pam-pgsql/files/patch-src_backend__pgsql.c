--- src/backend_pgsql.c.orig	2023-08-02 16:34:32 UTC
+++ src/backend_pgsql.c
@@ -1,6 +1,6 @@
 /*
  * PAM authentication module for PostgreSQL
- * 
+ *
  * Based in part on pam_unix.c of FreeBSD. See COPYRIGHT
  * for licensing details.
  *
@@ -23,6 +23,7 @@
 #include <unistd.h>
 #include <netdb.h>
 #include <arpa/inet.h>
+#include <sys/socket.h>
 
 #include <gcrypt.h>
 
@@ -57,7 +58,7 @@ build_conninfo(modopt_t *options)
 	if(options->port) {
 		strncat(str, " port=", strlen(" port="));
 		strncat(str, options->port, strlen(options->port));
-	}    
+	}
 	if(options->timeout) {
 		strncat(str, " connect_timeout=", strlen(" connect_timeout="));
 		strncat(str, options->timeout, strlen(options->timeout));
@@ -102,7 +103,7 @@ expand_query (char **command, const char** values, con
 	char *p, *q, *res;
 	unsigned int len;
 	unsigned int nparm=0;
-  
+
 	if (!query) {
 		*command = NULL;
 		return 0;
@@ -121,7 +122,7 @@ expand_query (char **command, const char** values, con
 			}
 		}
 		len++;
-		p++;  
+		p++;
 	}
 	res = malloc (len + 1);
 	if (!res) {
@@ -181,15 +182,15 @@ expand_query (char **command, const char** values, con
 		} else	*q++ = *p++;
 	 }
 	 *q = 0;
-	 
+
 	 *command = res;
-	 values[nparm] = NULL; 
+	 values[nparm] = NULL;
 	 return nparm;
 }
 
 /* private: execute query */
 int
-pg_execParam(PGconn *conn, PGresult **res, 
+pg_execParam(PGconn *conn, PGresult **res,
         const char *query, const char *service, const char *user, const char *passwd, const char *rhost)
 {
 	int nparm = 0;
@@ -197,26 +198,26 @@ pg_execParam(PGconn *conn, PGresult **res, 
 	char *command, *raddr;
 	struct hostent *hentry;
 
-	if (!conn) 
+	if (!conn)
 		return PAM_AUTHINFO_UNAVAIL;
 	bzero(values, sizeof(*values));
-	
+
 	raddr = NULL;
-	
+
 	if(rhost != NULL && (hentry = gethostbyname(rhost)) != NULL) {
 		/* Make IP string */
 		raddr = malloc(INET_ADDRSTRLEN);
 		inet_ntop(AF_INET, hentry->h_addr_list[0], raddr, INET_ADDRSTRLEN);
 	}
-	
+
 	nparm = expand_query(&command, values, query, service, user, passwd, rhost, raddr);
-	if (command == NULL) 
+	if (command == NULL)
 		return PAM_AUTH_ERR;
-	
+
 	*res = PQexecParams(conn, command, nparm, 0, values, 0, 0, 0);
 	free (command);
 	free (raddr);
-    
+
 	if(PQresultStatus(*res) != PGRES_COMMAND_OK && PQresultStatus(*res) != PGRES_TUPLES_OK) {
 		SYSLOG("PostgreSQL query failed: '%s'", PQresultErrorMessage(*res));
 		return PAM_AUTHINFO_UNAVAIL;
@@ -254,7 +255,7 @@ backend_authenticate(const char *service, const char *
 		return PAM_AUTH_ERR;
 
 	DBGLOG("query: %s", options->query_auth);
-	rc = PAM_AUTH_ERR;	
+	rc = PAM_AUTH_ERR;
 	if(pg_execParam(conn, &res, options->query_auth, service, user, passwd, rhost) == PAM_SUCCESS) {
 		if(PQntuples(res) == 0) {
 			rc = PAM_USER_UNKNOWN;
