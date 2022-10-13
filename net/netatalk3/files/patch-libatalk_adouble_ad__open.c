--- libatalk/adouble/ad_open.c.orig	2022-03-22 04:44:25 UTC
+++ libatalk/adouble/ad_open.c
@@ -140,17 +140,17 @@ static struct adouble_fops ad_adouble_ea = {
 
 static const struct entry entry_order2[ADEID_NUM_V2 + 1] = {
     {ADEID_NAME,        ADEDOFF_NAME_V2,     ADEDLEN_INIT},
-    {ADEID_COMMENT,     ADEDOFF_COMMENT_V2,  ADEDLEN_INIT},
+    {ADEID_COMMENT,     ADEDOFF_COMMENT_V2,  ADEDLEN_COMMENT},
     {ADEID_FILEDATESI,  ADEDOFF_FILEDATESI,  ADEDLEN_FILEDATESI},
     {ADEID_FINDERI,     ADEDOFF_FINDERI_V2,  ADEDLEN_FINDERI},
     {ADEID_DID,         ADEDOFF_DID,         ADEDLEN_DID},
     {ADEID_AFPFILEI,    ADEDOFF_AFPFILEI,    ADEDLEN_AFPFILEI},
     {ADEID_SHORTNAME,   ADEDOFF_SHORTNAME,   ADEDLEN_INIT},
     {ADEID_PRODOSFILEI, ADEDOFF_PRODOSFILEI, ADEDLEN_PRODOSFILEI},
-    {ADEID_PRIVDEV,     ADEDOFF_PRIVDEV,     ADEDLEN_INIT},
-    {ADEID_PRIVINO,     ADEDOFF_PRIVINO,     ADEDLEN_INIT},
-    {ADEID_PRIVSYN,     ADEDOFF_PRIVSYN,     ADEDLEN_INIT},
-    {ADEID_PRIVID,      ADEDOFF_PRIVID,      ADEDLEN_INIT},
+    {ADEID_PRIVDEV,     ADEDOFF_PRIVDEV,     ADEDLEN_PRIVDEV},
+    {ADEID_PRIVINO,     ADEDOFF_PRIVINO,     ADEDLEN_PRIVINO},
+    {ADEID_PRIVSYN,     ADEDOFF_PRIVSYN,     ADEDLEN_PRIVSYN},
+    {ADEID_PRIVID,      ADEDOFF_PRIVID,      ADEDLEN_PRIVID},
     {ADEID_RFORK,       ADEDOFF_RFORK_V2,    ADEDLEN_INIT},
     {0, 0, 0}
 };
@@ -158,13 +158,13 @@ static const struct entry entry_order2[ADEID_NUM_V2 + 
 /* Using Extended Attributes */
 static const struct entry entry_order_ea[ADEID_NUM_EA + 1] = {
     {ADEID_FINDERI,    ADEDOFF_FINDERI_EA,    ADEDLEN_FINDERI},
-    {ADEID_COMMENT,    ADEDOFF_COMMENT_EA,    ADEDLEN_INIT},
+    {ADEID_COMMENT,    ADEDOFF_COMMENT_EA,    ADEDLEN_COMMENT},
     {ADEID_FILEDATESI, ADEDOFF_FILEDATESI_EA, ADEDLEN_FILEDATESI},
     {ADEID_AFPFILEI,   ADEDOFF_AFPFILEI_EA,   ADEDLEN_AFPFILEI},
-    {ADEID_PRIVDEV,    ADEDOFF_PRIVDEV_EA,    ADEDLEN_INIT},
-    {ADEID_PRIVINO,    ADEDOFF_PRIVINO_EA,    ADEDLEN_INIT},
-    {ADEID_PRIVSYN,    ADEDOFF_PRIVSYN_EA,    ADEDLEN_INIT},
-    {ADEID_PRIVID,     ADEDOFF_PRIVID_EA,     ADEDLEN_INIT},
+    {ADEID_PRIVDEV,    ADEDOFF_PRIVDEV_EA,    ADEDLEN_PRIVDEV},
+    {ADEID_PRIVINO,    ADEDOFF_PRIVINO_EA,    ADEDLEN_PRIVINO},
+    {ADEID_PRIVSYN,    ADEDOFF_PRIVSYN_EA,    ADEDLEN_PRIVSYN},
+    {ADEID_PRIVID,     ADEDOFF_PRIVID_EA,     ADEDLEN_PRIVID},
     {0, 0, 0}
 };
 
@@ -360,15 +360,22 @@ static int new_ad_header(struct adouble *ad, const cha
     const struct entry  *eid;
     uint16_t            ashort;
     struct stat         st;
+    char                *adp = NULL;
 
     LOG(log_debug, logtype_ad, "new_ad_header(\"%s\")", path);
 
     if (ad_init_offsets(ad) != 0)
         return -1;
 
+    if (ad->valid_data_len == 0) {
+        ad->valid_data_len = ad->ad_vers == AD_VERSION_EA ? AD_DATASZ_EA : AD_DATASZ2;
+    }
+    adp = ad_entry(ad, ADEID_FINDERI);
+    AFP_ASSERT(adp != NULL);
+
     /* set default creator/type fields */
-    memcpy(ad_entry(ad, ADEID_FINDERI) + FINDERINFO_FRTYPEOFF,"\0\0\0\0", 4);
-    memcpy(ad_entry(ad, ADEID_FINDERI) + FINDERINFO_FRCREATOFF,"\0\0\0\0", 4);
+    memcpy(adp + FINDERINFO_FRTYPEOFF,"\0\0\0\0", 4);
+    memcpy(adp + FINDERINFO_FRCREATOFF,"\0\0\0\0", 4);
 
     /* make things invisible */
     if ((ad->ad_options & ADVOL_INVDOTS)
@@ -378,14 +385,16 @@ static int new_ad_header(struct adouble *ad, const cha
         ashort = htons(ATTRBIT_INVISIBLE);
         ad_setattr(ad, ashort);
         ashort = htons(FINDERINFO_INVISIBLE);
-        memcpy(ad_entry(ad, ADEID_FINDERI) + FINDERINFO_FRFLAGOFF, &ashort, sizeof(ashort));
+        memcpy(adp + FINDERINFO_FRFLAGOFF, &ashort, sizeof(ashort));
     }
 
     /* put something sane in the date fields */
     if (stp == NULL) {
         stp = &st;
-        if (lstat(path, &st) != 0)
+        if (lstat(path, &st) != 0) {
+            ad->valid_data_len = 0;
             return -1;
+        }
     }
     ad_setdate(ad, AD_DATE_CREATE | AD_DATE_UNIX, stp->st_mtime);
     ad_setdate(ad, AD_DATE_MODIFY | AD_DATE_UNIX, stp->st_mtime);
@@ -417,7 +426,7 @@ static int parse_entries(struct adouble *ad, uint16_t 
 
         if (!eid
             || eid > ADEID_MAX
-            || off >= valid_data_len
+            || ((eid != ADEID_RFORK) && (off >= valid_data_len))
             || ((eid != ADEID_RFORK) && (off + len >  valid_data_len)))
         {
             LOG(log_warning, logtype_ad, "parse_entries: bogus eid: %u, off: %u, len: %u",
@@ -782,20 +791,42 @@ static int ad_header_read_ea(const char *path, struct 
         EC_FAIL;
     }
 
+    /*
+     * It is possible for AFP metadata to contain a zero-length
+     * comment. This will cause ad_entry(ad, ADEID_COMMENT) to return NULL
+     * but should not be treated as an error condition.
+     * Since recent CVE fixes have introduced new behavior regarding
+     * ad_entry() output. For now, we will AFP_ASSERT() in EC_CLEANUP to prevent
+     * altering on-disk info. This does introduce an avenue to DOS
+     * the netatalk server by locally writing garbage to the EA. At this
+     * point, the outcome is an acceptable risk to prevent unintended
+     * changes to metadata.
+     */
     if (nentries != ADEID_NUM_EA
         || !ad_entry(ad, ADEID_FINDERI)
-        || !ad_entry(ad, ADEID_COMMENT)
         || !ad_entry(ad, ADEID_FILEDATESI)
         || !ad_entry(ad, ADEID_AFPFILEI)
         || !ad_entry(ad, ADEID_PRIVDEV)
         || !ad_entry(ad, ADEID_PRIVINO)
         || !ad_entry(ad, ADEID_PRIVSYN)
         || !ad_entry(ad, ADEID_PRIVID)) {
-        LOG(log_error, logtype_ad, "ad_header_read_ea(\"%s\"): invalid metadata EA", fullpathname(path));
+        LOG(log_error, logtype_ad,
+            "ad_header_read_ea(\"%s\"): invalid metadata EA "
+            "this is now being treated as a fatal error. "
+            "if you see this log entry, please file a bug ticket "
+            "with your upstream vendor and attach the generated "
+            "core file.", path ? fullpathname(path) : "UNKNOWN");
+
         errno = EINVAL;
         EC_FAIL;
     }
 
+    if (!ad_entry(ad, ADEID_COMMENT) &&
+        (ad->ad_eid[ADEID_COMMENT].ade_len != 0)) {
+        errno = EINVAL;
+        EC_FAIL;
+    }
+
     /*
      * Ensure the resource fork offset is always set
      */
@@ -805,6 +836,8 @@ static int ad_header_read_ea(const char *path, struct 
 #endif
 
 EC_CLEANUP:
+    AFP_ASSERT(!(ret != 0 && errno == EINVAL));
+#if 0
     if (ret != 0 && errno == EINVAL) {
         become_root();
         (void)sys_removexattr(path, AD_EA_META);
@@ -812,6 +845,7 @@ EC_CLEANUP:
         LOG(log_error, logtype_ad, "ad_header_read_ea(\"%s\"): deleted invalid metadata EA", fullpathname(path), nentries);
         errno = ENOENT;
     }
+#endif
     EC_EXIT;
 }
 
