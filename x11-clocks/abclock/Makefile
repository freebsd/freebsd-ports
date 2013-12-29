# Created by: Chris D. Faulhaber <jedgar@FreeBSD.org>
# $FreeBSD$

PORTNAME=	abclock
PORTVERSION=	1.0d
PORTREVISION=	2
CATEGORIES=	x11-clocks
MASTER_SITES=	http://odur.let.rug.nl/~kleiweg/abclock/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Clock for X that displays hours and minutes in an analog fashion

PLIST_FILES=	bin/abclock bin/abc_img

MAKE_ARGS=	CC="${CC}" OPT="${CFLAGS}"

USE_XORG=	x11 xau xdmcp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abclock ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/abc_img ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
