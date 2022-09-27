--- libatalk/adouble/ad_attr.c.orig	2022-02-28 13:32:06 UTC
+++ libatalk/adouble/ad_attr.c
@@ -2,8 +2,10 @@
 #include "config.h"
 #endif /* HAVE_CONFIG_H */
 
+#include <stdlib.h>
 #include <string.h>
 #include <arpa/inet.h>
+#include <atalk/util.h>
 #include <atalk/adouble.h>
 #include <atalk/logger.h>
 
@@ -22,10 +24,17 @@ int ad_getattr(const struct adouble *ad, uint16_t *att
     *attr = 0;
 
     if (ad_getentryoff(ad, ADEID_AFPFILEI)) {
-        memcpy(attr, ad_entry(ad, ADEID_AFPFILEI) + AFPFILEIOFF_ATTR, 2);
+        char *adp = NULL;
 
+        adp = ad_entry(ad, ADEID_AFPFILEI);
+        AFP_ASSERT(adp != NULL);
+        memcpy(attr, adp + AFPFILEIOFF_ATTR, 2);
+
         /* Now get opaque flags from FinderInfo */
-        memcpy(&fflags, ad_entry(ad, ADEID_FINDERI) + FINDERINFO_FRFLAGOFF, 2);
+        adp = ad_entry(ad, ADEID_FINDERI);
+        AFP_ASSERT(adp != NULL);
+        memcpy(&fflags, adp + FINDERINFO_FRFLAGOFF, 2);
+
         if (fflags & htons(FINDERINFO_INVISIBLE))
             *attr |= htons(ATTRBIT_INVISIBLE);
         else
@@ -61,10 +70,15 @@ int ad_setattr(const struct adouble *ad, const uint16_
         attr &= ~(ATTRBIT_MULTIUSER | ATTRBIT_NOWRITE | ATTRBIT_NOCOPY);
 
     if (ad_getentryoff(ad, ADEID_AFPFILEI) && ad_getentryoff(ad, ADEID_FINDERI)) {
-        memcpy(ad_entry(ad, ADEID_AFPFILEI) + AFPFILEIOFF_ATTR, &attr, sizeof(attr));
+        char *adp = NULL;
+
+        adp = ad_entry(ad, ADEID_FINDERI);
+        AFP_ASSERT(adp != NULL);
+
+        memcpy(adp + AFPFILEIOFF_ATTR, &attr, sizeof(attr));
             
         /* Now set opaque flags in FinderInfo too */
-        memcpy(&fflags, ad_entry(ad, ADEID_FINDERI) + FINDERINFO_FRFLAGOFF, 2);
+        memcpy(&fflags, adp + FINDERINFO_FRFLAGOFF, 2);
         if (attr & htons(ATTRBIT_INVISIBLE))
             fflags |= htons(FINDERINFO_INVISIBLE);
         else
@@ -77,7 +91,7 @@ int ad_setattr(const struct adouble *ad, const uint16_
         } else
             fflags &= htons(~FINDERINFO_ISHARED);
 
-        memcpy(ad_entry(ad, ADEID_FINDERI) + FINDERINFO_FRFLAGOFF, &fflags, 2);
+        memcpy(adp + FINDERINFO_FRFLAGOFF, &fflags, 2);
     }
 
     return 0;
@@ -86,54 +100,114 @@ int ad_setattr(const struct adouble *ad, const uint16_
 /* --------------
  * save file/folder ID in AppleDoubleV2 netatalk private parameters
  * return 1 if resource fork has been modified
+ * return -1 on error.
  */
 int ad_setid (struct adouble *adp, const dev_t dev, const ino_t ino , const uint32_t id, const cnid_t did, const void *stamp)
 {
     uint32_t tmp;
+    char *ade = NULL;
 
     ad_setentrylen( adp, ADEID_PRIVID, sizeof(id));
     tmp = id;
     if (adp->ad_vers == AD_VERSION_EA)
         tmp = htonl(tmp);
-    memcpy(ad_entry( adp, ADEID_PRIVID ), &tmp, sizeof(tmp));
 
+    ade = ad_entry(adp, ADEID_PRIVID);
+    if (ade == NULL) {
+        LOG(log_warning, logtype_ad, "ad_setid: failed to set ADEID_PRIVID\n");
+        return -1;
+    }
+    memcpy(ade, &tmp, sizeof(tmp));
+
     ad_setentrylen( adp, ADEID_PRIVDEV, sizeof(dev_t));
+    ade = ad_entry(adp, ADEID_PRIVDEV);
+    if (ade == NULL) {
+        LOG(log_warning, logtype_ad, "ad_setid: failed to set ADEID_PRIVDEV\n");
+        return -1;
+    }
+
     if ((adp->ad_options & ADVOL_NODEV)) {
-        memset(ad_entry( adp, ADEID_PRIVDEV ), 0, sizeof(dev_t));
+        memset(ade, 0, sizeof(dev_t));
     } else {
-        memcpy(ad_entry( adp, ADEID_PRIVDEV ), &dev, sizeof(dev_t));
+        memcpy(ade, &dev, sizeof(dev_t));
     }
 
     ad_setentrylen( adp, ADEID_PRIVINO, sizeof(ino_t));
-    memcpy(ad_entry( adp, ADEID_PRIVINO ), &ino, sizeof(ino_t));
 
-    ad_setentrylen( adp, ADEID_DID, sizeof(did));
-    memcpy(ad_entry( adp, ADEID_DID ), &did, sizeof(did));
+    ade = ad_entry(adp, ADEID_PRIVINO);
+    if (ade == NULL) {
+        LOG(log_warning, logtype_ad, "ad_setid: failed to set ADEID_PRIVINO\n");
+        return -1;
+    }
+    memcpy(ade, &ino, sizeof(ino_t));
 
+    if (adp->ad_vers != AD_VERSION_EA) {
+        ad_setentrylen( adp, ADEID_DID, sizeof(did));
+
+        ade = ad_entry(adp, ADEID_DID);
+        if (ade == NULL) {
+            LOG(log_warning, logtype_ad, "ad_setid: failed to set ADEID_DID\n");
+            return -1;
+        }
+        memcpy(ade, &did, sizeof(did));
+    }
+
     ad_setentrylen( adp, ADEID_PRIVSYN, ADEDLEN_PRIVSYN);
-    memcpy(ad_entry( adp, ADEID_PRIVSYN ), stamp, ADEDLEN_PRIVSYN);
+    ade = ad_entry(adp, ADEID_PRIVSYN);
+    if (ade == NULL) {
+        LOG(log_warning, logtype_ad, "ad_setid: failed to set ADEID_PRIVSYN\n");
+        return -1;
+    }
+    memcpy(ade, stamp, ADEDLEN_PRIVSYN);
 
     return 1;
 }
 
-/* ----------------------------- */
+/*
+ * Retrieve stored file / folder. Callers should treat a return of CNID_INVALID (0) as an invalid value.
+ */
 uint32_t ad_getid (struct adouble *adp, const dev_t st_dev, const ino_t st_ino , const cnid_t did, const void *stamp _U_)
 {
     uint32_t aint = 0;
     dev_t  dev;
     ino_t  ino;
-    cnid_t a_did;
+    cnid_t a_did = 0;
 
     if (adp) {
         if (sizeof(dev_t) == ad_getentrylen(adp, ADEID_PRIVDEV)) {
-            memcpy(&dev, ad_entry(adp, ADEID_PRIVDEV), sizeof(dev_t));
-            memcpy(&ino, ad_entry(adp, ADEID_PRIVINO), sizeof(ino_t));
-            memcpy(&a_did, ad_entry(adp, ADEID_DID), sizeof(cnid_t));
+            char *ade = NULL;
+            ade = ad_entry(adp, ADEID_PRIVDEV);
+            if (ade == NULL) {
+                LOG(log_warning, logtype_ad, "ad_getid: failed to retrieve ADEID_PRIVDEV\n");
+                return CNID_INVALID;
+            }
+            memcpy(&dev, ade, sizeof(dev_t));
+            ade = ad_entry(adp, ADEID_PRIVINO);
+            if (ade == NULL) {
+                LOG(log_warning, logtype_ad, "ad_getid: failed to retrieve ADEID_PRIVINO\n");
+                return CNID_INVALID;
+            }
+            memcpy(&ino, ade, sizeof(ino_t));
 
+            if (adp->ad_vers != AD_VERSION_EA) {
+                /* ADEID_DID is not stored for AD_VERSION_EA */
+                ade = ad_entry(adp, ADEID_DID);
+                if (ade == NULL) {
+                    LOG(log_warning, logtype_ad, "ad_getid: failed to retrieve ADEID_DID\n");
+                    return CNID_INVALID;
+                }
+                memcpy(&a_did, ade, sizeof(cnid_t));
+            }
+
             if (((adp->ad_options & ADVOL_NODEV) || (dev == st_dev))
                 && ino == st_ino
-                && (!did || a_did == did) ) {
-                memcpy(&aint, ad_entry(adp, ADEID_PRIVID), sizeof(aint));
+                && (!did || a_did == 0 || a_did == did) ) {
+                ade = ad_entry(adp, ADEID_PRIVID);
+                if (ade == NULL) {
+                    LOG(log_warning, logtype_ad, "ad_getid: failed to retrieve ADEID_PRIVID\n");
+                    return CNID_INVALID;
+                }
+                memcpy(&aint, ade, sizeof(aint));
                 if (adp->ad_vers == AD_VERSION2)
                     return aint;
                 else
@@ -141,7 +215,7 @@ uint32_t ad_getid (struct adouble *adp, const dev_t st
             }
         }
     }
-    return 0;
+    return CNID_INVALID;
 }
 
 /* ----------------------------- */
@@ -150,13 +224,18 @@ uint32_t ad_forcegetid (struct adouble *adp)
     uint32_t aint = 0;
 
     if (adp) {
-        memcpy(&aint, ad_entry(adp, ADEID_PRIVID), sizeof(aint));
+        char *ade = NULL;
+        ade = ad_entry(adp, ADEID_PRIVID);
+        if (ade == NULL) {
+            return CNID_INVALID;
+        }
+        memcpy(&aint, ade, sizeof(aint));
         if (adp->ad_vers == AD_VERSION2)
             return aint;
         else
             return ntohl(aint);
     }
-    return 0;
+    return CNID_INVALID;
 }
 
 /* -----------------
@@ -168,8 +247,13 @@ int ad_setname(struct adouble *ad, const char *path)
     if ((len = strlen(path)) > ADEDLEN_NAME)
         len = ADEDLEN_NAME;
     if (path && ad_getentryoff(ad, ADEID_NAME)) {
+        char *ade = NULL;
         ad_setentrylen( ad, ADEID_NAME, len);
-        memcpy(ad_entry( ad, ADEID_NAME ), path, len);
+        ade = ad_entry(ad, ADEID_NAME);
+        if (ade == NULL) {
+            return -1;
+        }
+        memcpy(ade, path, len);
         return 1;
     }
     return 0;
