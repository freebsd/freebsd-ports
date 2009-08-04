# -*-mode: makefile-*-
# New ports collection makefile for:	qt40
# Date created:				Wed Jun 29 11:49:42 CEST 2005
# Whom:					lofi@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	qtdemo
PORTVERSION=	${QT4_VERSION}
PORTREVISION=0
CATEGORIES?=	misc
MASTER_SITES=	${MASTER_SITE_QT}
PKGNAMEPREFIX=	qt4-
DISTNAME=	qt-x11-opensource-src-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt demonstration and example programs

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build assistantclient \
		corelib designer gui network opengl sql svg qtestlib xml \
		imageformats_run dbus script webkit phonon help assistant_run \
		phonon-gst scripttools xmlpatterns
QT_NONSTANDARD=	yes
QT_DIST=	yes

HAS_CONFIGURE=	yes

ALL_TARGET=	first
CONFIGURE_ENV?=	QTDIR=${WRKSRC} PATH=${WRKSRC}/bin:$$PATH
MAKE_ENV?=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib \
		PATH=${WRKSRC}/bin:$$PATH

DO_NOT_EXTRACT=	doc mkspecs qmake translations
EXTRACT_AFTER_ARGS=	| ${TAR} -xf -
.for dne in ${DO_NOT_EXTRACT}
EXTRACT_AFTER_ARGS+=	--exclude '${DISTNAME}/${dne}'
.endfor

WRKSRC=		${WRKDIR}/${DISTNAME}/demos
CONFIGURE_WRKSRC=${WRKSRC}/../
PATCH_WRKSRC=	${CONFIGURE_WRKSRC}

post-patch:
	${REINPLACE_CMD} -e '/app +=/s|"assistant"|"assistant-qt4"|' \
		${PATCH_WRKSRC}/demos/qtdemo/menumanager.cpp \
		${PATCH_WRKSRC}/examples/help/remotecontrol/remotecontrol.cpp \
		${PATCH_WRKSRC}/examples/help/simpletextviewer/assistant.cpp

pre-configure:
	${CP} ${.CURDIR}/../../devel/qt4/files/configure ${CONFIGURE_WRKSRC}
	${MKDIR} ${WRKSRC}/../mkspecs
	${LN} -sf ${LOCALBASE}/bin/qmake-qt4 ${WRKSRC}/../bin/qmake
	${LN} -sf ${LOCALBASE}/bin/moc-qt4 ${WRKSRC}/../bin/moc
	${LN} -sf ${LOCALBASE}/bin/uic-qt4 ${WRKSRC}/../bin/uic
	${LN} -sf ${LOCALBASE}/bin/rcc ${WRKSRC}/../bin/rcc

post-build:
	cd ${WRKSRC}/../examples && ${MAKE} -f Makefile first

post-install:
	cd ${WRKSRC}/../examples && ${MAKE} -f Makefile install

.include <bsd.port.mk>
