# Created by: lofi@freebsd.org
# $FreeBSD$

PORTNAME=	qtdemo
DISTVERSION=	${QT4_VERSION}
CATEGORIES?=	misc
PKGNAMEPREFIX=	qt4-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt demonstration and example programs

USE_QT4=	qmake_build moc_build rcc_build uic_build corelib designer \
		gui network opengl sql svg qtestlib xml imageformats_run dbus \
		script webkit phonon help assistant_run phonon-gst scripttools \
		xmlpatterns multimedia
QT_NONSTANDARD=	yes
QT_DIST=	yes
MAKE_JOBS_SAFE=	yes

HAS_CONFIGURE=	yes

ALL_TARGET=	first
CONFIGURE_ENV?=	QTDIR=${WRKSRC} PATH=${WRKSRC}/bin:$$PATH
MAKE_ENV?=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib:$$LD_LIBRARY_PATH \
		PATH=${WRKSRC}/bin:$$PATH

# qtlogo.png is installed by qt4-gui
DESKTOP_ENTRIES="Qt Examples and Demos" "${COMMENT}" \
		"${LOCALBASE}/share/pixmaps/qtlogo.png" \
		"${PREFIX}/bin/qtdemo" "Development;Qt;" true

DO_NOT_EXTRACT=	doc mkspecs qmake translations \
		src/activeqt src/openvg src/s60installs src/s60main src/tools \
		src/winmain src/3rdparty/clucene src/3rdparty/freetype \
		src/3rdparty/libjpeg src/3rdparty/libmng src/3rdparty/libpng \
		src/3rdparty/libtiff
EXTRACT_AFTER_ARGS=	| ${TAR} -xf -
.for dne in ${DO_NOT_EXTRACT}
EXTRACT_AFTER_ARGS+=	--exclude '${DISTNAME}/${dne}'
.endfor

BUILD_WRKSRC=	${WRKSRC}/demos
INSTALL_WRKSRC=	${BUILD_WRKSRC}

EXTRA_PATCHES=	${.CURDIR}/../../devel/qt4/files/patch-configure

post-patch:
	${REINPLACE_CMD} -e '/app +=/s|"assistant"|"assistant-qt4"|' \
		${BUILD_WRKSRC}/${PORTNAME}/menumanager.cpp \
		${WRKSRC}/examples/help/remotecontrol/remotecontrol.cpp \
		${WRKSRC}/examples/help/simpletextviewer/assistant.cpp

pre-configure:
	${MKDIR} ${WRKSRC}/mkspecs/modules
	${LN} -sf ${LOCALBASE}/bin/qmake-qt4 ${WRKSRC}/bin/qmake
	${LN} -sf ${LOCALBASE}/bin/moc-qt4 ${WRKSRC}/bin/moc
	${LN} -sf ${LOCALBASE}/bin/uic-qt4 ${WRKSRC}/bin/uic
	${LN} -sf ${LOCALBASE}/bin/rcc ${WRKSRC}/bin/rcc

post-build:
	cd ${WRKSRC}/examples && ${SETENV} MAKEOBJDIR=. ${MAKE}

post-install:
	cd ${WRKSRC}/examples && ${SETENV} MAKEOBJDIR=. ${MAKE} install
	${FIND} -E ${PREFIX}/share/examples/qt4/examples/declarative/cppextensions -regex ".*\.(moc|obj|pch|rcc)" -type d | ${XARGS} ${RM} -r

.include <bsd.port.mk>
