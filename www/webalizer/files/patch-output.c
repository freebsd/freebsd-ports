--- output.c.orig	2013-02-26 05:37:27 UTC
+++ output.c
@@ -54,7 +54,7 @@
 #endif
 
 #ifdef USE_GEOIP
-#include <GeoIP.h>
+#include <maxminddb.h>
 #endif
 
 #include "webalizer.h"                        /* main header              */
@@ -992,6 +992,20 @@ int all_sites_page(u_int64_t h_reg, u_in
       hptr=*pointer++;
       if (hptr->flag == OBJ_REG)
       {
+#ifdef USE_CLICKABLE_REFERER
+         if (strstr(hptr->string,"://")!=NULL)
+            fprintf(out_fp,
+               "%-8llu %6.02f%%  %8llu %6.02f%%  %8.0f %6.02f%%  "            \
+               "%8llu %6.02f%%  <A HREF=\"%s\">%s</A>\n",
+               hptr->count,
+               (t_hit==0)?0:((float)hptr->count/t_hit)*100.0,hptr->files,
+               (t_file==0)?0:((float)hptr->files/t_file)*100.0,hptr->xfer/1024,
+               (t_xfer==0)?0:((float)hptr->xfer/t_xfer)*100.0,hptr->visit,
+               (t_visit==0)?0:((float)hptr->visit/t_visit)*100.0,
+               hptr->string,
+               hptr->string);
+         else
+#endif
          fprintf(out_fp,
             "%-8llu %6.02f%%  %8llu %6.02f%%  %8.0f %6.02f%%  "            \
             "%8llu %6.02f%%  %s\n",
@@ -1948,7 +1962,7 @@ void top_ctry_table()
 
 #ifdef USE_GEOIP
    extern int    geoip;
-   extern GeoIP  *geo_fp;
+   extern MMDB_s mmdb;
    const  char   *geo_rc=NULL;
 #endif
    char          geo_ctry[3]="--";
@@ -1981,19 +1995,26 @@ void top_ctry_table()
                if (geoip)
                {
                   /* Lookup IP address here,  turn into idx  */
-                  geo_rc=GeoIP_country_code_by_addr(geo_fp, hptr->string);
-                  if (geo_rc==NULL||geo_rc[0]=='\0'||geo_rc[0]=='-')
+                  MMDB_lookup_result_s result;
+                  MMDB_entry_data_s entry_data;
+                  int gai_error, mmdb_error, rc;
+                  result=MMDB_lookup_string(&mmdb, hptr->string, &gai_error, &mmdb_error);
+                  if (gai_error!=0||mmdb_error!=MMDB_SUCCESS||!result.found_entry)
                   {
                      if (debug_mode)
                         fprintf(stderr,"GeoIP: %s unknown (returns '%s')\n",
-                                hptr->string,(geo_rc==NULL)?"null":geo_rc);
+                                hptr->string,MMDB_strerror(mmdb_error));
                   }
                   else
                   {
-                     /* index returned geo_ctry */
-                     geo_ctry[0]=tolower(geo_rc[0]);
-                     geo_ctry[1]=tolower(geo_rc[1]);
-                     idx=ctry_idx(geo_ctry);
+                     rc = MMDB_get_value(&result.entry, &entry_data, "country", "iso_code", NULL);
+                     if (rc==MMDB_SUCCESS&&entry_data.has_data)
+                     {
+                       /* index returned geo_ctry */
+                       geo_ctry[0]=tolower(entry_data.utf8_string[0]);
+                       geo_ctry[1]=tolower(entry_data.utf8_string[1]);
+                       idx=ctry_idx(geo_ctry);
+                     }
                   }
                }
 #endif /* USE_GEOIP */
