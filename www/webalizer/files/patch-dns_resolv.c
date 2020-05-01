--- dns_resolv.c.orig	2013-02-26 05:37:27 UTC
+++ dns_resolv.c
@@ -68,21 +68,29 @@
 #include "parser.h"                            /* log parser functions     */
 #include "dns_resolv.h"                        /* our header               */
 
+#ifndef DB_NOTFOUND
+#define DB_NOTFOUND 1
+#endif
+
 /* local data */
 
 DB       *dns_db   = NULL;                     /* DNS cache database       */
 int      dns_fd    = 0;
 
 DB       *geo_db   = NULL;                     /* GeoDB database           */
+#ifdef USE_DB185
+int      geo_dbc   = 0;                        /* GeoDB database cursor    */
+#else
 DBC      *geo_dbc  = NULL;                     /* GeoDB database cursor    */
+#endif
 
 struct   dns_child child[MAXCHILD];            /* DNS child pipe data      */
 
-DNODEPTR host_table[MAXHASH];                  /* hostname/ip hash table   */
+/* DNODEPTR host_table[MAXHASH]; */
 
-char     buffer[BUFSIZE];                      /* log file record buffer   */
-char     tmp_buf[BUFSIZE];                     /* used to temp save above  */
-struct   utsname system_info;                  /* system info structure    */
+static char     buffer[BUFSIZE];               /* log file record buffer   */
+static char     tmp_buf[BUFSIZE];              /* used to temp save above  */
+static struct   utsname system_info;           /* system info structure    */
 
 int      raiseSigChild = 1;
 
@@ -122,7 +130,11 @@ void resolve_dns(struct log_struct *log_rec)
 
    if (debug_mode) fprintf(stderr,"Checking %s...", log_rec->hostname);
 
+#ifdef USE_DB185
+   if ( (i=dns_db->get(dns_db, &query, &response, 0)) == 0)
+#else
    if ( (i=dns_db->get(dns_db, NULL, &query, &response, 0)) == 0)
+#endif
    {
       memcpy(&alignedRecord, response.data, sizeof(struct dnsRecord));
       strncpy (log_rec->hostname,
@@ -131,7 +143,7 @@ void resolve_dns(struct log_struct *log_rec)
       log_rec->hostname[MAXHOST-1]=0;
       if (debug_mode)
          fprintf(stderr," found: %s (%ld)\n",
-           log_rec->hostname, alignedRecord.timeStamp);
+           log_rec->hostname, (long)alignedRecord.timeStamp);
    }
    else  /* not found or error occured during get */
    {
@@ -193,10 +205,14 @@ int dns_resolver(void *log_fp)
    }
   
    /* open cache file */
+#ifdef USE_DB185
+   if (!(dns_db = dbopen(dns_cache, O_RDWR|O_CREAT, 0664, DB_HASH, NULL)))
+#else
    if ( (db_create(&dns_db, NULL, 0) != 0)   ||
         (dns_db->open(dns_db, NULL,
            dns_cache, NULL, DB_HASH,
            DB_CREATE, 0644) != 0) )
+#endif
    {
       /* Error: Unable to open DNS cache file <filename> */
       if (verbose) fprintf(stderr,"%s %s\n",msg_dns_nodb,dns_cache);
@@ -206,14 +222,22 @@ int dns_resolver(void *log_fp)
    }
 
    /* get file descriptor */
+#ifdef USE_DB185
+   dns_fd = dns_db->fd(dns_db);
+#else
    dns_db->fd(dns_db, &dns_fd);
+#endif
 
    tmp_flock.l_type=F_WRLCK;                    /* set read/write lock type */
    if (fcntl(dns_fd,F_SETLK,&tmp_flock) < 0)    /* and barf if we cant lock */
    {
       /* Error: Unable to lock DNS cache file <filename> */
       if (verbose) fprintf(stderr,"%s %s\n",msg_dns_nolk,dns_cache);
+#ifdef USE_DB185
+      dns_db->close(dns_db);
+#else
       dns_db->close(dns_db, 0);
+#endif
       dns_cache=NULL;
       dns_db=NULL;
       return 0;                  /* disable cache */
@@ -261,7 +285,11 @@ int dns_resolver(void *log_fp)
             q.size = strlen(log_rec.hostname);
 
             /* Check if we have it in DB */
+#ifdef USE_DB185
+            if ( (i=(dns_db->get)(dns_db, &q, &r, 0)) == 0 )
+#else
             if ( (i=dns_db->get(dns_db, NULL, &q, &r, 0)) == 0 )
+#endif
             {
                /* have a record for this address */
                memcpy(&alignedRecord, r.data, sizeof(struct dnsRecord));
@@ -302,7 +330,11 @@ int dns_resolver(void *log_fp)
       if (verbose>1) printf("%s\n",msg_dns_none);
       tmp_flock.l_type=F_UNLCK;
       fcntl(dns_fd, F_SETLK, &tmp_flock);
+#ifdef USE_DB185
+      dns_db->close(dns_db);
+#else
       dns_db->close(dns_db, 0);
+#endif
       return 0;
    }
 
@@ -335,7 +367,11 @@ int dns_resolver(void *log_fp)
    /* processing done, exit   */
    tmp_flock.l_type=F_UNLCK;
    fcntl(dns_fd, F_SETLK, &tmp_flock);
+#ifdef USE_DB185
+   dns_db->close(dns_db);
+#else
    dns_db->close(dns_db, 0);
+#endif
    return 0;
 
 }
@@ -720,7 +756,11 @@ static void db_put(char *key, char *value, int numeric
          v.size = recSize;
          v.data = recPtr;
 
+#ifdef USE_DB185
+         if ( (dns_db->put)(dns_db, &k, &v, 0) < 0)
+#else
          if ( dns_db->put(dns_db, NULL, &k, &v, 0) != 0 )
+#endif
             if (verbose>1) fprintf(stderr,"db_put fail!\n");
          free(recPtr);
       }
@@ -768,10 +808,14 @@ int open_cache()
    }
   
    /* open cache file */
+#ifdef USE_DB185
+   if (!(dns_db = dbopen(dns_cache, O_RDONLY, 0664, DB_HASH, NULL)))
+#else
    if ( (db_create(&dns_db, NULL, 0) != 0)   ||
         (dns_db->open(dns_db, NULL,
            dns_cache, NULL, DB_HASH,
            DB_RDONLY, 0644) != 0) )
+#endif
    {
       /* Error: Unable to open DNS cache file <filename> */
       if (verbose) fprintf(stderr,"%s %s\n",msg_dns_nodb,dns_cache);
@@ -779,13 +823,21 @@ int open_cache()
    }
 
    /* get file descriptor */
+#ifdef USE_DB185
+   dns_fd = dns_db->fd(dns_db);
+#else
    dns_db->fd(dns_db, &dns_fd);
+#endif
 
    /* Get shared lock on cache file */
    if (fcntl(dns_fd, F_SETLK, &tmp_flock) < 0)
    {
       if (verbose) fprintf(stderr,"%s %s\n",msg_dns_nolk,dns_cache);
+#ifdef USE_DB185
+      dns_db->close(dns_db);
+#else
       dns_db->close(dns_db, 0);
+#endif
       return 0;
    }
    return 1;
@@ -807,7 +859,11 @@ int close_cache()
 
    /* clear lock and close cache file */
    fcntl(dns_fd, F_SETLK, &tmp_flock);
+#ifdef USE_DB185
+   dns_db->close(dns_db);
+#else
    dns_db->close(dns_db, 0);
+#endif
    return 1;
 }
 
@@ -825,6 +881,11 @@ DB *geodb_open(char *dbname)
       strncpy(buf,dbname,sizeof(buf)-1);
    buf[sizeof(buf)-1]='\0';
 
+#ifdef USE_DB185
+   geo_db = dbopen(buf, O_RDONLY, 0664, DB_HASH, NULL);
+   if (geo_db == NULL)
+      return NULL;
+#else
    /* create database thingie */
    if ( db_create(&geo_db, NULL, 0) ) return NULL;
 
@@ -837,6 +898,7 @@ DB *geodb_open(char *dbname)
       geo_db->close(geo_db,0);
       return NULL;
    }
+#endif
    /* all is well in the world */
    return geo_db;
 }
@@ -857,7 +919,11 @@ char *geodb_ver(DB *db, char *str)
    k.data=&x;
    k.size=sizeof(x);
 
+#ifdef USE_DB185
+   i=geo_db->get(geo_db, &k, &v, 0);
+#else
    i=geo_db->get(geo_db, NULL, &k, &v, 0);
+#endif
 
    if (i) strncpy(str, "Unknown", 8);
    else   strncpy(str, v.data+3, v.size-3);
@@ -895,7 +961,11 @@ char *geodb_get_cc(DB *db, char *ip, char *buf)
    k.data=&addr;
    k.size=sizeof(addr);
 
+#ifdef USE_DB185
+   i=geo_db->get(geo_db, &k, &v, 0);
+#else
    i=geo_dbc->c_get(geo_dbc, &k, &v, DB_SET_RANGE);
+#endif
    if (!i) memcpy(buf, v.data, 2);
    return buf;
 }
@@ -906,7 +976,11 @@ char *geodb_get_cc(DB *db, char *ip, char *buf)
 
 void geodb_close(DB *db)
 {
+#ifdef USE_DB185
+   db->close(db);
+#else
    db->close(db,0);
+#endif
 }
 
 /*********************************************/
