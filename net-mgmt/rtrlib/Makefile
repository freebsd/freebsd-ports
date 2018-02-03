# $FreeBSD$

PORTNAME=	rtrlib
PORTVERSION=	0.5.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net-mgmt sysutils

MAINTAINER=	freebsd@bodems.net
COMMENT=	Open-source C implementation of the RPKI/Router Protocol client

LICENSE=	MIT

LIB_DEPENDS=	libssh.so:security/libssh
BUILD_DEPENDS=	cmake:devel/cmake

USES=		cmake
USE_LDCONFIG=	yes
CMAKE_ARGS=	-DCMAKE_BUILD_TYPE=Release

USE_GITHUB=	yes
GH_ACCOUNT=	rtrlib

.include <bsd.port.mk>
