# Created by: lofi@freebsd.org
# $FreeBSD$

PORTNAME=	qtconfig
DISTVERSION=	${QT4_VERSION}
CATEGORIES?=	misc
PKGNAMEPREFIX=	qt4-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt graphical configuration utility

OPTIONS_DEFINE=	PHONON
OPTIONS_DEFAULT=PHONON

PHONON_DESC=	Multimedia via Phonon (implies GStreamer)

USE_QT4=	qmake_build moc_build rcc_build uic_build \
		dbus gui xml
QT_NONSTANDARD=	yes
QT_DIST=	yes

HAS_CONFIGURE=	yes

ALL_TARGET=	first
CONFIGURE_ENV?=	QTDIR=${WRKSRC} PATH=${WRKSRC}/bin:$$PATH
MAKE_ENV?=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib:$$LD_LIBRARY_PATH \
		PATH=${WRKSRC}/bin:$$PATH

DESKTOP_ENTRIES="Qt Configuration" "${COMMENT}" \
		"${PREFIX}/share/pixmaps/qtconfig-qt4.png" \
		"${PREFIX}/bin/qtconfig-qt4" "Settings;Qt;" true

DO_NOT_EXTRACT=	demos doc examples mkspecs qmake translations \
		src/activeqt src/dbus src/multimedia src/network src/opengl \
		src/openvg src/s60installs src/s60main src/script \
		src/scripttools src/sql src/svg src/testlib src/tools \
		src/winmain src/xml src/xmlpatterns src/3rdparty/clucene \
		src/3rdparty/freetype src/3rdparty/libjpeg src/3rdparty/libmng \
		src/3rdparty/libpng src/3rdparty/libtiff src/3rdparty/webkit
EXTRACT_AFTER_ARGS=	| ${TAR} -xf -
.for dne in ${DO_NOT_EXTRACT}
EXTRACT_AFTER_ARGS+=	--exclude '${DISTNAME}/${dne}'
.endfor

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPHONON}
USE_QT4+=	phonon phonon-gst
USE_GSTREAMER=	yes
.else
CONFIGURE_ARGS+=-no-phonon -no-gstreamer
.endif

BUILD_WRKSRC=	${WRKSRC}/tools/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

EXTRA_PATCHES=	${.CURDIR}/../../devel/qt4/files/patch-configure

pre-configure:
	${REINPLACE_CMD} -e 's|^TARGET.*|TARGET=qtconfig-qt4|g' \
		${BUILD_WRKSRC}/${PORTNAME}.pro
	${ECHO_CMD} "INCLUDEPATH+=${EXTRA_INCL}" >> ${BUILD_WRKSRC}/${PORTNAME}.pro
	${MKDIR} ${WRKSRC}/mkspecs
	${LN} -sf ${LOCALBASE}/bin/qmake-qt4 ${WRKSRC}/bin/qmake
	${LN} -sf ${LOCALBASE}/bin/moc-qt4 ${WRKSRC}/bin/moc
	${LN} -sf ${LOCALBASE}/bin/uic-qt4 ${WRKSRC}/bin/uic
	${LN} -sf ${LOCALBASE}/bin/rcc ${WRKSRC}/bin/rcc

post-install:
	${INSTALL_DATA} ${BUILD_WRKSRC}/images/appicon.png \
		${PREFIX}/share/pixmaps/qtconfig-qt4.png

.include <bsd.port.mk>
