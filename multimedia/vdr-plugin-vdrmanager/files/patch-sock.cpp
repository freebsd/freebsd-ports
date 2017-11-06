From 333d83324710bbdef6f6feea38a9dadc3c01b959 Mon Sep 17 00:00:00 2001
From: bju <bju@maxi.fritz.box>
Date: Tue, 24 Jan 2012 23:06:34 +0100
Subject: Close() has used socket (method pointer) and not sock (variable) to
 check if close() should be called.

--- a/sock.cpp.orig	2011-12-28 15:11:48 UTC
+++ b/sock.cpp
@@ -20,7 +20,7 @@ cVdrmanagerSocket::~cVdrmanagerSocket() 
 }
 
 void cVdrmanagerSocket::Close() {
-	if (socket >= 0) {
+	if (sock >= 0) {
 		close(sock);
 		sock = -1;
 	}
