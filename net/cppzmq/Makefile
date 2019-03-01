# Created by: Vasil Dimov <vd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cppzmq
PORTVERSION=	4.3.0
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	vd@FreeBSD.org
COMMENT=	C++ bindings for 0MQ

LICENSE=	MIT

LIB_DEPENDS=	libzmq.so:net/libzmq4

NO_ARCH=	yes

USES=		cmake pkgconfig
CMAKE_ARGS=	--no-warn-unused-cli \
		-DCPPZMQ_BUILD_TESTS:BOOL=OFF \
		-DCPPZMQ_CMAKECONFIG_INSTALL_DIR:PATH="lib/cmake/${PORTNAME}" \
		-Wno-dev

# cppzmq is included in libzmq2
CONFLICTS_INSTALL=	libzmq2

USE_GITHUB=	yes
GH_ACCOUNT=	zeromq

PLIST_FILES=	\
	include/zmq.hpp \
	include/zmq_addon.hpp \
	lib/cmake/${PORTNAME}/cppzmqConfig.cmake \
	lib/cmake/${PORTNAME}/cppzmqConfigVersion.cmake \
	lib/cmake/${PORTNAME}/cppzmqTargets.cmake \
	lib/cmake/${PORTNAME}/libzmq-pkg-config/FindZeroMQ.cmake

post-patch:
	${SED} -i '.orig' \
		-e 's|ZeroMQ_LIBRARY AND ZeroMQ_STATIC_LIBRARY|ZeroMQ_LIBRARY|' \
		${WRKSRC}/libzmq-pkg-config/FindZeroMQ.cmake

.include <bsd.port.mk>
