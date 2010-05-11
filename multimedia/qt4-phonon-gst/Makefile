# New ports collection makefile for:	qt4-phonon-gst
# Date created:				Mon May 12 15:33:12 CEST 2008
# Whom:					danny@ricin.com
#
# $FreeBSD$
#

PORTNAME=	phonon
PORTVERSION=	${QT4_VERSION}
CATEGORIES?=	multimedia
PKGNAMEPREFIX=	qt4-
PKGNAMESUFFIX=	-gst

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt4 multimedia framework, gstreamer backend

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build corelib gui phonon opengl dbus
QT_NONSTANDARD=	yes
QT_DIST=	yes

USE_GSTREAMER=	yes

HAS_CONFIGURE=	yes

ALL_TARGET=	first
CONFIGURE_ENV?=	QTDIR=${WRKSRC} PATH=${WRKSRC}/bin:$$PATH
MAKE_ENV?=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib \
		PATH=${WRKSRC}/bin:$$PATH

DO_NOT_EXTRACT=	demos doc examples mkspecs qmake tools translations \
		src/activeqt src/dbus src/multimedia src/network src/openvg \
		src/qt3support src/s60installs src/s60main src/script \
		src/scripttools src/sql src/svg src/testlib src/tools \
		src/winmain src/xml src/xmlpatterns src/3rdparty/clucene \
		src/3rdparty/freetype src/3rdparty/libjpeg src/3rdparty/libmng \
		src/3rdparty/libpng src/3rdparty/libtiff src/3rdparty/webkit
EXTRACT_AFTER_ARGS=	| ${TAR} -xf -
.for dne in ${DO_NOT_EXTRACT}
EXTRACT_AFTER_ARGS+=	--exclude '${DISTNAME}/${dne}'
.endfor

BUILD_WRKSRC=	${WRKSRC}/src/plugins/${PORTNAME}/gstreamer
INSTALL_WRKSRC=	${BUILD_WRKSRC}

EXTRA_PATCHES=	${.CURDIR}/../../devel/qt4/files/patch-configure

.if !defined(WITH_QT_PHONON)
IGNORE=		conflicts with multimedia/phonon-gstreamer. You have defined WITH_KDE_PHONON to override Qt4 phonon
.endif

pre-configure:
	${ECHO_CMD} "DEFINES+= QT_OPENGL" >> ${BUILD_WRKSRC}/gstreamer.pro
	${MKDIR} ${WRKSRC}/mkspecs
	${LN} -sf ${LOCALBASE}/bin/qmake-qt4 ${WRKSRC}/bin/qmake
	${LN} -sf ${LOCALBASE}/bin/moc-qt4 ${WRKSRC}/bin/moc

.include <bsd.port.mk>
