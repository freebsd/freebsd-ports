PORTNAME=	microsocks
PORTVERSION=	1.0.4
CATEGORIES=	net
MASTER_SITES=	https://ftp.barfooze.de/pub/sabotage/tarballs/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Multithreaded, small, efficient SOCKS5 server
WWW=		https://github.com/rofl0r/microsocks

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz

USE_RC_SUBR=	microsocks

PLIST_FILES=	bin/microsocks

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/microsocks ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
