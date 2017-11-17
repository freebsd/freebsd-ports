# Created by: Vasil Dimov <vd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cppzmq
PORTVERSION=	4.2.2
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	vd@FreeBSD.org
COMMENT=	C++ bindings for 0MQ

LICENSE=	MIT

LIB_DEPENDS=	libzmq.so:net/libzmq4

USES=		cmake pkgconfig
CMAKE_ARGS=	--no-warn-unused-cli -Wno-dev

# cppzmq is included in libzmq2
CONFLICTS_INSTALL=	libzmq2

USE_GITHUB=	yes
GH_ACCOUNT=	zeromq

PLIST_FILES=	\
	include/zmq.hpp \
	include/zmq_addon.hpp \
	share/cmake/Modules/cppzmqConfig.cmake \
	share/cmake/Modules/cppzmqConfigVersion.cmake \
	share/cmake/Modules/cppzmqTargets.cmake \
	share/cmake/Modules/libzmqPkgConfigFallback.cmake

post-patch:
	${SED} -i '.orig' \
		-e 's|find_package(ZeroMQ)|find_package(ZeroMQ QUIET)|' \
		-e 's|share/cmake/$${PROJECT_NAME}|share/cmake/Modules|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
