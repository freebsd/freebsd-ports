# Created by: Timothy Bourke <timbob@bigpond.com>
# $FreeBSD$

PORTNAME=	pspresent
PORTVERSION=	1.3
PORTREVISION=	6
CATEGORIES=	misc
MASTER_SITES=	http://www.zmatt.net/pspresent/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Full-screen slide shows of postscript files

LICENSE=	GPLv2

USE_XORG=	x11 xext xinerama
USES=		ghostscript:x11,run
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LDLIBS="${LDFLAGS}"
ALL_TARGET=	pspresent

PLIST_FILES=	bin/pspresent man/man1/pspresent.1.gz

CFLAGS+=	-I${LOCALBASE}/include -DHAVE_LIBXINERAMA
LDFLAGS+=	-L${LOCALBASE}/lib -lX11 -lXext -lXinerama

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pspresent ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pspresent.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
