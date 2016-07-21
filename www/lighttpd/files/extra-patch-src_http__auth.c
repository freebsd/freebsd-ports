--- src/http_auth.c.orig	2016-07-16 10:06:16 UTC
+++ src/http_auth.c
@@ -30,6 +30,7 @@
 #include <errno.h>
 #include <unistd.h>
 #include <ctype.h>
+#include <mysql/mysql.h>
 
 #include "md5.h"
 
@@ -194,9 +195,119 @@ static int http_auth_get_password(server
 		fclose(fp);
 	} else if (p->conf.auth_backend == AUTH_BACKEND_LDAP) {
 		return 0;
-	}
+	} else if (p->conf.auth_backend == AUTH_BACKEND_MYSQL) {
+		MYSQL_RES *result;
+		MYSQL_ROW row;
+		int port = atoi(p->conf.auth_mysql_port->ptr);
+		char q[255];
 
-	return -1;
+		if (p->conf.auth_mysql_socket->ptr != NULL)
+			if (0 == strcmp(p->conf.auth_mysql_socket->ptr, "")) p->conf.auth_mysql_socket->ptr = NULL;
+
+		p->conf.mysql_conn = mysql_init(NULL);
+
+		if (mysql_real_connect(p->conf.mysql_conn, p->conf.auth_mysql_host->ptr, p->conf.auth_mysql_user->ptr, p->conf.auth_mysql_pass->ptr, p->conf.auth_mysql_db->ptr, port, p->conf.auth_mysql_socket->ptr, 0))
+		{
+//#define MY_HOSTING
+
+#ifdef MY_HOSTING
+			char my_full_realm[255];
+			char *my_realm = NULL;
+			char *my_domain = NULL;
+
+			char *uname;
+			size_t unamelen;
+
+			unamelen = strlen(username->ptr);
+			uname = malloc(unamelen*2+1);
+
+			mysql_real_escape_string(p->conf.mysql_conn,
+					uname, username->ptr,
+					(unsigned long)unamelen);
+
+			strcpy(my_full_realm, realm->ptr);
+			my_realm = strtok(my_full_realm, "@");
+
+			if (my_realm != NULL)
+				my_domain = strtok(NULL, "@");
+
+			sprintf(q, "SELECT %s FROM %s, %s WHERE %s='%s' AND %s='%s' AND %s='%s' AND %s=%s",
+				p->conf.auth_mysql_col_pass->ptr,
+
+				p->conf.auth_mysql_users_table->ptr,
+				p->conf.auth_mysql_domains_table->ptr,
+
+				p->conf.auth_mysql_col_user->ptr,
+				uname,
+
+				p->conf.auth_mysql_col_realm->ptr,
+				my_realm,
+
+				p->conf.auth_mysql_col_domain->ptr,
+				my_domain,
+
+				p->conf.auth_mysql_domains_table_col_domain_id->ptr,
+				p->conf.auth_mysql_users_table_col_domain_id->ptr
+				);
+
+			free(uname);
+#else
+			// sanitize username & realm by taguchi@ff.iij4u.or.jp
+			char *uname, *urealm;
+			size_t unamelen, urealmlen;
+
+			unamelen = strlen(username->ptr);
+			urealmlen = strlen(realm->ptr);
+			uname = malloc(unamelen*2+1);
+			urealm = malloc(urealmlen*2+1);
+
+			mysql_real_escape_string(p->conf.mysql_conn,
+				uname, username->ptr,
+				(unsigned long)unamelen);
+
+			mysql_real_escape_string(p->conf.mysql_conn,
+				urealm, realm->ptr,
+				(unsigned long)unamelen);
+
+			mysql_real_escape_string(p->conf.mysql_conn,
+				urealm, realm->ptr,
+				(unsigned long)urealmlen);
+
+			sprintf(q, "SELECT %s FROM %s WHERE %s='%s' AND %s='%s'",
+				p->conf.auth_mysql_col_pass->ptr,
+				p->conf.auth_mysql_users_table->ptr,
+				p->conf.auth_mysql_col_user->ptr,
+				uname,
+				p->conf.auth_mysql_col_realm->ptr,
+				urealm
+			);
+
+			free(uname);
+			free(urealm);
+#endif
+
+			mysql_query(p->conf.mysql_conn, q);
+			result = mysql_store_result(p->conf.mysql_conn);
+			if (mysql_num_rows(result) == 1)
+			{
+				/* found */
+				row = mysql_fetch_row(result);
+				buffer_copy_string_len(password, row[0], strlen(row[0]));
+
+				return 0;
+			} else
+			{
+				/* not found */
+				return -1;
+			}
+
+			mysql_free_result(result);
+			mysql_close(p->conf.mysql_conn);
+
+			p->conf.mysql_conn = NULL;
+		} else
+			return -1;
+	}
 }
 
 int http_auth_match_rules(server *srv, array *req, const char *username, const char *group, const char *host) {
@@ -711,6 +822,60 @@ static int http_auth_basic_password_comp
 
 		return 0;
 #endif
+	} else if (p->conf.auth_backend == AUTH_BACKEND_MYSQL) {
+		/*
+			we check for md5 crypt() now
+			request by Nicola Tiling <nti@w4w.net>
+		*/
+		if (password->ptr[0] == '$' && password->ptr[2] == '$')
+		{
+			char salt[32];
+			char *crypted;
+			size_t salt_len = 0;
+			char *dollar = NULL;
+
+			if (NULL == (dollar = strchr(password->ptr + 3, '$'))) {
+				fprintf(stderr, "%s.%d\n", __FILE__, __LINE__);
+				return -1;
+			}
+
+			salt_len = dollar - password->ptr;
+
+			if (salt_len > sizeof(salt) - 1)
+			{
+				fprintf(stderr, "%s.%d\n", __FILE__, __LINE__);
+				return -1;
+			}
+
+			strncpy(salt, password->ptr, salt_len);
+
+			salt[salt_len] = '\0';
+
+			crypted = crypt(pw, salt);
+
+			if (0 == strcmp(password->ptr, crypted))
+			{
+				return 0;
+			} else {
+				fprintf(stderr, "%s.%d\n", __FILE__, __LINE__);
+			}
+		} else
+		/* plain md5 check now */
+		{
+			li_MD5_CTX Md5Ctx;
+			HASH HA1;
+			char a1[256];
+
+			li_MD5_Init(&Md5Ctx);
+			li_MD5_Update(&Md5Ctx, (unsigned char *)pw, strlen(pw));
+			li_MD5_Final(HA1, &Md5Ctx);
+
+			CvtHex(HA1, a1);
+
+			if (0 == strcmp(password->ptr, a1)) {
+				return 0;
+			}
+		}
 	}
 	return -1;
 }
