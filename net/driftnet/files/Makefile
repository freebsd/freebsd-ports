# $corecode: ports/driftnet/files/Makefile,v 1.1 2002/03/01 02:32:10 corecode Exp $
# $FreeBSD$

VERSION?=	0.1.4

PROG=		driftnet
SRCS=		gif.c img.c jpeg.c png.c driftnet.c image.c display.c
CFLAGS+=	-I${LOCALBASE}/include -DDRIFTNET_VERSION='"${VERSION}"' ${GTK_CFLAGS}
LDFLAGS+=	${GTK_LDFLAGS} -lpcap -ljpeg -lungif

NOMAN=		yes

.if defined(PREFIX)
DESTDIR=	${PREFIX}/bin
.else
DESTDIR?=	/usr/X11R6/bin
.endif

GTK_CONFIG?=	gtk12-config
GTK_CFLAGS!=	${GTK_CONFIG} --cflags
GTK_LDFLAGS!=	${GTK_CONFIG} --libs

.include <bsd.prog.mk>
