# Created by: Muhammad Moinur Rahman <5u623l20@gmail.com>
# $FreeBSD$

PORTNAME=	centreon-clib
PORTVERSION=	20.04.0
CATEGORIES=	net-mgmt

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Common library of all Centreon projects written in C or C++

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	centreon

CMAKE_ARGS=	-DWITH_PREFIX=${PREFIX} \
		-DWITH_PREFIX_INC=${PREFIX}/include/centreon \
		-DWITH_PKGCONFIG_DIR=${PREFIX}/libdata/pkgconfig
CXXFLAGS+=	-std=c++11
USE_LDCONFIG=	yes

.include <bsd.port.mk>
