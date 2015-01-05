# Created by: Alberto Villa <avilla@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/net-im/telepathy-qt4/Makefile 19955 2014-10-15 10:15:00Z gusi $

PORTNAME=	telepathy-qt4
PORTVERSION=	0.9.4
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME:C/4//}/
DISTNAME=	${PORTNAME:C/4//}-${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	High-level Qt binding for Telepathy

LICENSE=	LGPL21

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/_dbus_bindings.so:${PORTSDIR}/devel/py-dbus
LIB_DEPENDS=	libtelepathy-farstream.so:${PORTSDIR}/net-im/telepathy-farstream \
		libtelepathy-glib.so:${PORTSDIR}/net-im/telepathy-glib
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_dbus_bindings.so:${PORTSDIR}/devel/py-dbus

USE_GNOME=	libxslt:build
USE_GSTREAMER=	yes
USE_QT4=	corelib dbus gui network qtestlib_build xml \
		moc_build qmake_build rcc_build uic_build
USES=		cmake pkgconfig python:build
CMAKE_ARGS=	-DENABLE_FARSIGHT:BOOL=False \
		-DENABLE_FARSTREAM:BOOL=True \
		-DENABLE_TESTS:BOOL=False
CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

PORTDOCS=	AUTHORS ChangeLog HACKING NEWS README html

PORTEXAMPLES=	Makefile accounts cm contact-messenger extensions \
		file-transfer protocols roster stream-tubes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
CMAKE_ARGS+=	-DENABLE_EXAMPLES:BOOL=True
.else
CMAKE_ARGS+=	-DENABLE_EXAMPLES:BOOL=False
.endif

pre-configure:
	${REINPLACE_CMD} -e '/FIND_PROGRAM/ s/qmake //' \
		${WRKSRC}/cmake/modules/FindQt.cmake
	${REINPLACE_CMD} -e '/^add_dependencies(doxygen-doc / d' \
		${WRKSRC}/TelepathyQt/CMakeLists.txt
	${REINPLACE_CMD} -e '/TelepathyQt.*\.pc/ s|pkgconfig|../libdata/pkgconfig|' \
		${WRKSRC}/TelepathyQt/CMakeLists.txt
	${REINPLACE_CMD} -e 's|LIB_INSTALL_DIR}/pkgconfig|LIB_INSTALL_DIR}/../libdata/pkgconfig|' \
		${WRKSRC}/TelepathyQt/Farstream/CMakeLists.txt

post-patch:
	@${REINPLACE_CMD} -e 's|farstream-0.1|farstream-0.2|g' \
		${WRKSRC}/cmake/modules/FindFarstream.cmake

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${CP} -R doc/html .
. for f in ${PORTDOCS}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${f} ${STAGEDIR}${DOCSDIR}
. endfor
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	cd ${WRKSRC}/examples && ${RM} -rf */CMakeFiles */*.cmake */Makefile
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
. for f in ${PORTEXAMPLES}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} ${f} ${STAGEDIR}${EXAMPLESDIR}
. endfor
.endif

.include <bsd.port.mk>
