# Created by: Vassili Tchersky <vt@bsdjeunz.org>
# $FreeBSD$

PORTNAME=	6tunnel
DISTVERSION=	0.12
CATEGORIES=	net
MASTER_SITES=	GH \
		LOCAL/bdrewery/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TCP proxy for applications that do not speak IPv6

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USES=		autoreconf
ALL_TARGET=	default

USE_GITHUB=	yes
GH_ACCOUNT=	wojtekka
GH_TAGNAME=	2d33461

PLIST_FILES=	bin/6tunnel \
		man/man1/6tunnel.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>
