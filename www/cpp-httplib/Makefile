# $FreeBSD$

PORTNAME=	cpp-httplib
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.6
CATEGORIES=	www devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ header-only HTTP/HTTPS server and client library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	yhirose

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	include/httplib/httplib.h

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/httplib
	${INSTALL_DATA} ${WRKSRC}/httplib.h ${STAGEDIR}${PREFIX}/include/httplib

.include <bsd.port.mk>
