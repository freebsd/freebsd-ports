# Created by: lofi@FreeBSD.org
# $FreeBSD$

PORTNAME=	qtconfig
DISTVERSION=	${QT4_VERSION}
PORTREVISION=	1
CATEGORIES=	misc
PKGNAMEPREFIX=	qt4-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 4 graphical configuration utility

USES=		pkgconfig
USE_QT4=	qmake_build moc_build rcc_build uic_build \
		corelib dbus gui xml
QT_DIST=	yes

HAS_CONFIGURE=	yes

ALL_TARGET=	first
CONFIGURE_ENV?=	QTDIR=${WRKSRC} PATH=${WRKSRC}/bin:$$PATH
MAKE_ENV?=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib:$$LD_LIBRARY_PATH \
		PATH=${WRKSRC}/bin:$$PATH

DESKTOP_ENTRIES="Qt 4 Configuration" "" \
		"${PREFIX}/share/pixmaps/qtconfig-qt4.png" \
		"${PREFIX}/${QT_BINDIR_REL}/qtconfig${_QT_BINSUFX}" \
		"Settings;Qt;" true

DO_NOT_EXTRACT=	demos doc examples mkspecs qmake translations \
		src/activeqt src/dbus src/multimedia src/network src/opengl \
		src/openvg src/s60installs src/s60main src/script \
		src/scripttools src/sql src/svg src/testlib src/tools \
		src/winmain src/xml src/xmlpatterns src/3rdparty/clucene \
		src/3rdparty/freetype src/3rdparty/libjpeg src/3rdparty/libmng \
		src/3rdparty/libpng src/3rdparty/libtiff src/3rdparty/webkit
.for dne in ${DO_NOT_EXTRACT}
EXTRACT_AFTER_ARGS+=	--exclude '${DISTNAME}/${dne}'
.endfor

OPTIONS_DEFINE=	PHONON
OPTIONS_DEFAULT=PHONON

PHONON_DESC=	Phonon multimedia framework support (implies GStreamer)
PHONON_USE=	GSTREAMER=yes QT4=phonon,phonon-gst
PHONON_CONFIGURE_ON=	-phonon -gstreamer
PHONON_CONFIGURE_OFF=	-no-phonon -no-gstreamer

BUILD_WRKSRC=	${WRKSRC}/tools/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

pre-configure:
	${REINPLACE_CMD} -e 's|^TARGET.*|TARGET=qtconfig${_QT_BINSUFX}|g' \
		${BUILD_WRKSRC}/${PORTNAME}.pro
	${ECHO_CMD} "INCLUDEPATH+=${EXTRA_INCL}" >> ${BUILD_WRKSRC}/${PORTNAME}.pro
	${MKDIR} ${WRKSRC}/mkspecs
	${LN} -sf ${QMAKE} ${WRKSRC}/bin/qmake
	${LN} -sf ${MOC} ${WRKSRC}/bin/moc
	${LN} -sf ${UIC} ${WRKSRC}/bin/uic
	${LN} -sf ${RCC} ${WRKSRC}/bin/rcc

post-install:
	${INSTALL_DATA} ${INSTALL_WRKSRC}/images/appicon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/qtconfig-qt4.png

.include <bsd.port.mk>
