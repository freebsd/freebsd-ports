#
# $FreeBSD$
#
# makefile for wmwave-0.4 on 27-12-2001 by bms
#
PROG=wmwave
SRCS=wmwave.c wmgeneral.c
MAN1=wmwave.1

CFLAGS += -g -I${X11BASE}/include -DWICACHE
LDFLAGS+= -L${X11BASE}/lib -lX11 -lXpm -lXext -lm

BINDIR=${PREFIX}/bin
MANDIR=${MANPREFIX}/man/man

# extra dependency to rebuild when master pixmap changed
wmwave.o: wmwave-master.xpm

.include <bsd.prog.mk>
