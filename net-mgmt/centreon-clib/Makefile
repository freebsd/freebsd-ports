# Created by: Muhammad Moinur Rahman <5u623l20@gmail.com>
# $FreeBSD$

PORTNAME=	centreon-clib
PORTVERSION=	1.4.2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://download.centreon.com/centreon-clib/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Common library of all Centreon projects written in C or C++

LICENSE=	AGPLv3

USES=		cmake
CMAKE_SOURCE_PATH=	${WRKSRC}/build
CMAKE_ARGS=	-DWITH_PREFIX=${PREFIX} \
		-DWITH_PREFIX_INC=${PREFIX}/include/centreon \
		-DWITH_PKGCONFIG_DIR=${PREFIX}/libdata/pkgconfig
USE_LDCONFIG=	yes

.include <bsd.port.mk>
