# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	cadabra2
PORTVERSION=	2.1.5
PORTREVISION=	2
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

OPTIONS_DEFINE=	GUI
OPTIONS_DEFAULT=GUI

USES=		compiler:c++14-lang cmake gettext-runtime pkgconfig python:2 sqlite
USE_GITHUB=	yes
GH_ACCOUNT=	kpeeters
GUI_USE=	GNOME=gtkmm30,gdkpixbuf2
USE_TEX=	base texmf texhash
USE_LDCONFIG=	yes
OPTIONS_SUB=	yes
GUI_INSTALLS_ICONS=	yes
GUI_USES=	desktop-file-utils

CMAKE_ARGS+=	-DBOOST_ROOT=${LOCALBASE}
CMAKE_ARGS+=	-DUSE_PYTHON_3:BOOL=OFF
GUI_CMAKE_BOOL=	FRONTEND
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
	@${REINPLACE_CMD} -e 's|execute|#execute|' \
			-e 's|"$${GIT_COMMIT_SERIAL}.$${GIT_SHORT_SHA}"|"FreeBSD port version=${PORTVERSION} tag=${GH_TAGNAME}"|' \
			-e 's|set(CADABRA_VERSION_DATE "$${THE_DATE}"|set(CADABRA_VERSION_DATE "'`date "+%Y-%m-%d"`'"|' \
			-e 's|include_directories(|include_directories($${PROJECT_SOURCE_DIR}/override/include |' \
				${WRKSRC}/CMakeLists.txt

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cadabra2html
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cadabra-server
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/cadabra2.so

post-install-GUI-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cadabra2-gtk
	@${GZIP_CMD}	< ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/cadabra2-gtk.svg \
			> ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/cadabra2-gtk.svgz
	@${RM} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/cadabra2-gtk.svg
	@${LN} ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps/cadabra2-gtk.png \
	       ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps/cadabra-gtk.png
	@${LN} ${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps/cadabra2-gtk.png \
	       ${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps/cadabra-gtk.png
	@${LN} ${STAGEDIR}${PREFIX}/share/icons/hicolor/64x64/apps/cadabra2-gtk.png \
	       ${STAGEDIR}${PREFIX}/share/icons/hicolor/64x64/apps/cadabra-gtk.png
	@${LN} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/cadabra2-gtk.svgz \
	       ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/cadabra-gtk.svgz

.include <bsd.port.mk>
