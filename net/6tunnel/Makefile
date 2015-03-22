# Created by: Vassili Tchersky <vt@bsdjeunz.org>
# $FreeBSD$

PORTNAME=	6tunnel
DISTVERSION=	0.11rc2.20130525
CATEGORIES=	net ipv6
MASTER_SITES=	GHL \
		LOCAL/bdrewery/${PORTNAME}/

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	TCP proxy for applications that do not speak IPv6

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf
ALL_TARGET=	default

USE_GITHUB=	yes
GH_ACCOUNT=	wojtekka
GH_PROJECT=	${PORTNAME}
GH_COMMIT=	2d33461
GH_TAGNAME=	${GH_COMMIT}

PLIST_FILES=	bin/6tunnel \
		man/man1/6tunnel.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>
