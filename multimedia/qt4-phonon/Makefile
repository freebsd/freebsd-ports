# New ports collection makefile for:	qt4-phonon
# Date created:				Mon May 12 15:33:12 CEST 2008
# Whom:					danny@ricin.com
#
# $FreeBSD$
#

PORTNAME=	phonon
PORTVERSION=	${QT4_VERSION}
CATEGORIES?=	multimedia
PKGNAMEPREFIX=	qt4-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt4 multimedia framework

CONFLICTS=	phonon-4.*

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build corelib dbus gui xml
QT_NONSTANDARD=	yes
QT_DIST=	yes
USE_KDE4=	#dummy, we need to know KDE4_PREFIX

HAS_CONFIGURE=	yes
USE_LDCONFIG=	${PREFIX}/lib/qt4

ALL_TARGET=	first
CONFIGURE_ENV?=	QTDIR=${WRKSRC} PATH=${WRKSRC}/bin:$$PATH
MAKE_ENV?=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib \
		PATH=${WRKSRC}/bin:$$PATH

DO_NOT_EXTRACT=	demos doc examples mkspecs qmake tools translations \
		src/activeqt src/multimedia src/network src/opengl src/openvg \
		src/qt3support src/s60installs src/s60main src/script \
		src/scripttools src/sql src/svg src/testlib src/tools \
		src/winmain src/xmlpatterns src/3rdparty/clucene \
		src/3rdparty/freetype src/3rdparty/libjpeg src/3rdparty/libmng \
		src/3rdparty/libpng src/3rdparty/libtiff src/3rdparty/webkit
EXTRACT_AFTER_ARGS=	| ${TAR} -xf -
.for dne in ${DO_NOT_EXTRACT}
EXTRACT_AFTER_ARGS+=	--exclude '${DISTNAME}/${dne}'
.endfor

BUILD_WRKSRC=	${WRKSRC}/src/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

EXTRA_PATCHES=	${.CURDIR}/../../devel/qt4/files/patch-configure

.include <bsd.port.pre.mk>

.if !defined(WITH_QT_PHONON)
IGNORE=		conflicts with multimedia/phonon. You have defined WITH_KDE_PHONON to override Qt4 phonon
.endif

pre-configure:
	${MKDIR} ${WRKSRC}/mkspecs
	${LN} -sf ${LOCALBASE}/bin/qmake-qt4 ${WRKSRC}/bin/qmake
	${LN} -sf ${LOCALBASE}/bin/moc-qt4 ${WRKSRC}/bin/moc

pre-install:
	${REINPLACE_CMD} \
		-e 's|${PREFIX}/lib/qt4/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		${BUILD_WRKSRC}/Makefile
	${REINPLACE_CMD} -E -e 's|-L.[^[:space:]]*qt-x11-opensource.[^[:space:]]*lib||g' \
			-E -e 's|(.*location=).*moc|\1${PREFIX}/bin/moc-qt4|g' \
		${WRKSRC}/lib/pkgconfig/phonon.pc

post-install:
	${MKDIR} ${QT_PLUGINDIR}/phonon_backend
	${LN} -sf ${PREFIX}/include/qt4/phonon ${PREFIX}/include/qt4/Phonon

.include <bsd.port.post.mk>
