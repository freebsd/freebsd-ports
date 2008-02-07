--- cflags.sh.orig	Wed Oct 24 23:37:00 2007
+++ cflags.sh	Wed Oct 24 23:31:46 2007
@@ -8,7 +8,8 @@
   INCDIR=/Library/Asterisk/include
   CFLAGS="${CFLAGS} -I/Library/Asterisk/include"
 else
-  INCDIR=/usr/include
+  INCDIR=${LOCALBASE}/include
+  CFLAGS="${CFLAGS} -I${INCDIR}"
 fi
 
 CHANNEL_H=${INCDIR}/asterisk/channel.h
