PORTNAME=	microsocks
PORTVERSION=	1.0.3
CATEGORIES=	net
MASTER_SITES=	https://ftp.barfooze.de/pub/sabotage/tarballs/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Multithreaded, small, efficient SOCKS5 server

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz

USE_RC_SUBR=	microsocks

PLIST_FILES=	bin/microsocks

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/microsocks ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
