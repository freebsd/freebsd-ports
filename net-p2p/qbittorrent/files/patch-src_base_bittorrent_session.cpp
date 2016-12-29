Revert the following commit until libtorrent 1.1.2 is released:

From 729c80f9104a3d01ec724351bd6910b4b8d14c6c Mon Sep 17 00:00:00 2001
From: sledgehammer999 <hammered999@gmail.com>
Date: Mon, 31 Oct 2016 02:31:56 +0200
Subject: [PATCH] Use new libtorrent 1.1.2+ utility function to generate client
 ID instead.

--- src/base/bittorrent/session.cpp.orig	2016-12-17 18:02:06 UTC
+++ src/base/bittorrent/session.cpp
@@ -45,6 +45,7 @@
 #include <QTimer>
 
 #include <cstdlib>
+#include <sstream>
 #include <queue>
 #include <vector>
 
@@ -194,6 +195,36 @@ namespace
 
     template <typename T>
     LowerLimited<T> lowerLimited(T limit, T ret) { return LowerLimited<T>(limit, ret); }
+
+#if LIBTORRENT_VERSION_NUM >= 10100
+    std::string makeFingerprint(const char* peerId, int major, int minor, int revision, int tag)
+    {
+        Q_ASSERT(peerId);
+        Q_ASSERT(major >= 0);
+        Q_ASSERT(minor >= 0);
+        Q_ASSERT(revision >= 0);
+        Q_ASSERT(tag >= 0);
+        Q_ASSERT(std::strlen(peerId) == 2);
+
+        auto versionToChar = [](int v) -> char
+        {
+            if (v >= 0 && v < 10) return static_cast<char>('0' + v);
+            if (v >= 10) return static_cast<char>('A' + (v - 10));
+            Q_ASSERT(false);
+            return '0';
+        };
+
+        std::ostringstream buf;
+        buf << '-'
+            << peerId
+            << versionToChar(major)
+            << versionToChar(minor)
+            << versionToChar(revision)
+            << versionToChar(tag)
+            << '-';
+        return buf.str();
+    }
+#endif
 }
 
 // Session
@@ -334,7 +365,7 @@ Session::Session(QObject *parent)
         dispatchAlerts(alertPtr.release());
     });
 #else
-    std::string peerId = libt::generate_fingerprint(PEER_ID, VERSION_MAJOR, VERSION_MINOR, VERSION_BUGFIX, VERSION_BUILD);
+    std::string peerId = makeFingerprint(PEER_ID, VERSION_MAJOR, VERSION_MINOR, VERSION_BUGFIX, VERSION_BUILD);
     libt::settings_pack pack;
     pack.set_int(libt::settings_pack::alert_mask, alertMask);
     pack.set_str(libt::settings_pack::peer_fingerprint, peerId);
