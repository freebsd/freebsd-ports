# Created by: lofi@FreeBSD.org
# $FreeBSD$

PORTNAME=	qtdemo
DISTVERSION=	${QT4_VERSION}
CATEGORIES=	misc
PKGNAMEPREFIX=	qt4-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 4 demonstration and example applications

USES=		pkgconfig
USE_GSTREAMER=	yes
USE_QT4=	qmake_build moc_build rcc_build uic_build corelib designer \
		gui network opengl sql svg qtestlib xml imageformats_run dbus \
		script webkit phonon help assistant_run phonon-gst_run scripttools \
		xmlpatterns multimedia
QT_DIST=	yes

HAS_CONFIGURE=	yes

ALL_TARGET=	first
CONFIGURE_ENV?=	QTDIR=${WRKSRC} PATH=${WRKSRC}/bin:$$PATH
MAKE_ENV?=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib:$$LD_LIBRARY_PATH \
		PATH=${WRKSRC}/bin:$$PATH

# qtlogo.png is installed by qt4-gui
DESKTOP_ENTRIES="Qt 4 Examples and Demos" "" \
		"${PREFIX}/share/pixmaps/qtlogo.png" \
		"${PREFIX}/${QT_BINDIR_REL}/qtdemo" \
		"Development;Qt;" true

DO_NOT_EXTRACT=	doc mkspecs qmake translations \
		src/activeqt src/openvg src/s60installs src/s60main src/tools \
		src/winmain src/3rdparty/clucene src/3rdparty/freetype \
		src/3rdparty/libjpeg src/3rdparty/libmng src/3rdparty/libpng \
		src/3rdparty/libtiff
.for dne in ${DO_NOT_EXTRACT}
EXTRACT_AFTER_ARGS+=	--exclude '${DISTNAME}/${dne}'
.endfor

BUILD_WRKSRC=	${WRKSRC}/demos
INSTALL_WRKSRC=	${BUILD_WRKSRC}

post-patch:
	${REINPLACE_CMD} -e '/app +=/s|"assistant"|"assistant${_QT_BINSUFX}"|' \
		${BUILD_WRKSRC}/${PORTNAME}/menumanager.cpp \
		${WRKSRC}/examples/help/remotecontrol/remotecontrol.cpp \
		${WRKSRC}/examples/help/simpletextviewer/assistant.cpp

pre-configure:
	${MKDIR} ${WRKSRC}/mkspecs/modules
	${LN} -sf ${QMAKE} ${WRKSRC}/bin/qmake
	${LN} -sf ${MOC} ${WRKSRC}/bin/moc
	${LN} -sf ${UIC} ${WRKSRC}/bin/uic
	${LN} -sf ${RCC} ${WRKSRC}/bin/rcc

post-build:
	cd ${WRKSRC}/examples && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKEFLAGS} ${MAKEFILE} \
		${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET}

post-install:
	cd ${WRKSRC}/examples && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKEFLAGS} ${MAKEFILE} \
		${MAKE_ARGS} ${INSTALL_TARGET}
	${FIND} -E ${STAGEDIR}${PREFIX}/share/examples/qt4/examples/declarative/cppextensions -regex ".*\.(moc|obj|pch|rcc)" -type d | ${XARGS} ${RM} -r

.include <bsd.port.mk>
