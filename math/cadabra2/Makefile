# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	cadabra2
PORTVERSION=	2.0.816
CATEGORIES=	math

MAINTAINER=	yuri@rawbw.com
COMMENT=	Computer algebra system for solving field theory problems

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/doc/license.txt

LIB_DEPENDS=	libboost_python.so:devel/boost-python-libs \
		libpcrecpp.so:devel/pcre \
		libboost_system.so:devel/boost-libs \
		libjsoncpp.so:devel/jsoncpp \
		libgmp.so:math/gmp \
		libuuid.so:misc/e2fsprogs-libuuid
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/sympy/__init__.py:math/py-sympy \
		${PYTHON_SITELIBDIR}/matplotlib/__init__.py:math/py-matplotlib

USE_GITHUB=	yes
GH_ACCOUNT=	kpeeters
GH_TAGNAME=	8258bfc

BROKEN_FreeBSD_9=	does not build: fatal error: 'type_traits' file not found
GUI_BROKEN=	Builds but has a WebSockets communication problem in the runtime
GUI_CONFLICTS_BUILD=	websocketpp-*

OPTIONS_DEFINE=	GUI

USES=		compiler:c++11-lang cmake gettext gmake pkgconfig python:2 sqlite
GUI_USE=	GNOME=gtkmm30,gdkpixbuf2
USE_TEX=	base
USE_LDCONFIG=	yes
OPTIONS_SUB=	yes
GUI_INSTALLS_ICONS=	yes

BUILD_DEPENDS+=	clang36:lang/clang36
RUN_DEPENDS+=	clang36:lang/clang36
CC=		clang36
CXX=		clang++36

CMAKE_ARGS+=	-DBOOST_ROOT=${LOCALBASE}
CMAKE_ARGS+=	-DUSE_PYTHON_3:BOOL=OFF
GUI_CMAKE_ON+=	-DENABLE_FRONTEND:BOOL=ON
CXXFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-I${LOCALBASE}/include/jsoncpp
LDFLAGS+=	-L${LOCALBASE}/lib -ljsoncpp
CMAKE_CXX_FLAGS=${CXXFLAGS}
CMAKE_INSTALL_PREFIX=${PREFIX}

post-extract:
	${RM} -r ${WRKSRC}/client_server/jsoncpp

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cadabra2html
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cadabra-server
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/cadabra2.so

post-install-GUI-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cadabra-gtk

.include <bsd.port.mk>
