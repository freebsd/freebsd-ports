--- mod_log_sql.c.orig	Thu Feb 16 05:30:51 2006
+++ mod_log_sql.c	Wed Nov 16 19:35:10 2005
@@ -37,6 +37,11 @@
 #define DEFAULT_HOUT_TABLE_NAME		"headers_out"
 #define DEFAULT_COOKIE_TABLE_NAME	"cookies"
 #define DEFAULT_PRESERVE_FILE		"logs/mod_log_sql-preserve"
+#define DEFAULT_SCOREBOARD_DOMAIN	"www"
+#define DEFAULT_SCOREBOARD_SUBDOMAIN	"default-domain.tld"
+#define DEFAULT_SCOREBOARD_TABLE_NAME	"scoreboard"
+
+#include <time.h>
 
 /* -------------*
  * DECLARATIONS *
@@ -96,6 +101,9 @@
 	logsql_item **parsed_log_format;
 	const char *preserve_file;
 	const char *cookie_name;
+	const char *scoreboard_domain;
+	const char *scoreboard_subdomain;
+	const char *scoreboard_table_name;
 } logsql_state;
 
 
@@ -638,6 +646,9 @@
 	cls->hout_table_name = DEFAULT_HOUT_TABLE_NAME;
 	cls->cookie_table_name = DEFAULT_COOKIE_TABLE_NAME;
 	cls->preserve_file = DEFAULT_PRESERVE_FILE;
+	cls->scoreboard_domain = DEFAULT_SCOREBOARD_DOMAIN;
+	cls->scoreboard_subdomain = DEFAULT_SCOREBOARD_SUBDOMAIN;
+	cls->scoreboard_table_name = DEFAULT_SCOREBOARD_TABLE_NAME;
 
 	cls->transfer_ignore_list = apr_array_make(p, 1, sizeof(char *));
 	cls->transfer_accept_list = apr_array_make(p, 1, sizeof(char *));
@@ -748,6 +759,15 @@
 	if (child->cookie_table_name == DEFAULT_COOKIE_TABLE_NAME)
 		child->cookie_table_name = parent->cookie_table_name;
 
+	if (child->scoreboard_domain == DEFAULT_SCOREBOARD_DOMAIN)
+		child->scoreboard_domain = parent->scoreboard_domain;
+
+	if (child->scoreboard_subdomain == DEFAULT_SCOREBOARD_SUBDOMAIN)
+		child->scoreboard_subdomain = parent->scoreboard_subdomain;
+
+	if (child->scoreboard_table_name == DEFAULT_SCOREBOARD_TABLE_NAME)
+		child->scoreboard_table_name = parent->scoreboard_table_name;
+
 	DO_MERGE_ARRAY(parent->transfer_ignore_list, child->transfer_ignore_list, subp);
 	DO_MERGE_ARRAY(parent->transfer_accept_list, child->transfer_accept_list, subp);
 	DO_MERGE_ARRAY(parent->remhost_ignore_list, child->remhost_ignore_list, subp);
@@ -779,6 +799,10 @@
 	const char *hout_tablename = cls->hout_table_name;
 	const char *hin_tablename = cls->hin_table_name;
 	const char *cookie_tablename = cls->cookie_table_name;
+	const char *scoreboard_domain = cls->scoreboard_domain;
+	const char *scoreboard_subdomain = cls->scoreboard_subdomain;
+	const char *scoreboard_table_name = cls->scoreboard_table_name;
+	struct timeval now_time;
 
 	/* We handle mass virtual hosting differently.  Dynamically determine the name
 	 * of the table from the virtual server's name, and flag it for creation.
@@ -1097,6 +1121,29 @@
 		if (cookie_query)
 		  	safe_sql_insert(orig, LOGSQL_TABLE_COOKIES,cookie_tablename,cookie_query);
 
+		gettimeofday(&now_time, (struct timeval*)0);
+
+		{
+			const char *score_query_insert;
+			const char *score_query_update;
+			struct tm *ptr;
+			time_t tm;
+			char sql_month[60];
+			char sql_year[60];
+			char a[60];
+ 
+			tm = time(NULL);
+			ptr = localtime(&tm);
+			strftime(sql_month ,100 , "\%m",ptr);
+			strftime(sql_year ,100 , "\%Y",ptr);
+
+			score_query_insert = apr_psprintf(r->pool, "insert ignore into %s (domain,vhost,month,year,count_impressions) values ('%s','%s','%s','%s','0')"
+				,scoreboard_table_name,scoreboard_domain,scoreboard_subdomain,sql_month,sql_year);
+			safe_sql_insert(orig,LOGSQL_TABLE_SCORE,"score_board",score_query_insert);
+			score_query_update = apr_psprintf(r->pool, "update %s SET count_impressions = count_impressions+1, bytes_sent = bytes_sent+%s WHERE domain='%s' AND vhost='%s' AND month='%s' AND year='%s'"
+				,scoreboard_table_name,extract_bytes_sent(r, a),scoreboard_domain,scoreboard_subdomain,sql_month,sql_year);
+			safe_sql_insert(orig,LOGSQL_TABLE_SCORE,"score_board",score_query_update);
+		}
 		return OK;
 	}
 }
@@ -1157,6 +1204,18 @@
 	AP_INIT_TAKE1("LogSQLCookieLogTable", set_server_nmv_string_slot,
 	 (void *)APR_OFFSETOF(logsql_state, cookie_table_name), RSRC_CONF,
 	 "The database table that holds the cookie info")
+	,
+	AP_INIT_TAKE1("LogSQLScoreDomain", set_server_nmv_string_slot,
+	 (void *)APR_OFFSETOF(logsql_state, scoreboard_domain), RSRC_CONF,
+	 "The domain to set in scoreboard")
+	,
+	AP_INIT_TAKE1("LogSQLScoreSubdomain", set_server_nmv_string_slot,
+	 (void *)APR_OFFSETOF(logsql_state, scoreboard_subdomain), RSRC_CONF,
+	 "The subdomain to set in scoreboard")
+	,
+	AP_INIT_TAKE1("LogSQLScoreTable", set_server_nmv_string_slot,
+	 (void *)APR_OFFSETOF(logsql_state, scoreboard_table_name), RSRC_CONF,
+	 "The scoreboard to log in")
 	,
 	/* Log format */
 	AP_INIT_TAKE1("LogSQLTransferLogFormat", set_logformat_slot,
