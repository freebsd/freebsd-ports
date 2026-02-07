--- wcmgr.c.orig	2013-08-26 04:35:57 UTC
+++ wcmgr.c
@@ -78,6 +78,10 @@ int main()
 #define str(x) xstr(x)
 #define SMAXHOST str(MAXHOST)   /* String version of MAXHOST value */
 
+#ifndef DB_NOTFOUND
+#define DB_NOTFOUND 1
+#endif
+
 /*********************************************/
 /* Forward reference local functions         */
 /*********************************************/
@@ -109,7 +113,11 @@ int       verbose    = 0;               
 int       rec_ttl    = 7;                  /* purge TTL in days           */
 DB        *dns_db    = NULL;               /* DNS cache database          */
 DB        *out_db    = NULL;               /* output cache db if needed   */
+#ifdef USE_DB185
+int       cursorp    = 0;                  /* database cursor             */
+#else
 DBC       *cursorp   = NULL;               /* database cursor             */
+#endif
 DBT       q, r;                            /* query/reply structures      */
 char      *in_file   = NULL;               /* input cache filename        */
 char      out_file[MAXHOST+4];             /* output cache filename       */
@@ -138,18 +146,24 @@ struct dnsRec
 
 void print_ver()
 {
+#ifndef USE_DB185
    int v,r,l;
+#endif
    struct utsname system_info;
    uname(&system_info);
    printf("%s V%s-%s\n%s\n",pname,version,editlvl,copyright);
    if (verbose)
    {
+#ifndef USE_DB185
       db_version(&v,&r,&l);
+#endif
       printf("System  : %s %s (%s)\n",
              system_info.sysname,
              system_info.release,
              system_info.machine);
+#ifndef USE_DB185
       printf("DB Ver. : V%d.%d.%d\n",v,r,l);
+#endif
       printf("Mod Date: %s\n",moddate);
    }
    printf("\n");
@@ -175,7 +189,9 @@ void print_help(void)
    printf(" -l         List cache file contents\n");
    printf(" -n name    hostname (used for add)\n");
    printf(" -p num     Purge after num days\n");
+#ifndef USE_DB185
    printf(" -s         Display cache file stats/info\n");
+#endif
    printf(" -t num     TTL value (for add and stats)\n");
    printf(" -x name    Export cache to tab file\n");
    printf("\n");
@@ -240,7 +256,9 @@ int main(int argc, char *argv[])
          case 'h':  print_help();                                     break;
          case 'n':  strncpy(name,optarg,sizeof(name)-1);              break;
          case 'p':  action='p'; if (optarg!=NULL) rec_ttl=atoi(optarg); break;
+#ifndef USE_DB185
          case 's':  action='s';                                       break;
+#endif
          case 't':  rec_ttl=atoi(optarg);                             break;
          case 'v':  verbose=1;                                        break;
          case 'V':  print_ver();                                      break;
@@ -257,12 +275,14 @@ int main(int argc, char *argv[])
    if (argc - optind == 0) print_help();   /* gots to have a filename!!     */
    in_file = argv[optind];
 
+#ifndef USE_DB185
    /* Try to create our DB handle */
    if ( db_create(&dns_db, NULL, 0) )
    {
       fprintf(stderr,"Error: unable to create db handle!\n");
       exit(1);
    }
+#endif
 
    /* force sane TTL value */
    if (rec_ttl > 99) rec_ttl=99;
@@ -276,7 +296,9 @@ int main(int argc, char *argv[])
       case 'd': del_rec();                                            break;
       case 'f': find_rec();                                           break;
       case 'i': import_cache();                                       break;
+#ifndef USE_DB185
       case 's': stat_cache();                                         break;
+#endif
       case 'p': purge_cache();                                        break;
       case 'x': export_cache();                                       break;
       case 'l':
@@ -297,19 +319,31 @@ void list_cache()
    u_int64_t t_num=0;
 
    /* open the database (read-only) */
+#ifdef USE_DB185
+   dns_db = dbopen(in_file, O_RDONLY, 0664, DB_HASH, NULL);
+   i = errno;
+   if (!dns_db)
+#else
    if ((i=dns_db->open(dns_db, NULL, in_file, NULL, DB_HASH, DB_RDONLY, 0)))
+#endif
    {
       /* Error opening the cache file.. tell user and exit */
+#ifdef USE_DB185
+      fprintf(stderr,"Error: %s: %s\n",in_file,strerror(i));
+#else
       fprintf(stderr,"Error: %s: %s\n",in_file,db_strerror(i));
+#endif
       exit(1);
    }
 
+#ifndef USE_DB185
    /* Create a cursor */
    if ( dns_db->cursor(dns_db, NULL, &cursorp, 0) )
    {
       fprintf(stderr,"Error: Unable to create cursor!\n");
       exit(1);
    }
+#endif
 
    /* get our runtime for TTL calculations */
    time(&runtime);
@@ -328,7 +362,12 @@ void list_cache()
    memset(&dns_rec, 0, sizeof(struct dnsRec));
 
    /* Loop through database */
+#ifdef USE_DB185
+   cursorp = dns_db->seq(dns_db, &q, &r, R_FIRST);
+   while (!cursorp)
+#else
    while (!cursorp->c_get(cursorp, &q, &r, DB_NEXT))
+#endif
    {
       /* got a record */
       t_rec++;
@@ -346,6 +385,9 @@ void list_cache()
       /* done, clear for next rec */
       memset(&q, 0, sizeof(DBT));
       memset(&r, 0, sizeof(DBT));
+#ifdef USE_DB185
+      cursorp = dns_db->seq(dns_db, &q, &r, R_NEXT);
+#endif
    }
 
    if (verbose)
@@ -376,15 +418,29 @@ void purge_cache()
                         rec_ttl, in_file);
 
    /* open the input database (read-write) */
+#ifdef USE_DB185
+   dns_db = dbopen(in_file, O_RDWR|O_CREAT, 0664, DB_HASH, NULL);
+   i = errno;
+   if (!dns_db)
+#else
    if ((i=dns_db->open(dns_db, NULL, in_file, NULL, DB_HASH, 0, 0)))
+#endif
    {
       /* Error opening the cache file.. tell user and exit */
+#ifdef USE_DB185
+      fprintf(stderr,"Error: %s: %s\n",in_file,strerror(i));
+#else
       fprintf(stderr,"Error: %s: %s\n",in_file,db_strerror(i));
+#endif
       exit(1);
    }
 
    /* get file descriptor */
+#ifdef USE_DB185
+   dns_fd = dns_db->fd(dns_db);
+#else
    dns_db->fd(dns_db, &dns_fd);
+#endif
 
    /* Try to lock the file */
    our_flock.l_whence=SEEK_SET;
@@ -399,30 +455,44 @@ void purge_cache()
       exit(1);
    }
 
+#ifndef USE_DB185
    /* Create a cursor */
    if ( dns_db->cursor(dns_db, NULL, &cursorp, 0) )
    {
       fprintf(stderr,"Error: Unable to create cursor!\n");
       exit(1);
    }
+#endif
 
+#ifndef USE_DB185
    /* Try to create our output DB handle */
    if ( db_create(&out_db, NULL, 0) )
    {
       fprintf(stderr,"Error: unable to create output db handle!\n");
       exit(1);
    }
+#endif
 
    /* generate output filename */
    memset(out_file, 0, sizeof(out_file));
    sprintf(out_file, "%s.new", in_file);
 
    /* open the output database (read-write) */
+#ifdef USE_DB185
+   out_db = dbopen(out_file, O_RDWR|O_CREAT, 0664, DB_HASH, NULL);
+   i = errno;
+   if (!out_db)
+#else
    if ((i=out_db->open(out_db, NULL, out_file, NULL,
                   DB_HASH, DB_CREATE|DB_EXCL, 0644)))
+#endif
    {
       /* Error opening the cache file.. tell user and exit */
+#ifdef USE_DB185
+      fprintf(stderr,"Error: %s: %s\n",out_file,strerror(i));
+#else
       fprintf(stderr,"Error: %s: %s\n",out_file,db_strerror(i));
+#endif
       exit(1);
    }
 
@@ -434,7 +504,12 @@ void purge_cache()
    memset(&r, 0, sizeof(DBT));
 
    /* Loop through database */
+#ifdef USE_DB185
+   cursorp = dns_db->seq(dns_db, &q, &r, R_FIRST);
+   while (!cursorp)
+#else
    while (!cursorp->c_get(cursorp, &q, &r, DB_NEXT))
+#endif
    {
       /* got a record */
       t_in++;
@@ -447,9 +522,17 @@ void purge_cache()
       if ( age <= (rec_ttl*86400) )
       {
          /* Good record.. insert into new cache file */
+#ifdef USE_DB185
+         if ( (out_db->put)(out_db, &q, &r, 0) < 0)
+#else
          if ( (i=out_db->put(out_db, NULL, &q, &r, 0)) != 0 )
+#endif
          {
+#ifdef USE_DB185
+            fprintf(stderr,"Error: db_put fail: %s!\n",strerror(i));
+#else
             fprintf(stderr,"Error: db_put fail: %s!\n",db_strerror(i));
+#endif
             exit(1);
          }
          else t_out++;
@@ -470,13 +553,21 @@ void purge_cache()
       /* done, clear for next rec */
       memset(&q, 0, sizeof(DBT));
       memset(&r, 0, sizeof(DBT));
+#ifdef USE_DB185
+      cursorp = dns_db->seq(dns_db, &q, &r, R_NEXT);
+#endif
    }
 
    /* Successful exit! */
    our_flock.l_type=F_UNLCK;
    fcntl(dns_fd, F_SETLK, &our_flock);
+#ifdef USE_DB185
+   dns_db->close(dns_db);
+   out_db->close(out_db);
+#else
    dns_db->close(dns_db, 0);
    out_db->close(out_db, 0);
+#endif
 
    /* rename files */
    if (rename(out_file, in_file))
@@ -493,6 +584,7 @@ void purge_cache()
 /* STAT_CACHE - Display cache stats/info     */
 /*********************************************/
 
+#ifndef USE_DB185
 void stat_cache()
 {
    /* Define some variables */
@@ -566,6 +658,7 @@ void stat_cache()
    if (t_err) printf("Record Size Errors : %llu\n",t_err);
    printf("\n");
 }
+#endif
 
 /*********************************************/
 /* FIND_REC - Find IP record in cache        */
@@ -577,10 +670,20 @@ void find_rec()
    char  ip_buf[48];
 
    /* open the database (read-only) */
+#ifdef USE_DB185
+   dns_db = dbopen(in_file, O_RDONLY, 0664, DB_HASH, NULL);
+   i = errno;
+   if (!dns_db)
+#else
    if ((i=dns_db->open(dns_db, NULL, in_file, NULL, DB_HASH, DB_RDONLY, 0)))
+#endif
    {
       /* Error opening the cache file.. tell user and exit */
+#ifdef USE_DB185
+      fprintf(stderr,"Error: %s: %s\n",in_file,strerror(i));
+#else
       fprintf(stderr,"Error: %s: %s\n",in_file,db_strerror(i));
+#endif
       exit(1);
    }
 
@@ -595,7 +698,11 @@ void find_rec()
    /* search the cache */
    q.data = &addr;
    q.size = strlen(addr);
+#ifdef USE_DB185
+   if ( (i=(dns_db->get)(dns_db, &q, &r, 0)) == 0 )
+#else
    if ( (i=dns_db->get(dns_db, NULL, &q, &r, 0)) == 0)
+#endif
    {
       /* We found it! display info */
       memset(ip_buf, 0, sizeof(ip_buf));
@@ -635,7 +742,11 @@ void find_rec()
       if (i==DB_NOTFOUND)
          printf("%s not found!\n",addr);
       else
+#ifdef USE_DB185
+         printf("Error: %s\n",strerror(i));
+#else
          printf("Error: %s\n",db_strerror(i));
+#endif
    }
 }
 
@@ -660,10 +771,20 @@ void del_rec()
    cp=addr; while (*cp!='\0') *cp++=tolower(*cp);
 
    /* open the database (read-write) */
+#ifdef USE_DB185
+   dns_db = dbopen(in_file, O_RDWR, 0664, DB_HASH, NULL);
+   i = errno;
+   if (!dns_db)
+#else
    if ((i=dns_db->open(dns_db, NULL, in_file, NULL, DB_HASH, 0, 0)))
+#endif
    {
       /* Error opening the cache file.. tell user and exit */
+#ifdef USE_DB185
+      fprintf(stderr,"Error: %s: %s\n",in_file,strerror(i));
+#else
       fprintf(stderr,"Error: %s: %s\n",in_file,db_strerror(i));
+#endif
       exit(1);
    }
 
@@ -677,7 +798,11 @@ void del_rec()
    q.size = strlen(addr);
 
    /* Try to delete the record */
+#ifdef USE_DB185
+   if ( (i=dns_db->del(dns_db, &q, 0)) )
+#else
    if ( (i=dns_db->del(dns_db, NULL, &q, 0)) )
+#endif
    {
       if (i==DB_NOTFOUND)
       {
@@ -686,11 +811,19 @@ void del_rec()
       }
       else
       {
+#ifdef USE_DB185
+         fprintf(stderr,"Error: %s\n",strerror(i));
+#else
          fprintf(stderr,"Error: %s\n",db_strerror(i));
+#endif
          exit(1);
       }
    }
+#ifdef USE_DB185
+   dns_db->close(dns_db);
+#else
    dns_db->close(dns_db, 0);
+#endif
    if (verbose)
       printf("%s sucessfully deleted from cache file\n",addr);
 }
@@ -727,10 +860,20 @@ void add_rec()
    }
 
    /* open the database (read-write) */
+#ifdef USE_DB185
+   dns_db = dbopen(in_file, O_RDWR, 0664, DB_HASH, NULL);
+   i = errno;
+   if (!dns_db)
+#else
    if ((i=dns_db->open(dns_db, NULL, in_file, NULL, DB_HASH, 0, 0)))
+#endif
    {
       /* Error opening the cache file.. tell user and exit */
+#ifdef USE_DB185
+      fprintf(stderr,"Error: %s: %s\n",in_file,strerror(i));
+#else
       fprintf(stderr,"Error: %s: %s\n",in_file,db_strerror(i));
+#endif
       exit(1);
    }
 
@@ -745,7 +888,11 @@ void add_rec()
    /* search the cache */
    q.data = &addr;
    q.size = strlen(addr);
+#ifdef USE_DB185
+   if ( (i=(dns_db->get)(dns_db, &q, &r, 0)) == 0 )
+#else
    if ( (i=dns_db->get(dns_db, NULL, &q, &r, 0)) == 0)
+#endif
    {
       fprintf(stderr,"Error: %s already exists in cache!\n",addr);
       exit(1);
@@ -754,7 +901,11 @@ void add_rec()
    {
       if (i!=DB_NOTFOUND)
       {
+#ifdef USE_DB185
+         fprintf(stderr,"Error: %s\n",strerror(i));
+#else
          fprintf(stderr,"Error: %s\n",db_strerror(i));
+#endif
          exit(1);
       }
       else
@@ -768,7 +919,11 @@ void add_rec()
 
          /* put it in the database */
          if (db_put(addr, name, (strcmp(name,addr))?0:1, runtime)==0)
+#ifdef USE_DB185
+            dns_db->close(dns_db);
+#else
             dns_db->close(dns_db,0);
+#endif
          if (verbose)
             printf("%s sucessfully added to cache file\n",addr);
       }
@@ -784,14 +939,28 @@ void create_cache()
    int   i;
 
    /* create the database */
+#ifdef USE_DB185
+   dns_db = dbopen(in_file, O_RDWR|O_CREAT, 0664, DB_HASH, NULL);
+   i = errno;
+   if (!dns_db)
+#else
    if ((i=dns_db->open(dns_db,NULL,in_file,NULL,
                   DB_HASH,DB_CREATE|DB_EXCL,0644)))
+#endif
    {
       /* Error opening the cache file.. tell user and exit */
+#ifdef USE_DB185
+      fprintf(stderr,"Error: %s: %s\n",in_file,strerror(i));
+#else
       fprintf(stderr,"Error: %s: %s\n",in_file,db_strerror(i));
+#endif
       exit(1);
    }
+#ifdef USE_DB185
+   dns_db->close(dns_db);
+#else
    dns_db->close(dns_db,0);
+#endif
    if (verbose) printf("Cache file %s created successfully\n",in_file);
 }
 
@@ -808,11 +977,23 @@ void import_cache()
    char      buffer[4096];
 
    /* open the database (read-write) */
+#ifdef USE_DB185
+   flag=O_RDWR;
+   if (create) flag|=O_CREAT;
+   dns_db = dbopen(in_file, flag, 0664, DB_HASH, NULL);
+   i = errno;
+   if (!dns_db)
+#else
    if (create) flag=DB_CREATE|DB_EXCL;
    if ((i=dns_db->open(dns_db, NULL, in_file, NULL, DB_HASH, flag, 0644)))
+#endif
    {
       /* Error opening the cache file.. tell user and exit */
+#ifdef USE_DB185
+      fprintf(stderr,"Error: %s: %s\n",in_file,strerror(i));
+#else
       fprintf(stderr,"Error: %s: %s\n",in_file,db_strerror(i));
+#endif
       exit(1);
    }
 
@@ -850,7 +1031,11 @@ void import_cache()
       }
    }
    else fprintf(stderr,"Error: File not found: %s\n",out_file);
+#ifdef USE_DB185
+   dns_db->close(dns_db);
+#else
    dns_db->close(dns_db,0);
+#endif
 
    if (verbose) printf("%llu records imported into '%s' from file '%s'\n",
                        t_rec, in_file, out_file);
@@ -876,19 +1061,31 @@ void export_cache()
    }
 
    /* open the database (read-only) */
+#ifdef USE_DB185
+   dns_db = dbopen(in_file, O_RDONLY, 0664, DB_HASH, NULL);
+   i = errno;
+   if (!dns_db)
+#else
    if ((i=dns_db->open(dns_db, NULL, in_file, NULL, DB_HASH, DB_RDONLY, 0)))
+#endif
    {
       /* Error opening the cache file.. tell user and exit */
+#ifdef USE_DB185
+      fprintf(stderr,"Error: %s: %s\n",in_file,strerror(i));
+#else
       fprintf(stderr,"Error: %s: %s\n",in_file,db_strerror(i));
+#endif
       exit(1);
    }
 
+#ifndef USE_DB185
    /* Create a cursor */
    if ( dns_db->cursor(dns_db, NULL, &cursorp, 0) )
    {
       fprintf(stderr,"Error: Unable to create cursor!\n");
       exit(1);
    }
+#endif
 
    /* stat output file */
    if ( !(lstat(out_file, &out_stat)) )
@@ -914,7 +1111,12 @@ void export_cache()
    memset(&dns_rec, 0, sizeof(struct dnsRec));
 
    /* Loop through database */
+#ifdef USE_DB185
+   cursorp = dns_db->seq(dns_db, &q, &r, R_FIRST);
+   while (!cursorp)
+#else
    while (!cursorp->c_get(cursorp, &q, &r, DB_NEXT))
+#endif
    {
       /* got a record */
       t_rec++;
@@ -932,8 +1134,15 @@ void export_cache()
       /* done, clear for next rec */
       memset(&q, 0, sizeof(DBT));
       memset(&r, 0, sizeof(DBT));
+#ifdef USE_DB185
+      cursorp = dns_db->seq(dns_db, &q, &r, R_NEXT);
+#endif
    }
+#ifdef USE_DB185
+   dns_db->close(dns_db);
+#else
    dns_db->close(dns_db,0);
+#endif
    fclose(out_fp);
 
    if (verbose) printf("%llu records exported from '%s' to file '%s'\n",
@@ -980,8 +1189,13 @@ static int db_put(char *key, char *value
          v.size = recSize;
          v.data = recPtr;
 
+#ifdef USE_DB185
+         if ( (dns_db->put)(dns_db, &k, &v, 0) < 0)
+            fprintf(stderr,"Error: db_put fail: %s!\n",strerror(errno));
+#else
          if ( (i=dns_db->put(dns_db, NULL, &k, &v, 0)) != 0 )
             fprintf(stderr,"Error: db_put fail: %s!\n",db_strerror(i));
+#endif
          free(recPtr);
       }
       else return 1;
