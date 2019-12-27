# $FreeBSD$

.if exists(/usr/lib/libncursesw.so)
LDLIBS += -lncursesw
.else
LDLIBS += -lncurses
.endif
LDLIBS += -ldialog

all: pkg_cleanup

pkg_cleanup: pkg_cleanup.c
