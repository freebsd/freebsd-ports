PORTNAME=	centreon-clib
DISTVERSION=	21.10.1
CATEGORIES=	net-mgmt

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Common library of all Centreon projects written in C or C++
WWW=		https://www.centreon.com/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	centreon
GH_PROJECT=	centreon-collect

WRKSRC_SUBDIR=	${PORTNAME}

CMAKE_ARGS=	-DWITH_PREFIX=${PREFIX} \
		-DWITH_PREFIX_INC=${PREFIX}/include/centreon \
		-DWITH_PKGCONFIG_DIR=${PREFIX}/libdata/pkgconfig
CXXFLAGS+=	-std=c++11

.include <bsd.port.mk>
