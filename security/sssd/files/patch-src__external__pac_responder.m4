From b52128bc333fd4717a96950ef8fb4171f25fabcf Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Wed, 30 Oct 2013 08:54:41 +0100
Subject: [PATCH 2/4] patch-src__external__pac_responder.m4

---
 src/external/pac_responder.m4 | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)

diff --git src/external/pac_responder.m4 src/external/pac_responder.m4
index 49d5cbb..2b4ca5c 100644
--- src/external/pac_responder.m4
+++ src/external/pac_responder.m4
@@ -14,7 +14,7 @@ then
     PKG_CHECK_MODULES(NDR_KRB5PAC, ndr_krb5pac, ndr_krb5pac_ok=yes,
         AC_MSG_WARN([Cannot build pac responder without libndr_krb5pac]))
 
-    AC_PATH_PROG(KRB5_CONFIG, krb5-config)
+    AC_PATH_PROG(KRB5_CONFIG, krb5-config, [], [/usr/local/bin:$PATH])
     AC_MSG_CHECKING(for supported MIT krb5 version)
     KRB5_VERSION="`$KRB5_CONFIG --version`"
     case $KRB5_VERSION in
-- 
1.8.0

