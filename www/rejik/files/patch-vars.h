--- vars.h.orig	2016-03-21 06:49:53 UTC
+++ vars.h
@@ -48,23 +48,23 @@
 #define ML_2LD 200
 #define ML_SUBDOMEN 512
 
-FILE *change_log;
+extern FILE *change_log;
 
-char *input_ident;
-char *input_ident_un;
-char *input_ip;
-char *input_url;
-char *input_url_un;
+extern char *input_ident;
+extern char *input_ident_un;
+extern char *input_ip;
+extern char *input_url;
+extern char *input_url_un;
 
 #ifdef CASE_INDEPENDENT
 char *input_url_uc;
 #endif
 
-char *input_method;
-char *input_host;
-struct p_url  *i_url;
+extern char *input_method;
+extern char *input_host;
+extern struct p_url  *i_url;
 
-char *change_reason;
+extern char *change_reason;
 
 
  /*****************************************************************
@@ -82,40 +82,38 @@ struct p_url
     };
 
 //GLOBAL OPTIONS
-char *err_log;   // Error log path
-char *chg_log;   // Change log path
-char *makecache; // make-cache program
+extern char *err_log;   // Error log path
+extern char *chg_log;   // Change log path
+extern char *makecache; // make-cache program
 
-char *work_ip; 	       //Work ip
-int  work_ip_count;    //Work ip count
-int  work_ip_flag;     //Work ip flag
+extern char *work_ip; 	       //Work ip
+extern int  work_ip_count;    //Work ip count
+extern int  work_ip_flag;     //Work ip flag
 
-char *allow_ip; 	//Allow ip
-int  allow_ip_count;  	//Allow ip count
+extern char *allow_ip; 	//Allow ip
+extern int  allow_ip_count;  	//Allow ip count
 
-char **work_id;	//Work id
-int  work_id_count;	//Work id count
-int  work_id_flag;	//Work id flag
+extern char **work_id;	//Work id
+extern int  work_id_count;	//Work id count
+extern int  work_id_flag;	//Work id flag
 
-char **allow_id;	//Allow id
-int  allow_id_count;	//Allow id count
+extern char **allow_id;	//Allow id
+extern int  allow_id_count;	//Allow id count
 
-char *allow_urls_file;  //Allow urls file name
-char **allow_urls;	//Allow urls
-int allow_urls_count;	//Allow urls count
+extern char *allow_urls_file;  //Allow urls file name
+extern char **allow_urls;	//Allow urls
+extern int allow_urls_count;	//Allow urls count
 
-char **change_from;      //
-char **change_to;        // Change data
-int change_count;        //
-int raw_change_log_flag; //
+extern char **change_from;      //
+extern char **change_to;        // Change data
+extern int change_count;        //
+extern int raw_change_log_flag; //
 
-int sections_count;    //Count of sections in config
+extern int write_hostname_to_log; // Write hostname to log flag
 
-int write_hostname_to_log; // Write hostname to log flag
-
 //SECTIONS OPTIONS
-int sections_count;    //Count of sections in config
-struct section
+extern int sections_count;    //Count of sections in config
+extern struct section
      {
 	char *name;	        //Header name
 	char *ban_dir;		//Ban lists dir
