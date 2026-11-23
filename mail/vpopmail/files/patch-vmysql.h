--- vmysql.h.orig	2005-01-01 00:00:00.000000000 +0000
+++ vmysql.h	2005-01-01 00:00:00.000000000 +0000
@@ -63,53 +63,53 @@
 
 #ifdef MANY_DOMAINS
 #ifdef CLEAR_PASS
-#define TABLE_LAYOUT "pw_name char(32) not null, \
-pw_domain char(96) not NULL, \
-pw_passwd char(40), \
+#define TABLE_LAYOUT "pw_name VARCHAR (64) not null, \
+pw_domain VARCHAR (96) not NULL, \
+pw_passwd VARCHAR (128), \
 pw_uid int, pw_gid int, \
-pw_gecos char(48), \
-pw_dir char(160), \
-pw_shell char(20), \
-pw_clear_passwd char(16), \
+pw_gecos VARCHAR (64), \
+pw_dir VARCHAR (160), \
+pw_shell VARCHAR (20), \
+pw_clear_passwd VARCHAR (128), \
 primary key (pw_name, pw_domain ) "
 #else
-#define TABLE_LAYOUT "pw_name char(32) not null, \
-pw_domain char(96) not null, \
-pw_passwd char(40), \
+#define TABLE_LAYOUT "pw_name VARCHAR (64) not null, \
+pw_domain VARCHAR (96) not null, \
+pw_passwd VARCHAR (128), \
 pw_uid int, pw_gid int, \
-pw_gecos char(48), \
-pw_dir char(160), \
-pw_shell char(20), \
+pw_gecos VARCHAR (64), \
+pw_dir VARCHAR (160), \
+pw_shell VARCHAR (20), \
 primary key (pw_name, pw_domain ) "
 #endif
 #else
 #ifdef CLEAR_PASS
-#define TABLE_LAYOUT "pw_name char(32) not null, \
-pw_passwd char(40), \
+#define TABLE_LAYOUT "pw_name VARCHAR (64) not null, \
+pw_passwd VARCHAR (128), \
 pw_uid int, pw_gid int, \
-pw_gecos char(48), \
-pw_dir char(160), \
-pw_shell char(20), \
-pw_clear_passwd char(16), \
+pw_gecos VARCHAR (64), \
+pw_dir VARCHAR (160), \
+pw_shell VARCHAR (20), \
+pw_clear_passwd VARCHAR (128), \
 primary key (pw_name ) "
 #else
-#define TABLE_LAYOUT "pw_name char(32) not null, \
-pw_passwd char(40), \
+#define TABLE_LAYOUT "pw_name VARCHAR (64) not null, \
+pw_passwd VARCHAR (128), \
 pw_uid int, pw_gid int, \
-pw_gecos char(48), \
-pw_dir char(160), \
-pw_shell char(20), \
+pw_gecos VARCHAR (64), \
+pw_dir VARCHAR (160), \
+pw_shell VARCHAR (20), \
 primary key (pw_name ) "
 #endif
 #endif
 
-#define RELAY_TABLE_LAYOUT "ip_addr char(18) not null, \
+#define RELAY_TABLE_LAYOUT "ip_addr VARCHAR (39) not null, \
 timestamp char(12), primary key (ip_addr)"
 
 #define LASTAUTH_TABLE_LAYOUT \
-"user char(32) NOT NULL, \
+"user VARCHAR (64) NOT NULL, \
 domain char(96) NOT NULL,\
-remote_ip char(18) not null,  \
+remote_ip VARCHAR (39) not null,  \
 timestamp bigint default 0 NOT NULL, \
 primary key (user, domain)"
 
@@ -241,7 +241,7 @@
 #endif
 
 #ifdef IP_ALIAS_DOMAINS
-#define IP_ALIAS_TABLE_LAYOUT "ip_addr char(18) not null, domain char(96),  primary key(ip_addr)"
+#define IP_ALIAS_TABLE_LAYOUT "ip_addr VARCHAR (39) not null, domain char(96),  primary key(ip_addr)"
 #endif
 
 #define DIR_CONTROL_TABLE_LAYOUT "domain char(96) not null, cur_users int, \
@@ -267,8 +267,8 @@
 
 #ifdef ENABLE_SQL_LOGGING
 #define VLOG_TABLE_LAYOUT "id BIGINT PRIMARY KEY AUTO_INCREMENT, \
-      user char(32), passwd CHAR(32), \
-      domain CHAR(96), logon VARCHAR(200), \
+      user VARCHAR (64), passwd CHAR(32), \
+      domain VARCHAR (96), logon VARCHAR(200), \
       remoteip char(18), message VARCHAR(255), \
       timestamp bigint default 0 NOT NULL, error INT, \
       INDEX user_idx (user), \
@@ -277,7 +277,7 @@
 #endif
 
 #ifdef ENABLE_MYSQL_LIMITS
-#define LIMITS_TABLE_LAYOUT "domain CHAR(96) PRIMARY KEY, \
+#define LIMITS_TABLE_LAYOUT "domain VARCHAR (96) PRIMARY KEY, \
       maxpopaccounts           INT(10) NOT NULL DEFAULT -1, \
       maxaliases               INT(10) NOT NULL DEFAULT -1, \
       maxforwards              INT(10) NOT NULL DEFAULT -1, \
