--- ./source4/dynconfig/config.mk.orig	2009-06-19 04:36:48.000000000 +0000
+++ ./source4/dynconfig/config.mk	2009-07-12 02:39:36.000000000 +0000
@@ -6,7 +6,7 @@
 # These can be overridden by command line switches (see samba(8))
 # or in smb.conf (see smb.conf(5))
 CONFIG4FILE = $(sysconfdir)/smb.conf
-pkgconfigdir = $(libdir)/pkgconfig
+pkgconfigdir = $(prefix)/libdata/pkgconfig
 LMHOSTSFILE4 = $(sysconfdir)/lmhosts
 
 $(dynconfigsrcdir)/dynconfig.o: CFLAGS+=-DCONFIGFILE=\"$(CONFIG4FILE)\" -DBINDIR=\"$(bindir)\" \
