# $FreeBSD$

PORTNAME=	telepathy-qt4
PORTVERSION=	0.9.3
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME:C/4//}/
DISTNAME=	${PORTNAME:C/4//}-${PORTVERSION}

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	High-level Qt binding for Telepathy

LICENSE=	LGPL21

LIB_DEPENDS=	libtelepathy-farsight.so:${PORTSDIR}/net-im/telepathy-farsight \
		libtelepathy-glib.so:${PORTSDIR}/net-im/telepathy-glib

USE_GNOME=	libxslt:build
USE_GSTREAMER=	yes
USE_QT4=	corelib dbus gui network qtestlib_build xml \
		moc_build qmake_build rcc_build uic_build
USES=		cmake pkgconfig python:build
CMAKE_ARGS=	-DENABLE_FARSIGHT:BOOL=True \
		-DENABLE_TESTS:BOOL=False
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

PORTDOCS=	AUTHORS ChangeLog HACKING NEWS README html

PORTEXAMPLES=	accounts cm contact-messenger extensions \
		file-transfer protocols roster stream-tubes

OPTIONS_DEFINE=	DOCS EXAMPLES

EXAMPLES_CMAKE_ON=	-DENABLE_EXAMPLES:BOOL=True
EXAMPLES_CMAKE_OFF=	-DENABLE_EXAMPLES:BOOL=False

pre-configure:
	@${REINPLACE_CMD} -e '/FIND_PROGRAM/ s,qmake ,,' \
		${WRKSRC}/cmake/modules/FindQt.cmake
	@${REINPLACE_CMD} -e '/^add_dependencies(doxygen-doc / d' \
		${WRKSRC}/TelepathyQt/CMakeLists.txt
	@${REINPLACE_CMD} -e '/TelepathyQt.*\.pc/ s,pkgconfig,../libdata/pkgconfig,' \
		${WRKSRC}/TelepathyQt/CMakeLists.txt \
		${WRKSRC}/TelepathyQt/Farsight/CMakeLists.txt
	@${REINPLACE_CMD} -e '/$${LIBXML2_INCLUDE_DIR}/ s,$$, ${LOCALBASE}/include,' \
		${WRKSRC}/TelepathyQt/Farsight/CMakeLists.txt

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:Nhtml:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/examples && ${RM} -rf */CMakeFiles */*.cmake */_gen */Makefile
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} ${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
