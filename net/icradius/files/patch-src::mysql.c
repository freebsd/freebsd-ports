--- src/mysql.c.orig	Thu Jun 14 23:32:02 2001
+++ src/mysql.c	Wed Jun 27 11:22:09 2001
@@ -443,7 +443,7 @@
 #if defined(F_LOCK) && !defined(BSD)
 		(void)lockf((int)mysqlfile, (int)F_LOCK, (off_t)SQL_LOCK_LEN);
 #else
-		(void)flock(mysqlfile, LOCK_EX);
+		(void)flock(fileno(mysqlfile), LOCK_EX);
 #endif
 	}
 
@@ -1463,8 +1463,6 @@
 
    char		querystr[2048];
    SQL_ROW	row;
-   char opts1[32];
-   char opts2[32];
    REALM   *c;
    
    realm_free(realms);
@@ -1483,11 +1481,11 @@
 		return -1;
 	}
 
-	opts1[0] = opts2[0] = 0;
 	c->realm[0] = 0;
 	c->server[0] = 0;
 	c->striprealm = 1;
 	c->dohints = 0;
+	c->loglocal = 0;
 
 	if (c->realm != NULL)
 		strNcpy(c->realm, row[0], sizeof(c->realm));
@@ -1503,12 +1501,9 @@
 		c->auth_port = strtol(row[3], NULL, 0);
 	c->acct_port = c->auth_port + 1;
 	if (row[4] != NULL) {
-		sscanf(row[4], "%31s%31s", opts1, opts2);
-
-		c->striprealm = strcmp(opts1, "nostrip") != 0 &&
-				strcmp(opts2, "nostrip") != 0;
-		c->dohints    = strcmp(opts1, "hints") == 0 ||
-				strcmp(opts2, "hints") == 0;
+		c->striprealm = strstr(row[4], "nostrip") == NULL;
+		c->dohints    = strstr(row[4], "hints") != NULL;
+		c->loglocal   = strstr(row[4], "loglocal") != NULL; 
  	}
 
 	c->next = realms;
