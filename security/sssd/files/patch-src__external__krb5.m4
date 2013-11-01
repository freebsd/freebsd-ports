From b7947258702e250dbf569bb9cd74f1e73f0c94bb Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Wed, 30 Oct 2013 08:53:42 +0100
Subject: [PATCH 1/4] patch-src__external__krb5.m4

---
 src/external/krb5.m4 | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)

diff --git src/external/krb5.m4 src/external/krb5.m4
index 71239c9..63c8ece 100644
--- src/external/krb5.m4
+++ src/external/krb5.m4
@@ -9,7 +9,7 @@ if test x$KRB5_CFLAGS != x; then
     KRB5_PASSED_CFLAGS=$KRB5_CFLAGS
 fi
 
-AC_PATH_PROG(KRB5_CONFIG, krb5-config)
+AC_PATH_PROG(KRB5_CONFIG, krb5-config, [], [/usr/local/bin:$PATH])
 AC_MSG_CHECKING(for working krb5-config)
 if test -x "$KRB5_CONFIG"; then
   KRB5_CFLAGS="`$KRB5_CONFIG --cflags`"
-- 
1.8.0

