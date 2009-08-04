# New ports collection makefile for:	qt4-phonon
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
DISTNAME=	qt-x11-opensource-src-${PORTVERSION}
DIST_SUBDIR=	KDE

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
		src/network src/opengl \
		src/qt3support src/script src/sql src/svg src/testlib \
		src/tools src/xmlpatterns src/3rdparty/clucene \
		src/3rdparty/webkit
EXTRACT_AFTER_ARGS=	| ${TAR} -xf -
.for dne in ${DO_NOT_EXTRACT}
EXTRACT_AFTER_ARGS+=	--exclude '${DISTNAME}/${dne}'
.endfor

BUILD_WRKSRC=	${WRKSRC}/src/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

.include <bsd.port.pre.mk>

.if exists(${KDE4_PREFIX}/lib/libphonon.so)
IGNORE=		conflicts with KDE4 phonon. Please, deinstall multimedia/phonon
.endif

pre-configure:
	${CP} ${.CURDIR}/../../devel/qt4/files/configure ${CONFIGURE_WRKSRC}
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
	${LN} -sf ${LOCALBASE}/include/qt4/phonon ${LOCALBASE}/include/qt4/Phonon
	${LN} -sf ${LOCALBASE}/include/qt4/Phonon/phononnamespace.h ${LOCALBASE}/include/qt4/Phonon/Global

.include <bsd.port.post.mk>
