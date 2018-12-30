# $FreeBSD$

PORTNAME=	cpr
DISTVERSION=	1.3.0-57
DISTVERSIONSUFFIX=	-g3d14e61
CATEGORIES=	www

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	8eb16e267843d18834bf42d9ae4ccfb58f34bdb5.patch:-p1

MAINTAINER=	che@bein.link
COMMENT=	Curl for people, a simple wrapper around libcurl

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		compiler:c++11-lang cmake
USE_GITHUB=	yes
GH_ACCOUNT=	whoshuu
GH_TUPLE=	whoshuu:mongoose:df9f7a7:mongoose/opt/mongoose
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_CPR_TESTS
CMAKE_ON=	BUILD_SHARED_LIBS USE_SYSTEM_CURL

INSTALL_TARGET=	install

.include <bsd.port.mk>
