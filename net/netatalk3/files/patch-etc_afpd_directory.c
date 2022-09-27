--- etc/afpd/directory.c.orig	2022-02-28 13:32:06 UTC
+++ etc/afpd/directory.c
@@ -1426,6 +1426,7 @@ int getdirparams(const AFPObj *obj,
     struct maccess  ma;
     struct adouble  ad;
     char        *data, *l_nameoff = NULL, *utf_nameoff = NULL;
+    char        *ade = NULL;
     int         bit = 0, isad = 0;
     uint32_t           aint;
     uint16_t       ashort;
@@ -1520,7 +1521,10 @@ int getdirparams(const AFPObj *obj,
 
         case DIRPBIT_FINFO :
             if ( isad ) {
-                memcpy( data, ad_entry( &ad, ADEID_FINDERI ), 32 );
+                ade = ad_entry(&ad, ADEID_FINDERI);
+                AFP_ASSERT(ade != NULL);
+
+                memcpy( data, ade, 32 );
             } else { /* no appledouble */
                 memset( data, 0, 32 );
                 /* dot files are by default visible */
@@ -1744,6 +1748,7 @@ int setdirparams(struct vol *vol, struct path *path, u
     struct timeval      tv;
 
     char                *upath;
+    char                *ade = NULL;
     struct dir          *dir;
     int         bit, isad = 0;
     int                 cdate, bdate;
@@ -1905,6 +1910,8 @@ int setdirparams(struct vol *vol, struct path *path, u
                 fflags &= htons(~FINDERINFO_ISHARED);
                 memcpy(finder_buf + FINDERINFO_FRFLAGOFF, &fflags, sizeof(uint16_t));
                 /* #2802236 end */
+                ade = ad_entry(&ad, ADEID_FINDERI);
+                AFP_ASSERT(ade != NULL);
 
                 if (  dir->d_did == DIRDID_ROOT ) {
                     /*
@@ -1915,10 +1922,10 @@ int setdirparams(struct vol *vol, struct path *path, u
                      * behavior one sees when mounting above another mount
                      * point.
                      */
-                    memcpy( ad_entry( &ad, ADEID_FINDERI ), finder_buf, 10 );
-                    memcpy( ad_entry( &ad, ADEID_FINDERI ) + 14, finder_buf + 14, 18 );
+                    memcpy( ade, finder_buf, 10 );
+                    memcpy( ade + 14, finder_buf + 14, 18 );
                 } else {
-                    memcpy( ad_entry( &ad, ADEID_FINDERI ), finder_buf, 32 );
+                    memcpy( ade, finder_buf, 32 );
                 }
             }
             break;
