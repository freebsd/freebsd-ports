--- libatalk/adouble/ad_conv.c.orig	2022-02-28 13:32:06 UTC
+++ libatalk/adouble/ad_conv.c
@@ -93,6 +93,7 @@ static int ad_conv_v22ea_hf(const char *path, const st
         goto copy;
     if (ad_getentryoff(&adv2, ADEID_FINDERI)
         && (ad_getentrylen(&adv2, ADEID_FINDERI) == ADEDLEN_FINDERI)
+        && (ad_entry(&adv2, ADEID_FINDERI) != NULL)
         && (memcmp(ad_entry(&adv2, ADEID_FINDERI), emptyad, ADEDLEN_FINDERI) != 0))
         goto copy;
     if (ad_getentryoff(&adv2, ADEID_FILEDATESI)) {
@@ -101,7 +102,7 @@ static int ad_conv_v22ea_hf(const char *path, const st
         if ((ctime != mtime) || (mtime != sp->st_mtime))
             goto copy;
     }
-    if (ad_getentryoff(&adv2, ADEID_AFPFILEI)) {
+    if (ad_getentryoff(&adv2, ADEID_AFPFILEI) && (ad_entry(&adv2, ADEID_AFPFILEI) != NULL)) {
         if (memcmp(ad_entry(&adv2, ADEID_AFPFILEI), &afpinfo, ADEDLEN_AFPFILEI) != 0)
             goto copy;
     }
@@ -115,6 +116,7 @@ copy:
     EC_ZERO_LOGSTR( ad_open(&adea, path, adflags | ADFLAGS_HF | ADFLAGS_RDWR | ADFLAGS_CREATE),
                     "ad_conv_v22ea_hf(\"%s\"): error creating metadata EA: %s",
                     fullpathname(path), strerror(errno));
+    AFP_ASSERT(ad_refresh(path, &adea) == 0);
     EC_ZERO_LOG( ad_copy_header(&adea, &adv2) );
     ad_flush(&adea);
 
