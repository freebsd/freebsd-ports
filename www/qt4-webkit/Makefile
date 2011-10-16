# New ports collection makefile for:	qt4-webkit
# Date created:				Mon May 12 17:18:19 CEST 2008
# Whom:					danny@ricin.com
#
# $FreeBSD$
#

PORTNAME=	webkit
DISTVERSION=	${QT4_VERSION}
CATEGORIES?=	www
PKGNAMEPREFIX=	qt4-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt4 WebKit engine

USE_QT_VER=	4
QT_COMPONENTS=	corelib declarative gui network phonon \
		qmake_build moc_build rcc_build
QT_NONSTANDARD=	yes
QT_DIST=	yes
USE_XORG=	xrender
MAKE_JOBS_SAFE=	yes

HAS_CONFIGURE=	yes
USE_LDCONFIG=	${PREFIX}/lib/qt4

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
EXTRACT_AFTER_ARGS=	| ${TAR} -xf -
.for dne in ${DO_NOT_EXTRACT}
EXTRACT_AFTER_ARGS+=	--exclude '${DISTNAME}/${dne}'
.endfor

BUILD_WRKSRC=	${WRKSRC}/src/3rdparty/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

CONFIGURE_ARGS+=	-I../../../../include/Qt -I../../../../include

EXTRA_PATCHES=	${.CURDIR}/../../devel/qt4/files/patch-configure

pre-configure:
	${MKDIR} ${WRKSRC}/mkspecs
	${LN} -sf ${LOCALBASE}/bin/qmake-qt4 ${WRKSRC}/bin/qmake
	${LN} -sf ${LOCALBASE}/bin/moc-qt4 ${WRKSRC}/bin/moc
	${LN} -sf ${LOCALBASE}/bin/rcc ${WRKSRC}/bin/rcc
	${REINPLACE_CMD} -e '/WebKit\/qt\/tests/ d' \
		${BUILD_WRKSRC}/WebKit.pro

post-configure:
	${REINPLACE_CMD} \
		-e 's|${PREFIX}/lib/qt4/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		-e 's|.*$$(QMAKE).*||g' \
		-e '/^CFLAGS/ s|-I${LOCALBASE}/include ||g' \
		-e '/^CXXFLAGS/ s|-I${LOCALBASE}/include ||g' \
		${BUILD_WRKSRC}/WebCore/Makefile
	${REINPLACE_CMD} -E -e 's|-L.[^[:space:]]*qt-x11-opensource.[^[:space:]]*lib||g' \
			-E -e 's|(.*location=).*moc|\1${PREFIX}/bin/moc-qt4|g' \
		${WRKSRC}/lib/pkgconfig/QtWebKit.pc
# QtWebKit is statically linked with jscore, remove the latest.
	${REINPLACE_CMD} -e 's|-L../JavaScriptCore/release||;s|-ljscore||' \
		${WRKSRC}/lib/pkgconfig/QtWebKit.pc \
		${WRKSRC}/lib/libQtWebKit.la

.include <bsd.port.mk>
