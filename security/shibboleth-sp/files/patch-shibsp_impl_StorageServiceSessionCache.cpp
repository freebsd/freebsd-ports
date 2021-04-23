From 5a47c3b9378f4c49392dd4d15189b70956f9f2ec Mon Sep 17 00:00:00 2001
From: Scott Cantor <cantor.2@osu.edu>
Date: Thu, 22 Apr 2021 15:58:43 -0400
Subject: [PATCH] SSPCPP-927 - Check for missing DataSealer during cookie recovery

https://issues.shibboleth.net/jira/browse/SSPCPP-927

--- shibsp/impl/StorageServiceSessionCache.cpp.orig	2020-12-07 20:51:12.000000000 +0000
+++ shibsp/impl/StorageServiceSessionCache.cpp	2021-04-23 16:17:00.398821000 +0000
@@ -1148,6 +1148,12 @@
     else {
         // We're out of process, so we can recover the session.
 #ifndef SHIBSP_LITE
+        const DataSealer* sealer = XMLToolingConfig::getConfig().getDataSealer();
+        if (!sealer) {
+            m_log.warn("can't attempt recovery of session (%s), no DataSealer configured", key);
+            return false;
+        }
+
         m_log.debug("checking for revocation of session (%s)", key);
         try {
             if (m_storage_lite->readString("Revoked", key) > 0) {
@@ -1174,7 +1180,7 @@
         try {
             dup = strdup(data);
             XMLToolingConfig::getConfig().getURLEncoder()->decode(dup);
-            unwrapped = XMLToolingConfig::getConfig().getDataSealer()->unwrap(dup);
+            unwrapped = sealer->unwrap(dup);
             free(dup);
 
             stringstream str(unwrapped);
