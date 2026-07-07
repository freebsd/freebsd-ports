From 3cee1c59bc937597b496fea5e7df84a2db9989ea Mon Sep 17 00:00:00 2001
From: Matthias Andree <matthias.andree@gmx.de>
Date: Thu, 2 Jul 2026 23:26:06 +0200
Subject: [PATCH] LMDB: call mdb_env_get_maxkeysize() after mdb_env_open()

LMDB 1.0.0 would otherwise return 0 and we'd ignore our entire database
--- src/datastore_lmdb.c.orig	2025-04-09 19:50:41 UTC
+++ src/datastore_lmdb.c
@@ -202,8 +202,6 @@ a_bflm_init(bfpath *bfp, bool rdonly){
         goto jerr1;
     }
 
-    rv->bflm_maxkeysize = mdb_env_get_maxkeysize(rv->bflm_env);
-
     /* To accommodate bogofilter's db_created() mechanism, we cannot use the 
      * unnamed DB which "always exists", but must place data in named ones */
     e = mdb_env_set_maxdbs(rv->bflm_env, 2);
@@ -230,6 +228,8 @@ a_bflm_init(bfpath *bfp, bool rdonly){
         emsg = "mdb_env_open()";
         goto jerr2;
     }
+
+    rv->bflm_maxkeysize = mdb_env_get_maxkeysize(rv->bflm_env);
 
     /* Let us fake a "has been created" event :( */
     if(!(rv->bflm_flags & a_BFLM_RDONLY) &&
