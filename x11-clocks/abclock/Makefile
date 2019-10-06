# Created by: Chris D. Faulhaber <jedgar@FreeBSD.org>
# $FreeBSD$

PORTNAME=	abclock
PORTVERSION=	1.0d
PORTREVISION=	4
CATEGORIES=	x11-clocks
MASTER_SITES=	https://www.let.rug.nl/~kleiweg/abclock/

MAINTAINER=	m.ne@gmx.net
COMMENT=	Clock for X that displays hours and minutes in an analog fashion

LICENSE=	GPLv2+

PLIST_FILES=	bin/abc_img \
		bin/abclock

MAKE_ARGS=	CC="${CC}" \
		OPT="${CFLAGS}"

USES=		xorg
USE_XORG=	x11 xau xdmcp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abclock ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/abc_img ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
