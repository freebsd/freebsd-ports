# $FreeBSD$

PORTNAME=	telepathy-qt4
PORTVERSION=	0.9.3
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME:C/4//}/
DISTNAME=	${PORTNAME:C/4//}-${PORTVERSION}

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	High-level Qt binding for Telepathy

LICENSE=	LGPL21

LIB_DEPENDS=	telepathy-farsight:${PORTSDIR}/net-im/telepathy-farsight \
		telepathy-glib:${PORTSDIR}/net-im/telepathy-glib

USE_GNOME=	libxslt:build
USE_GSTREAMER=	yes
USE_PYTHON_BUILD=	2.5+
USE_QT4=	dbus gui network qtestlib_build xml \
		moc_build qmake_build rcc_build uic_build
USES=		cmake pkgconfig
CMAKE_ARGS=	-DENABLE_FARSIGHT:BOOL=True \
		-DENABLE_TESTS:BOOL=False
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
		${WRKSRC}/TelepathyQt/CMakeLists.txt \
		${WRKSRC}/TelepathyQt/Farsight/CMakeLists.txt
	${REINPLACE_CMD} -e '/$${LIBXML2_INCLUDE_DIR}/ s|$$| ${LOCALBASE}/include|' \
		${WRKSRC}/TelepathyQt/Farsight/CMakeLists.txt

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${CP} -R doc/html .
. for f in ${PORTDOCS}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${f} ${DOCSDIR}
. endfor
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	cd ${WRKSRC}/examples && ${RM} -rf */CMakeFiles */*.cmake */Makefile
	${MKDIR} ${EXAMPLESDIR}
. for f in ${PORTEXAMPLES}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} ${f} ${EXAMPLESDIR}
. endfor
.endif

.include <bsd.port.mk>
