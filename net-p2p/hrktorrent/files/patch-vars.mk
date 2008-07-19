--- vars.mk.orig	2008-06-29 16:18:44.000000000 +0200
+++ vars.mk	2008-06-29 16:18:52.000000000 +0200
@@ -4,5 +4,5 @@
 OBJ		= main.o core.o settings.o utils.o ipfilter.o
 OUT		= hrktorrent
 CXXFLAGS	+= `pkg-config --cflags libtorrent`
-LIBS		= `pkg-config --libs libtorrent` -lpthread
+LIBS		= `pkg-config --libs libtorrent` -pthread

