# Created by: Andreas Klemm <andreas@klemm.gtn.com>
# $FreeBSD$

PORTNAME=	knews
PORTVERSION=	1.0b.1
PORTREVISION=	13
CATEGORIES=	news
MASTER_SITES=	LOCAL/dinoex

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Threaded nntp newsreader for X

LIB_DEPENDS=	libpng.so:graphics/png \
		libcompface.so:mail/faces
RUN_DEPENDS=	newsp:print/mp-letter

LICENSE=	GPLv2

USES=		imake jpeg
USE_XORG=	xmu xpm xt sm ice xext x11
MAKE_FLAGS=	BINDIR=${PREFIX}/bin MANDIR=${PREFIX}/man/man1 CC="${CC}" \
		XAPPLOADDIR=${PREFIX}/lib/X11/app-defaults  -f

.if defined(MAKE_JOBS)
MAKE_ARGS+=	-j${MAKE_JOBS}
.endif

.include <bsd.port.mk>
