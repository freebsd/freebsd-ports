--- cflags.sh.orig	Sun Jul 30 12:23:23 2006
+++ cflags.sh	Wed Jul 19 10:09:51 2006
@@ -1,13 +1,13 @@
 #!/bin/sh
 
-CFLAGS="-g -Wall -D_REENTRANT -D_GNU_SOURCE -fPIC"
+CFLAGS="-g -Wall -D_REENTRANT -D_GNU_SOURCE -fPIC -I/usr/local/include -L/usr/local/lib"
 
-CHANNEL_H=/usr/include/asterisk/channel.h
+CHANNEL_H=/usr/local/include/asterisk/channel.h
 if [ "`grep 'struct ast_callerid cid' ${CHANNEL_H}`" != "" ]; then
     CFLAGS="${CFLAGS} -DCHANNEL_HAS_CID"
 fi
 
-CONFIG_H=/usr/include/asterisk/config.h
+CONFIG_H=/usr/local/include/asterisk/config.h
 if [ "`grep 'ast_config_load' ${CONFIG_H}`" != "" ]; then
     CFLAGS="${CFLAGS} -DNEW_CONFIG"
 fi
