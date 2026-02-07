# Based on https://github.com/benhoyt/scandir/pull/109
# TODO: Upstream
# See: https://github.com/benhoyt/scandir/issues/122

From cfda49a07865097d3fdadc4e321881635ab2f795 Mon Sep 17 00:00:00 2001
From: "Elias M. Mariani" <marianielias@gmail.com>
Date: Mon, 6 Aug 2018 12:06:44 -0300
Subject: [PATCH] Fix dirent.h struct alignment on OpenBSD

--- scandir.py.orig	2019-03-09 17:51:39 UTC
+++ scandir.py
@@ -432,6 +432,16 @@ elif sys.platform.startswith(('linux', 'darwin', 'suno
                     ('__d_padding', ctypes.c_uint8 * 4),
                     ('d_name', ctypes.c_char * 256),
                 )
+            elif 'freebsd' in sys.platform:
+                _fields_ = (
+                    ('d_ino', ctypes.c_uint64),
+                    ('d_off', ctypes.c_uint64),
+                    ('d_reclen', ctypes.c_uint16),
+                    ('d_type', ctypes.c_uint8),
+                    ('d_namlen', ctypes.c_uint8),
+                    ('__d_padding', ctypes.c_uint8 * 4),
+                    ('d_name', ctypes.c_char * 256),
+                )
             else:
                 _fields_ = (
                     ('d_ino', ctypes.c_uint32),  # must be uint32, not ulong
