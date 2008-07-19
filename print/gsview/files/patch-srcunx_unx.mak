--- srcunx/unx.mak.orig	2008-07-13 07:39:58.254461217 -0400
+++ srcunx/unx.mak	2008-07-14 09:22:24.652938045 -0400
@@ -19,8 +19,8 @@
 #
 # WARNING: Doesn't install pstotext
 
-prefix=
-GSVIEW_ROOT=/usr/local
+prefix=${PREFIX}
+GSVIEW_ROOT=
 GSVIEW_BASE=$(prefix)$(GSVIEW_ROOT)
 
 
@@ -38,8 +38,6 @@
 # GSview printer.ini and system wide gsview.ini
 GSVIEW_ETCPATH=$(prefix)/etc
 
-MAKE=make
-CC=gcc
 OBJ=o
 INSTALL=install -m 644
 INSTALL_EXE=install -m 755
@@ -50,8 +48,8 @@
 
 # Linux
 XINCLUDE=
-PFLAGS=-DMULTITHREAD
-PLINK=-lpthread -lrt
+PFLAGS=-DMULTITHREAD ${PTHREAD_CFLAGS}
+PLINK=${PTHREAD_LIBS}
 
 # SunOS 5.7
 #XINCLUDE=-I/usr/openwin/share/lib
@@ -77,7 +75,8 @@
 
 # Other possible options are -Wtraditional
 # Compiler flags for C and C++ files.
-CFLAGS=-O -Wall -Wstrict-prototypes -Wmissing-declarations -Wmissing-prototypes -fno-builtin -fno-common -Wcast-qual -Wwrite-strings $(CDEBUG) -DX11 -DUNIX -DNONAG $(RPM_OPT_FLAGS) `gtk-config --cflags` $(XINCLUDE) $(PFLAGS)
+#CFLAGS=-O -Wall -Wstrict-prototypes -Wmissing-declarations -Wmissing-prototypes -fno-builtin -fno-common -Wcast-qual -Wwrite-strings $(CDEBUG) -DX11 -DUNIX -DNONAG $(RPM_OPT_FLAGS) `gtk-config --cflags` $(XINCLUDE) $(PFLAGS)
+CFLAGS+=-Wall -Wstrict-prototypes -Wmissing-declarations -Wmissing-prototypes -fno-builtin -fno-common -Wcast-qual -Wwrite-strings $(CDEBUG) -DX11 -DUNIX -DNONAG `gtk-config --cflags` $(XINCLUDE) $(PFLAGS)
 
 # Linker flags
 LFLAGS=$(LDEBUG) $(PLINK) `gtk-config --libs`
@@ -152,7 +151,7 @@
 #all: gsview html pstotext
 all: $(BD)gsview$(EXE) html
 
-GSVIEW_DOCDIR=$(GSVIEW_DOCPATH)/gsview-$(GSVIEW_DOT_VERSION)
+GSVIEW_DOCDIR=$(GSVIEW_DOCPATH)/gsview
 
 $(BD)gsview$(EXE): $(OBJS)
 	$(COMP) $(CFLAGS) $(FO)$(BD)gsview$(EXE) $(OBJS) $(LFLAGS)
