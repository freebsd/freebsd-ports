# $FreeBSD$

PORTNAME=	microsocks
PORTVERSION=	1.0.1
CATEGORIES=	net
MASTER_SITES=	http://ftp.barfooze.de/pub/sabotage/tarballs/

MAINTAINER=	neel@neelc.org
COMMENT=	Multithreaded, small, efficient SOCKS5 server

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
