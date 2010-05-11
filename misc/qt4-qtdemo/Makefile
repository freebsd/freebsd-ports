# -*-mode: makefile-*-
# New ports collection makefile for:	qt40
# Date created:				Wed Jun 29 11:49:42 CEST 2005
# Whom:					lofi@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	qtdemo
PORTVERSION=	${QT4_VERSION}
CATEGORIES?=	misc
PKGNAMEPREFIX=	qt4-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt demonstration and example programs

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build assistantclient \
		corelib designer gui network opengl sql svg qtestlib xml \
		imageformats_run dbus script webkit phonon help assistant_run \
		phonon-gst scripttools xmlpatterns multimedia
QT_NONSTANDARD=	yes
QT_DIST=	yes

HAS_CONFIGURE=	yes

ALL_TARGET=	first
CONFIGURE_ENV?=	QTDIR=${WRKSRC} PATH=${WRKSRC}/bin:$$PATH
MAKE_ENV?=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib \
		PATH=${WRKSRC}/bin:$$PATH

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
	${MKDIR} ${WRKSRC}/mkspecs
	${LN} -sf ${LOCALBASE}/bin/qmake-qt4 ${WRKSRC}/bin/qmake
	${LN} -sf ${LOCALBASE}/bin/moc-qt4 ${WRKSRC}/bin/moc
	${LN} -sf ${LOCALBASE}/bin/uic-qt4 ${WRKSRC}/bin/uic
	${LN} -sf ${LOCALBASE}/bin/rcc ${WRKSRC}/bin/rcc

post-build:
	cd ${WRKSRC}/examples && ${SETENV} MAKEOBJDIR=. ${MAKE}

post-install:
	cd ${WRKSRC}/examples && ${SETENV} MAKEOBJDIR=. ${MAKE} install

.include <bsd.port.mk>
