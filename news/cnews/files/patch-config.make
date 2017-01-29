--- include/config.make.orig	1970-01-01 01:00:00 UTC
+++ include/config.make
@@ -0,0 +1,58 @@
+# make header file
+# pathname variables
+# =()<NEWSARTS=@<NEWSARTS>@>()=
+NEWSARTS=/var/news
+# =()<NEWSOV=@<NEWSOV>@>()=
+NEWSOV=/var/news/over.view
+# =()<NEWSBIN=@<NEWSBIN>@>()=
+NEWSBIN=/usr/local/news/cnewsbin
+# =()<NEWSCTL=@<NEWSCTL>@>()=
+NEWSCTL=/usr/local/news/lib
+# =()<NEWSCONFIG=@<NEWSCONFIG>@>()=
+NEWSCONFIG=/usr/local/news/cnewsbin/config
+
+# workaround for System V make bug
+SHELL=/bin/sh
+
+# directories where things go
+UIBIN=/usr/local/bin
+RBIN=/usr/local/news/cnewsbin/input
+
+# compilation stuff
+# LIB is for makefile dependencies, LIBS for cc invocations
+LIB=../libcnews.a
+LIBS=../libcnews.a 
+CFLAGS+=$(MORECFLAGS) -I../include
+LDFLAGS=$(CFLAGS) 
+LINTFLAGS=$(MORELINTFLAGS) -I../include
+
+# directories etc.
+CONF=../conf
+MAKE=make
+TO=$(CONF)/cpto
+IN=$(CONF)/cmpto $(CMPOPT)
+CF=$(CONF)/checkfile $(CMPOPT)
+MKDIR=$(CONF)/mkdirs
+MX=chmod +x
+UPDATE=$(CONF)/update.ran ../libcnews.a
+LIBCMP=$(CONF)/libcmp ../libcnews.a
+
+# misc configuration bits
+SPACEFOR=statfs
+DOSPACEFOR=dospacefor
+QUEUELEN=tay
+UID=news
+GID=news
+SIZE=big
+DBZ=libdbz
+STDIO=sysstdio
+SERVER=
+REPORTTO=newsmaster
+URGENTTO=newscrisis
+
+# things for testing
+HERE=. ../conf/rsetup ;
+
+# fake files needed
+HFAKE= sys/timeb.h
+OFAKE= fgetline.o
