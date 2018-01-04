From 2155dd9153457886c4f5dac58dcf269eeb2a8122 Mon Sep 17 00:00:00 2001
From: Hidde van der Heide <hvanderheide@nexuz.net>
Date: Thu, 19 Oct 2017 16:10:56 +0200
Subject: [PATCH] Add libcache to installed headers and removed relative import

---
 example/Makefile.am         | 2 +-
 src/include/ndpi_typedefs.h | 2 +-
 src/lib/Makefile.am         | 3 ++-
 3 files changed, 4 insertions(+), 3 deletions(-)

diff --git a/example/Makefile.am b/example/Makefile.am
index 7fc29402..6cc6a14c 100644
--- example/Makefile.am
+++ example/Makefile.am
@@ -1,6 +1,6 @@
 bin_PROGRAMS = ndpiReader
 
-AM_CPPFLAGS = -I$(top_srcdir)/src/include @PCAP_INC@
+AM_CPPFLAGS = -I$(top_srcdir)/src/include -I$(top_srcdir)/src/lib/third_party/include @PCAP_INC@
 AM_CFLAGS = @PTHREAD_CFLAGS@ # --coverage
 
 LDADD = $(top_builddir)/src/lib/libndpi.la @JSON_C_LIB@ @PTHREAD_LIBS@ @PCAP_LIB@ @DL_LIB@ -lm
diff --git a/src/include/ndpi_typedefs.h b/src/include/ndpi_typedefs.h
index 33043fde..0587503f 100644
--- src/include/ndpi_typedefs.h
+++ src/include/ndpi_typedefs.h
@@ -25,7 +25,7 @@
 #define __NDPI_TYPEDEFS_H__
 
 #include "ndpi_define.h"
-#include "../lib/third_party/include/libcache.h"
+#include "libcache.h"
 
 #define BT_ANNOUNCE
 #define SNAP_EXT
diff --git a/src/lib/Makefile.am b/src/lib/Makefile.am
index c2b4e4b1..39823d37 100644
--- src/lib/Makefile.am
+++ src/lib/Makefile.am
@@ -12,7 +12,8 @@ libndpi_la_include_HEADERS = ../include/ndpi_api.h \
 			     ../include/ndpi_includes.h \
 			     ../include/ndpi_protocol_ids.h \
 			     ../include/ndpi_protocols.h \
-			     ../include/ndpi_typedefs.h
+			     ../include/ndpi_typedefs.h \
+			     third_party/include/libcache.h
 
 libndpi_la_SOURCES = ndpi_content_match.c.inc \
 		     ndpi_main.c \
