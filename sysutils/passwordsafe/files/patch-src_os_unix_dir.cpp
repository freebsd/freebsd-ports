From 9cdf2cd3ad5de5034d367b8283c071ad90ad2055 Mon Sep 17 00:00:00 2001
From: Bernard Spil <brnrd@FreeBSD.org>
Date: Sun, 5 Feb 2017 15:36:48 +0100
Subject: [PATCH] Obey hier(8) on FreeBSD

Signed-off-by: Bernard Spil <brnrd@FreeBSD.org>
---
 src/os/unix/dir.cpp | 8 ++++++++
  1 file changed, 8 insertions(+)
	
--- src/os/unix/dir.cpp.orig	2016-12-21 20:10:25 UTC
+++ src/os/unix/dir.cpp
@@ -173,10 +173,18 @@ stringT pws_os::getsafedir(void)
 
 stringT pws_os::getxmldir(void)
 {
+#ifdef __FreeBSD__
+  return _S("/usr/local/share/pwsafe/xml/");
+#else
   return _S("/usr/share/pwsafe/xml/");
+#endif
 }
 
 stringT pws_os::gethelpdir(void)
 {
+#ifdef __FreeBSD__
+  return _S("/usr/local/share/doc/passwordsafe/help/");
+#else
   return _S("/usr/share/doc/passwordsafe/help/");
+#endif
 }
