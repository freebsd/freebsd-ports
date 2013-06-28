# Created by: Andreas Klemm <andreas@klemm.gtn.com>
# $FreeBSD$

PORTNAME=	knews
PORTVERSION=	1.0b.1
PORTREVISION=	12
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=dinoex

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Threaded nntp newsreader for X

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		compface:${PORTSDIR}/mail/faces
RUN_DEPENDS=	newsp:${PORTSDIR}/print/mp-letter

LICENSE=	GPLv2

USES=		imake
USE_XORG=	xmu xpm xt sm ice xext x11
MAKE_FLAGS=	BINDIR=${PREFIX}/bin MANDIR=${PREFIX}/man/man1 CC="${CC}" \
		XAPPLOADDIR=${PREFIX}/lib/X11/app-defaults  -f
.if defined(MAKE_JOBS)
MAKE_ARGS+=	-j${MAKE_JOBS}
.endif
MAN1=		knews.1

.include <bsd.port.mk>
