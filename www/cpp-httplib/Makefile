# $FreeBSD$

PORTNAME=	cpp-httplib
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.9
CATEGORIES=	www devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ header-only HTTP/HTTPS server and client library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	yhirose

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	include/httplib/httplib.h \
		share/httplib/cmake/httplibConfig.cmake

.include <bsd.port.mk>
