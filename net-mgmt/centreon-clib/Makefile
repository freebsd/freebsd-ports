PORTNAME=	centreon-clib
DISTVERSION=	${COLLECT_MAJOR}.${COLLECT_MINOR}.${COLLECT_PATCH}
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

WRKSRC_SUBDIR=	clib

COLLECT_MAJOR=22
COLLECT_MINOR=04
COLLECT_PATCH=0

CMAKE_ARGS=	-DCMAKE_INSTALL_PREFIX=${PREFIX} \
		-DWITH_PREFIX_INC=${PREFIX}/include/centreon \
		-DWITH_PKGCONFIG_DIR=${PREFIX}/libdata/pkgconfig
CXXFLAGS+=	-std=c++11

post-patch:
	@${REINPLACE_CMD} -e 's|$${COLLECT_MAJOR}|${COLLECT_MAJOR}|g; s|$${COLLECT_MINOR}|${COLLECT_MINOR}|g; s|$${COLLECT_PATCH}|${COLLECT_PATCH}|g' \
		${WRKSRC}/CMakeLists.txt \
		${WRKSRC}/cmake/package.cmake
	@${REINPLACE_CMD} -e 's|@COLLECT_MAJOR@|${COLLECT_MAJOR}|g; s|@COLLECT_MINOR@|${COLLECT_MINOR}|g; s|@COLLECT_PATCH@|${COLLECT_PATCH}|g' \
		${WRKSRC}/inc/com/centreon/clib/version.hh.in

.include <bsd.port.mk>
