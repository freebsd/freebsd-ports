--- etc/afpd/file.c.orig	2022-02-28 13:32:06 UTC
+++ etc/afpd/file.c
@@ -296,6 +296,7 @@ int getmetadata(const AFPObj *obj,
 {
     char		*data, *l_nameoff = NULL, *upath;
     char                *utf_nameoff = NULL;
+    char		*ade = NULL;
     int			bit = 0;
     uint32_t		aint;
     cnid_t              id = 0;
@@ -497,8 +498,11 @@ int getmetadata(const AFPObj *obj,
             }
             else {
                 if ( adp ) {
-                    memcpy(fdType, ad_entry( adp, ADEID_FINDERI ), 4 );
+                    ade = ad_entry(adp, ADEID_FINDERI);
+                    AFP_ASSERT(ade != NULL);
 
+                    memcpy(fdType, ade, 4);
+
                     if ( memcmp( fdType, "TEXT", 4 ) == 0 ) {
                         achar = '\x04';
                         ashort = 0x0000;
@@ -576,8 +580,19 @@ int getmetadata(const AFPObj *obj,
                10.3 clients freak out. */
 
     	    aint = st->st_mode;
- 	    if (adp) {
-	        memcpy(fdType, ad_entry( adp, ADEID_FINDERI ), 4 );
+            /*
+             * ad_open() does not initialize adouble header
+             * for symlinks. Hence this should be skipped to
+             * avoid AFP_ASSERT here. Decision was made to
+             * not alter ad_open() behavior so that
+             * improper ops on symlink adoubles will be
+             * more visible (assert).
+             */
+            if (adp && (ad_meta_fileno(adp) != AD_SYMLINK)) {
+                ade = ad_entry(adp, ADEID_FINDERI);
+                AFP_ASSERT(ade != NULL);
+
+	        memcpy(fdType, ade, 4);
                 if ( memcmp( fdType, "slnk", 4 ) == 0 ) {
 	 	    aint |= S_IFLNK;
             	}
@@ -839,6 +854,7 @@ int setfilparams(const AFPObj *obj, struct vol *vol,
     struct extmap	*em;
     int			bit, isad = 1, err = AFP_OK;
     char                *upath;
+    char		*ade = NULL;
     u_char              achar, *fdType, xyy[4]; /* uninitialized, OK 310105 */
     uint16_t		ashort, bshort, oshort;
     uint32_t		aint;
@@ -989,7 +1005,7 @@ int setfilparams(const AFPObj *obj, struct vol *vol,
     /* second try with adouble open 
     */
     if (ad_open(adp, upath, ADFLAGS_HF | ADFLAGS_RDWR | ADFLAGS_CREATE, 0666) < 0) {
-        LOG(log_debug, logtype_afpd, "setfilparams: ad_open_metadata error");
+        LOG(log_debug, logtype_afpd, "setfilparams: ad_open_metadata error: %s", strerror(errno));
         /*
          * For some things, we don't need an adouble header:
          * - change of modification date
@@ -1021,6 +1037,9 @@ int setfilparams(const AFPObj *obj, struct vol *vol,
 
         switch(  bit ) {
         case FILPBIT_ATTR :
+            if (isad == 0) {
+                break;
+            }
             ad_getattr(adp, &bshort);
             oshort = bshort;
             if ( ntohs( ashort ) & ATTRBIT_SETCLR ) {
@@ -1034,15 +1053,26 @@ int setfilparams(const AFPObj *obj, struct vol *vol,
             ad_setattr(adp, bshort);
             break;
         case FILPBIT_CDATE :
+            if (isad == 0) {
+                break;
+            }
             ad_setdate(adp, AD_DATE_CREATE, cdate);
             break;
         case FILPBIT_MDATE :
             break;
         case FILPBIT_BDATE :
+            if (isad == 0) {
+                break;
+            }
             ad_setdate(adp, AD_DATE_BACKUP, bdate);
             break;
         case FILPBIT_FINFO :
-            if (default_type( ad_entry( adp, ADEID_FINDERI ))
+            if (isad == 0) {
+                break;
+            }
+            ade = ad_entry(adp, ADEID_FINDERI);
+            AFP_ASSERT(ade != NULL);
+            if (default_type(ade)
                     && ( 
                      ((em = getextmap( path->m_name )) &&
                       !memcmp(finder_buf, em->em_type, sizeof( em->em_type )) &&
@@ -1053,7 +1083,7 @@ int setfilparams(const AFPObj *obj, struct vol *vol,
             )) {
                 memcpy(finder_buf, ufinderi, 8 );
             }
-            memcpy(ad_entry( adp, ADEID_FINDERI ), finder_buf, 32 );
+            memcpy(ade, finder_buf, 32 );
             break;
         case FILPBIT_UNIXPR :
             if (upriv_bit) {
@@ -1061,9 +1091,15 @@ int setfilparams(const AFPObj *obj, struct vol *vol,
             }
             break;
         case FILPBIT_PDINFO :
+            if (isad == 0) {
+                break;
+            }
+            ade = ad_entry(adp, ADEID_FINDERI);
+            AFP_ASSERT(ade != NULL);
+
             if (obj->afp_version < 30) { /* else it's UTF8 name */
-                memcpy(ad_entry( adp, ADEID_FINDERI ), fdType, 4 );
-                memcpy(ad_entry( adp, ADEID_FINDERI ) + 4, "pdos", 4 );
+                memcpy(ade, fdType, 4 );
+                memcpy(ade + 4, "pdos", 4 );
                 break;
             }
             /* fallthrough */
