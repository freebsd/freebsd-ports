--- src/bittorrent.h.orig	Sun Sep  9 06:09:24 2007
+++ src/bittorrent.h	Mon Oct  1 12:37:38 2007
@@ -27,6 +27,7 @@
 #include <QStringList>
 
 #include <libtorrent/session.hpp>
+#include <libtorrent/ip_filter.hpp>
 #include "qtorrenthandle.h"
 
 using namespace libtorrent;
