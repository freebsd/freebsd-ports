--- usr/sbin/pkcsconf/pkcsconf.mk.orig	2018-11-16 14:53:03 UTC
+++ usr/sbin/pkcsconf/pkcsconf.mk
@@ -1,7 +1,7 @@
 sbin_PROGRAMS += usr/sbin/pkcsconf/pkcsconf
 noinst_HEADERS += usr/sbin/pkcsconf/pkcsconf_msg.h
 
-usr_sbin_pkcsconf_pkcsconf_LDFLAGS = -lpthread -ldl -lcrypto
+usr_sbin_pkcsconf_pkcsconf_LDFLAGS = -lpthread -lcrypto
 
 usr_sbin_pkcsconf_pkcsconf_CFLAGS =					\
 	-D_THREAD_SAFE -DDEBUG -DDEV -DAPI				\
