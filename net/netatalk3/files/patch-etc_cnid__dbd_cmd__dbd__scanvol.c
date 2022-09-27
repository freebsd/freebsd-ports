--- etc/cnid_dbd/cmd_dbd_scanvol.c.orig	2022-02-28 13:32:06 UTC
+++ etc/cnid_dbd/cmd_dbd_scanvol.c
@@ -560,6 +560,7 @@ static int read_addir(void)
 static cnid_t check_cnid(const char *name, cnid_t did, struct stat *st, int adfile_ok)
 {
     int adflags = ADFLAGS_HF;
+    int err;
     cnid_t db_cnid, ad_cnid;
     struct adouble ad;
 
@@ -602,7 +603,13 @@ static cnid_t check_cnid(const char *name, cnid_t did,
                     cwdbuf, name, strerror(errno));
             return CNID_INVALID;
         }
-        ad_setid( &ad, st->st_dev, st->st_ino, db_cnid, did, stamp);
+        err = ad_setid( &ad, st->st_dev, st->st_ino, db_cnid, did, stamp);
+        if (err == -1) {
+            dbd_log(LOGSTD, "Error setting new CNID, malformed adouble: '%s/%s'",
+                    cwdbuf, name);
+            ad_close(&ad, ADFLAGS_HF);
+            return CNID_INVALID;
+        }
         ad_flush(&ad);
         ad_close(&ad, ADFLAGS_HF);
     }
