# Created by: danny@ricin.com
# $FreeBSD$

PORTNAME=	xmlpatterns-tool
DISTVERSION=	${QT4_VERSION}
PORTREVISION=	2
CATEGORIES=	textproc
PKGNAMEPREFIX=	qt4-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt command-line utility for running XQueries

USE_QT4=	qmake_build xmlpatterns
QT_DIST=	yes

HAS_CONFIGURE=	yes

ALL_TARGET=	first
CONFIGURE_ENV?=	QTDIR=${WRKSRC} PATH=${WRKSRC}/bin:$$PATH
MAKE_ENV?=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib:$$LD_LIBRARY_PATH \
		PATH=${WRKSRC}/bin:$$PATH

DO_NOT_EXTRACT=	demos doc examples mkspecs qmake translations \
		src/activeqt src/dbus src/gui src/multimedia src/network \
		src/opengl src/openvg src/phonon src/qt3support \
		src/s60installs src/s60main src/script src/scripttools \
		src/sql src/svg src/testlib src/tools src/winmain src/xml \
		src/3rdparty/clucene src/3rdparty/freetype \
		src/3rdparty/libjpeg src/3rdparty/libmng src/3rdparty/libpng \
		src/3rdparty/libtiff src/3rdparty/phonon src/3rdparty/webkit
.for dne in ${DO_NOT_EXTRACT}
EXTRACT_AFTER_ARGS+=	--exclude '${DISTNAME}/${dne}'
.endfor

BUILD_WRKSRC=	${WRKSRC}/tools/xmlpatterns
INSTALL_WRKSRC=	${BUILD_WRKSRC}

pre-configure:
	${MKDIR} ${WRKSRC}/mkspecs
#	${REINPLACE_CMD} -e 's|^TARGET.*|TARGET=xmlpatterns|g' \
#		${BUILD_WRKSRC}/xmlpatterns.pro
	${LN} -sf ${QMAKE} ${WRKSRC}/bin/qmake

.include <bsd.port.mk>
