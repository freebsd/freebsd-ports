--- traff.c.orig	Fri Feb  1 16:10:22 2002
+++ traff.c	Tue Sep 27 18:04:32 2005
@@ -135,7 +135,7 @@
   DEBUG(printf("Reading Config\n");)
   config = (t_config *) malloc(sizeof(t_config));
   // reading config file
-  config_init(config,"/etc/traff.conf"); // this function will initialize configuration
+  config_init(config,"%%PREFIX%%/etc/traff.conf"); // this function will initialize configuration
   config->dt = time(0);
 
   DEBUG(print_config();)
@@ -467,14 +467,8 @@
   bzero(my_query, QUERYLENGTH);
   DEBUG(printf("Initializing Mysql\n");)
   mysql_init(&mysql);
-  DEBUG(printf("Connecting to host %s, db %s, table %s using login %s, password %s\n",cat->sql->host,cat->sql->db, cat->sql->table,cat->sql->user,cat->sql->password);)
-  mysql_connect(&mysql,cat->sql->host,cat->sql->user,cat->sql->password);
-  if (mysql_errno(&mysql)) {
-    fprintf(stderr,"Error connecting to Mysql-Database in category %s:\n%d, %s\n",cat->name,  mysql_errno(&mysql),mysql_error(&mysql));
-    syslog(LOG_ERR,"Error connecting to Mysql-Database in category %s:\n%d, %s\n",cat->name, mysql_errno(&mysql),mysql_error(&mysql));
-    return 1;
-  }
-  mysql_select_db(&mysql,cat->sql->db); 
+  DEBUG(printf("Connecting to host %s, db %s, table %s using login %s, password %s\n",cat->sql->host,cat->sql->db, cat->sql->table,cat->sql->user,cat->sql->password,cat->sql->db,0,NULL,0);)
+  mysql_real_connect(&mysql,cat->sql->host,cat->sql->user,cat->sql->password,cat->sql->db,0,NULL,0);
   if (mysql_errno(&mysql)) {
     fprintf(stderr,"Error connecting to Mysql-Database in category %s:\n%d, %s\n",cat->name,  mysql_errno(&mysql),mysql_error(&mysql));
     syslog(LOG_ERR,"Error connecting to Mysql-Database in category %s:\n%d, %s\n",cat->name, mysql_errno(&mysql),mysql_error(&mysql));
