# $FreeBSD$
# Makefile to build trayicon.so

CFLAGS = `pkg-config --cflags gtk+-2.0 pygtk-2.0` -I${PREFIX}/include/python2.4/ -I. -Wall -I${PREFIX}/share/pygtk/2.0 -I${PREFIX}/libdata/pkgconfig -DEGG_COMPILATION
LDFLAGS = `pkg-config --libs gtk+-2.0 pygtk-2.0`

DEFS_DIR= ${PREFIX}/share/pygtk/2.0/defs/

CODEGEN = pygtk-codegen-2.0

all: trayicon.so

trayicon.so: trayicon.o eggtrayicon.o trayiconmodule.o
	$(CC) $(LDFLAGS) -shared $^ -o $@

trayicon.c: trayicon.defs eggtrayicon.h trayicon.override
	$(CODEGEN) --prefix pytrayicon \
	--register $(DEFS_DIR)/gdk-types.defs \
	--register $(DEFS_DIR)/gtk-types.defs \
	--override trayicon.override \
	trayicon.defs > $@

clean:
	rm -f *.o *.so trayicon.c *~
