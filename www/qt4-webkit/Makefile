# New ports collection makefile for:	qt4-webkit
# Date created:				Mon May 12 17:18:19 CEST 2008
# Whom:					danny@ricin.com
#
# $FreeBSD$
#

PORTNAME=	webkit
PORTVERSION=	${QT4_VERSION}
CATEGORIES?=	www
MASTER_SITES=	${MASTER_SITE_QT}
PKGNAMEPREFIX=	qt4-
DISTNAME=	qt-x11-opensource-src-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt4 webkit engine

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build corelib gui network xml
QT_NONSTANDARD=	yes
QT_DIST=	yes

HAS_CONFIGURE=	yes
USE_LDCONFIG=	${PREFIX}/lib/qt4

ALL_TARGET=	first
CONFIGURE_ENV?=	QTDIR=${WRKSRC} PATH=${WRKSRC}/bin:$$PATH
MAKE_ENV?=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib \
		PATH=${WRKSRC}/bin:$$PATH

DO_NOT_EXTRACT=	demos doc examples mkspecs qmake tools translations \
		src/dbus src/opengl src/phonon \
		src/qt3support src/script src/sql src/svg src/testlib \
		src/tools src/xmlpatterns src/3rdparty/clucene \
		src/3rdparty/kdebase src/3rdparty/kdelibs
EXTRACT_AFTER_ARGS=	| ${TAR} -xf -
.for dne in ${DO_NOT_EXTRACT}
EXTRACT_AFTER_ARGS+=	--exclude '${DISTNAME}/${dne}'
.endfor

WRKSRC=		${WRKDIR}/${DISTNAME}/src/3rdparty/${PORTNAME}/WebCore
CONFIGURE_WRKSRC=${WRKSRC}/../../../../

pre-configure:
	${CP} ${.CURDIR}/../../devel/qt4/files/configure ${CONFIGURE_WRKSRC}
	${MKDIR} ${WRKSRC}/../../../../mkspecs
	${LN} -sf ${LOCALBASE}/bin/qmake-qt4 ${WRKSRC}/../../../../bin/qmake
	${LN} -sf ${LOCALBASE}/bin/moc-qt4 ${WRKSRC}/../../../../bin/moc
	${LN} -sf ${LOCALBASE}/bin/rcc ${WRKSRC}/../../../../bin/rcc

post-configure:
	${REINPLACE_CMD} \
		-e 's|${PREFIX}/lib/qt4/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		-e 's|.*$$(QMAKE).*||g' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -E -e 's|-L.[^[:space:]]*qt-x11-opensource.[^[:space:]]*lib||g' \
			-E -e 's|(.*location=).*moc|\1${PREFIX}/bin/moc-qt4|g' \
		${WRKSRC}/../../../../lib/pkgconfig/QtWebKit.pc

.include <bsd.port.mk>
