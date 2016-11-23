# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	cadabra2
PORTVERSION=	2.0.930
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	yuri@rawbw.com
COMMENT=	Computer algebra system for solving field theory problems

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/doc/license.txt

PATCH_DEPENDS=	${NONEXISTENT}:devel/boost-libs:extract \
		${NONEXISTENT}:devel/websocketpp:extract
BUILD_DEPENDS=	${LOCALBASE}/include/websocketpp/client.hpp:devel/websocketpp
LIB_DEPENDS=	libboost_python.so:devel/boost-python-libs \
		libboost_system.so:devel/boost-libs \
		libpcrecpp.so:devel/pcre \
		libjsoncpp.so:devel/jsoncpp \
		libgmp.so:math/gmp \
		libuuid.so:misc/e2fsprogs-libuuid
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/sympy/__init__.py:math/py-sympy \
		${PYTHON_SITELIBDIR}/matplotlib/__init__.py:math/py-matplotlib

USE_GITHUB=	yes
GH_ACCOUNT=	kpeeters
GH_TAGNAME=	85ac041

BROKEN_FreeBSD_9=	does not build: fatal error: 'type_traits' file not found

OPTIONS_DEFINE=	GUI
OPTIONS_DEFAULT=GUI

USES=		compiler:c++14-lang cmake gettext-runtime gmake pkgconfig python:2 sqlite
GUI_USE=	GNOME=gtkmm30,gdkpixbuf2
USE_TEX=	base texmf texhash
USE_LDCONFIG=	yes
OPTIONS_SUB=	yes
GUI_INSTALLS_ICONS=	yes

CMAKE_ARGS+=	-DBOOST_ROOT=${LOCALBASE}
CMAKE_ARGS+=	-DUSE_PYTHON_3:BOOL=OFF
GUI_CMAKE_OFF+=	-DENABLE_FRONTEND:BOOL=OFF
GUI_CMAKE_ON+=	-DENABLE_FRONTEND:BOOL=ON
CXXFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-I${LOCALBASE}/include/jsoncpp
LDFLAGS+=	-L${LOCALBASE}/lib -ljsoncpp
CMAKE_CXX_FLAGS=${CXXFLAGS}
CMAKE_INSTALL_PREFIX=${PREFIX}

post-extract:
	@${RM} -r ${WRKSRC}/client_server/jsoncpp ${WRKSRC}/client_server/websocketpp

pre-patch:
	# workaround for https://github.com/zaphoyd/websocketpp/issues/563, so that the local patch can be applied
	@${MKDIR} ${WRKSRC}/override/include/boost/asio/detail/impl
	@${CP} `${MAKE} -C ${PORTSDIR}/devel/boost-libs -V WRKSRC`/boost/asio/detail/impl/socket_ops.ipp \
		${WRKSRC}/override/include/boost/asio/detail/impl/
	# workaround for https://github.com/zaphoyd/websocketpp/issues/587, so that the local patch can be applied
	@${MKDIR} ${WRKSRC}/override/include/websocketpp/transport/asio
	@${CP} `${MAKE} -C ${PORTSDIR}/devel/websocketpp -V WRKSRC`/websocketpp/transport/asio/endpoint.hpp \
		${WRKSRC}/override/include/websocketpp/transport/asio/

post-patch:
	@${REINPLACE_CMD} -e 's|"$${GIT_COMMIT_SERIAL}.$${GIT_SHORT_SHA}"|"FreeBSD port version=${PORTVERSION} tag=${GH_TAGNAME}"|' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|include_directories(|include_directories($${PROJECT_SOURCE_DIR}/override/include |' \
		${WRKSRC}/CMakeLists.txt

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cadabra2html
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cadabra-server
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/cadabra2.so

post-install-GUI-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cadabra-gtk
	@${GZIP_CMD} ${GZIP} < ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/cadabra2.svg \
	                     > ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/cadabra2.svgz
	@${RM} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/cadabra2.svg
	@${LN} ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps/cadabra2.png \
	       ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps/cadabra-gtk.png
	@${LN} ${STAGEDIR}${PREFIX}/share/icons/hicolor/64x64/apps/cadabra2.png \
	       ${STAGEDIR}${PREFIX}/share/icons/hicolor/64x64/apps/cadabra-gtk.png
	@${LN} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/cadabra2.svgz \
	       ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/cadabra-gtk.svgz

.include <bsd.port.mk>
