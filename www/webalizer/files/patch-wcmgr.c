--- wcmgr.c.orig	2008-06-02 07:27:57.000000000 +0200
+++ wcmgr.c	2008-07-05 08:49:42.000000000 +0200
@@ -73,6 +73,10 @@
 #include <db.h>
 #include "webalizer.h"
 
+#ifndef DB_NOTFOUND
+#define DB_NOTFOUND 1
+#endif
+
 /*********************************************/
 /* Forward reference local functions         */
 /*********************************************/
@@ -104,7 +108,11 @@
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
@@ -131,18 +139,24 @@
 
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
@@ -168,7 +182,9 @@
    printf(" -l         List cache file contents\n");
    printf(" -n name    hostname (used for add)\n");
    printf(" -p num     Purge after num days\n");
+#ifndef USE_DB185
    printf(" -s         Display cache file stats/info\n");
+#endif
    printf(" -t num     TTL value (for add and stats)\n");
    printf(" -x name    Export cache to tab file\n");
    printf("\n");
@@ -233,7 +249,9 @@
          case 'h':  print_help();                                     break;
          case 'n':  strncpy(name,optarg,sizeof(name)-1);              break;
          case 'p':  action='p'; if (optarg!=NULL) rec_ttl=atoi(optarg); break;
+#ifndef USE_DB185
          case 's':  action='s';                                       break;
+#endif
          case 't':  rec_ttl=atoi(optarg);                             break;
          case 'v':  verbose=1;                                        break;
          case 'V':  print_ver();                                      break;
@@ -250,12 +268,14 @@
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
@@ -269,7 +289,9 @@
       case 'd': del_rec();                                            break;
       case 'f': find_rec();                                           break;
       case 'i': import_cache();                                       break;
+#ifndef USE_DB185
       case 's': stat_cache();                                         break;
+#endif
       case 'p': purge_cache();                                        break;
       case 'x': export_cache();                                       break;
       case 'l':
@@ -290,19 +312,31 @@
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
@@ -321,7 +355,12 @@
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
@@ -338,6 +377,9 @@
       /* done, clear for next rec */
       memset(&q, 0, sizeof(DBT));
       memset(&r, 0, sizeof(DBT));
+#ifdef USE_DB185
+      cursorp = dns_db->seq(dns_db, &q, &r, R_NEXT);
+#endif
    }
 
    if (verbose)
@@ -368,15 +410,29 @@
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
@@ -391,30 +447,44 @@
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
 
@@ -426,7 +496,12 @@
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
@@ -439,9 +514,17 @@
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
@@ -462,13 +545,21 @@
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
@@ -485,6 +576,7 @@
 /* STAT_CACHE - Display cache stats/info     */
 /*********************************************/
 
+#ifndef USE_DB185
 void stat_cache()
 {
    /* Define some variables */
@@ -576,6 +668,7 @@
    printf("Record Size Errors : %llu\n",t_err);
    printf("\n");
 }
+#endif
 
 /*********************************************/
 /* FIND_REC - Find IP record in cache        */
@@ -587,10 +680,20 @@
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
 
@@ -605,7 +708,11 @@
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
@@ -644,7 +751,11 @@
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
 
@@ -669,10 +780,20 @@
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
 
@@ -686,7 +807,11 @@
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
@@ -695,11 +820,19 @@
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
@@ -736,10 +869,20 @@
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
 
@@ -754,7 +897,11 @@
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
@@ -763,7 +910,11 @@
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
@@ -777,7 +928,11 @@
 
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
@@ -793,14 +948,28 @@
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
 
@@ -817,11 +986,23 @@
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
 
@@ -859,7 +1040,11 @@
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
@@ -885,19 +1070,31 @@
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
@@ -923,7 +1120,12 @@
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
@@ -941,8 +1143,15 @@
       /* done, clear for next rec */
       memset(&q, 0, sizeof(DBT));
       memset(&r, 0, sizeof(DBT));
-   }
+#ifdef USE_DB185
+      cursorp = dns_db->seq(dns_db, &q, &r, R_NEXT);
+#endif
+   }
+#ifdef USE_DB185
+   dns_db->close(dns_db);
+#else
    dns_db->close(dns_db,0);
+#endif
    fclose(out_fp);
 
    if (verbose) printf("%llu records exported from '%s' to file '%s'\n",
@@ -989,8 +1198,13 @@
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
