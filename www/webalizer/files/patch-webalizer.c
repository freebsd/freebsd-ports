--- webalizer.c.orig	2013-08-26 04:52:15 UTC
+++ webalizer.c
@@ -72,7 +72,7 @@
 #endif  /* USE_DNS */
 
 #ifdef USE_GEOIP
-#include <GeoIP.h>
+#include <maxminddb.h>
 #endif
 
 #ifdef USE_BZIP
@@ -172,7 +172,8 @@ char    *flag_dir    = "flags";         
 #ifdef USE_GEOIP
 int     geoip        = 0;                     /* Use GeoIP (0=no)         */
 char    *geoip_db    = NULL;                  /* GeoIP database filename  */
-GeoIP   *geo_fp      = NULL;                  /* GeoIP database handle    */
+int	mmdb_open    = MMDB_FILE_OPEN_ERROR;  /* GeoIP database open      */
+MMDB_s  mmdb;                                 /* GeoIP database handle    */
 #endif
 
 int     ntop_sites   = 30;                    /* top n sites to display   */
@@ -619,20 +620,17 @@ int main(int argc, char *argv[])
    if (geoip)
    {
       if (geoip_db!=NULL)
-         geo_fp=GeoIP_open(geoip_db, GEOIP_MEMORY_CACHE);
+         mmdb_open = MMDB_open(geoip_db, MMDB_MODE_MMAP, &mmdb);
       else
-         geo_fp=GeoIP_new(GEOIP_MEMORY_CACHE);
+         mmdb_open = MMDB_open("GeoLite2-Country.mmdb", MMDB_MODE_MMAP, &mmdb);
 
       /* Did we open one? */
-      if (geo_fp==NULL)
+      if (mmdb_open!=MMDB_SUCCESS)
       {
          /* couldn't open.. warn user */
          if (verbose) printf("GeoIP %s\n",msg_geo_nolu);
          geoip=0;
       }
-      else if (verbose>1) printf("%s %s (%s)\n",msg_geo_use,
-         GeoIPDBDescription[(int)geo_fp->databaseType],
-         (geoip_db==NULL)?msg_geo_dflt:geo_fp->file_path);
    }
 #endif /* USE_GEOIP */
 
@@ -942,7 +940,11 @@ int main(int argc, char *argv[])
                {
                   /* Save query portion in log.rec.srchstr */
                   strncpy(log_rec.srchstr,(char *)cp1,MAXSRCH);
+#ifdef USE_FULL_CGI_REFS
+                  *cp1++;
+#else
                   *cp1++='\0';
+#endif
                   break;
                }
                else cp1++;
@@ -1089,6 +1091,13 @@ int main(int argc, char *argv[])
             {
                freeaddrinfo(ares);
                resolve_dns(&log_rec);
+
+#ifdef USE_IP_AS_HOSTNAME
+               /* restore the host's IP-address if the host's name has not been resolved */
+               if (!strcmp(log_rec.hostname,"\020\002"))
+                       strncpy(log_rec.hostname, host_buf, sizeof(host_buf));
+#endif
+
             }
          }
 #endif
@@ -1487,7 +1496,10 @@ int main(int argc, char *argv[])
 
 #ifdef USE_GEOIP
       /* Close GeoIP database */
-      if (geo_fp) GeoIP_delete(geo_fp);
+      if (mmdb_open==MMDB_SUCCESS) {
+         MMDB_close(&mmdb);
+         mmdb_open=MMDB_FILE_OPEN_ERROR;
+      }
 #endif
 
       /* Whew, all done! Exit with completion status (0) */
