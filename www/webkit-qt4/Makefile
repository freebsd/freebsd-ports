# Created by: danny@ricin.com
# $FreeBSD$

PORTNAME=	webkit
DISTVERSION=	${QT4_VERSION}
CATEGORIES=	www
PKGNAMEPREFIX=	qt4-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt WebKit implementation

USE_QT4=	corelib declarative gui network \
		qmake_build moc_build rcc_build
QT_DIST=	yes
USE_XORG=	xrender
USES=		pkgconfig

HAS_CONFIGURE=	yes
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

ALL_TARGET=	first
CONFIGURE_ENV?=	QTDIR=${WRKSRC} PATH=${WRKSRC}/bin:$$PATH
MAKE_ENV?=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib:$$LD_LIBRARY_PATH \
		PATH=${WRKSRC}/bin:$$PATH MAKEOBJDIR=.

DO_NOT_EXTRACT=	demos doc examples mkspecs qmake tools translations \
		src/activeqt src/dbus src/opengl src/openvg src/qt3support \
		src/s60installs src/s60main src/scripttools src/sql src/svg \
		src/testlib src/tools src/winmain src/3rdparty/clucene \
		src/3rdparty/freetype src/3rdparty/libjpeg src/3rdparty/libmng \
		src/3rdparty/libpng src/3rdparty/libtiff
.for dne in ${DO_NOT_EXTRACT}
EXTRACT_AFTER_ARGS+=	--exclude '${DISTNAME}/${dne}'
.endfor

BUILD_WRKSRC=	${WRKSRC}/src/3rdparty/${PORTNAME}/Source
INSTALL_WRKSRC=	${BUILD_WRKSRC}

CONFIGURE_ARGS+=	-I../../../../include/Qt -I../../../../include

OPTIONS_DEFINE=	GSTREAMER
OPTIONS_DEFAULT=GSTREAMER

GSTREAMER_USE=	GSTREAMER=yes

.include <bsd.port.pre.mk>

# Base ld(1) segfaults on PowerPC:
# http://bugs.freebsd.org/173042
.if ${ARCH} == "powerpc"
BUILD_DEPENDS+= ${LOCALBASE}/bin/ld:devel/binutils
.endif

.if ${ARCH} == powerpc64
CFLAGS+=	-mminimal-toc
.endif

# Quick hack to avoid messing up qt_webkit_version.pri installation
# directory. bsd.port.pre.mk is required to add the setting at the end.
CONFIGURE_ENV+=	QMAKEPATH=""
MAKE_ENV+=	QMAKEPATH=""

pre-configure:
	${MKDIR} ${WRKSRC}/mkspecs
	${LN} -sf ${QMAKE} ${WRKSRC}/bin/qmake
	${LN} -sf ${MOC} ${WRKSRC}/bin/moc
	${LN} -sf ${RCC} ${WRKSRC}/bin/rcc
	${REINPLACE_CMD} -e 's|linux-\*|unix|g' \
		${BUILD_WRKSRC}/WebCore/features.pri \
		${BUILD_WRKSRC}/JavaScriptCore/wtf/wtf.pri
.if ! ${PORT_OPTIONS:MGSTREAMER}
	${REINPLACE_CMD} -e 's|.*exists.*gstreamer.*|false {|' \
		${BUILD_WRKSRC}/WebCore/features.pri
.endif
# Avoid building and installing several tests. Should this be made an option?
	${REINPLACE_CMD} -e '/WebKit\/qt\/tests/ d' \
		${BUILD_WRKSRC}/WebKit.pro

post-configure:
	${REINPLACE_CMD} \
		-e 's|${PREFIX}/${QT_LIBDIR_REL}/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		-e 's|.*$$(QMAKE).*||g' \
		-e '/^CFLAGS/ s|-I${LOCALBASE}/include ||g' \
		-e '/^CXXFLAGS/ s|-I${LOCALBASE}/include ||g' \
		${BUILD_WRKSRC}/Makefile \
		${BUILD_WRKSRC}/WebCore/Makefile \
		${BUILD_WRKSRC}/WebKit/qt/Makefile
	${CP} ${BUILD_WRKSRC}/WebKit/qt/Makefile \
		${BUILD_WRKSRC}/WebKit/qt/Makefile.QtWebKit
	${REINPLACE_CMD} -E -e 's|-L.[^[:space:]]*qt-x11-opensource.[^[:space:]]*lib||g' \
			-E -e 's|(.*location=).*moc|\1${PREFIX}/${QT_BINDIR_REL}/${MOC:T}|g' \
		${WRKSRC}/lib/pkgconfig/QtWebKit.pc
# QtWebKit is statically linked with jscore, remove the latest.
	${REINPLACE_CMD} -e 's|-L../JavaScriptCore/release||; s|-ljscore||' \
		${WRKSRC}/lib/pkgconfig/QtWebKit.pc

.include <bsd.port.post.mk>
