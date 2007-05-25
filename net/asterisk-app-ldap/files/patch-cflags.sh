--- cflags.sh.orig	Tue Apr 17 14:11:19 2007
+++ cflags.sh	Tue Apr 17 14:13:40 2007
@@ -11,6 +11,11 @@ else
   INCDIR=/usr/include/asterisk
 fi
 
+if [ ${OSARCH} = "FreeBSD" ]; then
+  INCDIR=/usr/local/include/asterisk
+  CFLAGS="${CFLAGS} -I/usr/local/include -L/usr/local/lib"
+fi
+
 CHANNEL_H=${INCDIR}/channel.h
 if [ "`grep 'struct ast_callerid cid' ${CHANNEL_H}`" != "" ]; then
     CFLAGS="${CFLAGS} -DCHANNEL_HAS_CID"
