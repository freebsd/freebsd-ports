--- ./source4/smbd/config.mk.orig	2009-06-19 04:36:48.000000000 +0000
+++ ./source4/smbd/config.mk	2009-07-12 02:39:36.000000000 +0000
@@ -18,7 +18,7 @@
 
 $(eval $(call proto_header_template,$(smbdsrcdir)/pidfile.h,$(PIDFILE_OBJ_FILES:.o=.c)))
 
-[BINARY::samba]
+[BINARY::samba4]
 INSTALLDIR = SBINDIR
 PRIVATE_DEPENDENCIES = \
 		LIBEVENTS \
@@ -36,7 +36,7 @@
 		share \
 		CLUSTER
 
-samba_OBJ_FILES = $(smbdsrcdir)/server.o
-$(samba_OBJ_FILES): CFLAGS+=-DSTATIC_service_MODULES="$(service_INIT_FUNCTIONS)NULL"
+samba4_OBJ_FILES = $(smbdsrcdir)/server.o
+$(samba4_OBJ_FILES): CFLAGS+=-DSTATIC_service_MODULES="$(service_INIT_FUNCTIONS)NULL"
 
-MANPAGES += $(smbdsrcdir)/samba.8
+MANPAGES += $(smbdsrcdir)/samba4.8
