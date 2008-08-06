# New ports collection makefile for:	qt4-phonon-gst
# Date created:				Mon May 12 15:33:12 CEST 2008
# Whom:					danny@ricin.com
#
# $FreeBSD$
#

PORTNAME=	phonon
PORTVERSION=	${QT4_VERSION}
CATEGORIES?=	multimedia
MASTER_SITES=	${MASTER_SITE_QT}
PKGNAMEPREFIX=	qt4-
PKGNAMESUFFIX=	-gst
DISTNAME=	qt-x11-opensource-src-${PORTVERSION}
DIST_SUBDIR=	KDE

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
		src/network \
		src/qt3support src/script src/sql src/svg src/testlib \
		src/tools src/xmlpatterns src/3rdparty/clucene \
		src/3rdparty/webkit
EXTRACT_AFTER_ARGS=	| ${TAR} -xf -
.for dne in ${DO_NOT_EXTRACT}
EXTRACT_AFTER_ARGS+=	--exclude '${DISTNAME}/${dne}'
.endfor

WRKSRC=		${WRKDIR}/${DISTNAME}/src/plugins/phonon/gstreamer
CONFIGURE_WRKSRC=${WRKSRC}/../../../../

pre-configure:
	${CP} ${.CURDIR}/../../devel/qt4/files/configure ${CONFIGURE_WRKSRC}
	${ECHO_CMD} "DEFINES+= QT_OPENGL" >> ${WRKSRC}/gstreamer.pro
	${MKDIR} ${WRKSRC}/../../../../mkspecs
	${LN} -sf ${LOCALBASE}/bin/qmake-qt4 ${WRKSRC}/../../../../bin/qmake
	${LN} -sf ${LOCALBASE}/bin/moc-qt4 ${WRKSRC}/../../../../bin/moc

.include <bsd.port.mk>
