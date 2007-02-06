# -*-mode: makefile-*-
# New ports collection makefile for:	qt40
# Date created:				Wed Jun 29 11:49:42 CEST 2005
# Whom:					lofi@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	doc
PORTVERSION=	4.2.2
CATEGORIES?=	misc
MASTER_SITES=	${MASTER_SITE_QT}
PKGNAMEPREFIX= 	qt4-
DISTNAME=	qt-x11-opensource-src-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Multiplatform C++ application framework

CONFLICTS=	linguist-0.* qt-2.* qt-3.0.* \
		qt-3.1.* qt-3.2.* qt-designer-2.* xfmail-1.5.[0-5] \
		xfmail-1.5.5_[1-2]

NO_BUILD=	yes

CONFIGURE_ARGS=	-fast -no-exceptions \
		-platform ${LOCALBASE}/share/qt/mkspecs/freebsd-g++ \
		-qt-gif -release -system-libjpeg -system-libpng \
		-system-zlib -no-nas-sound -prefix ${PREFIX} \
		-plugindir ${PREFIX}/lib/plugins -bindir ${PREFIX}/bin \
		-confirm-license

ALL_TARGET=	first
CONFIGURE_ENV?=	QTDIR=${WRKSRC} PATH=${WRKSRC}/bin:$$PATH
MAKE_ENV?=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib \
		PATH=${WRKSRC}/bin:$$PATH
EXTRACT_AFTER_ARGS=| ${TAR} -xf - \
	--exclude '${DISTNAME}/mkspecs' --exclude '${DISTNAME}/qmake' \
	--exclude '${DISTNAME}/demos' --exclude '${DISTNAME}/examples' \
	--exclude '${DISTNAME}/src/gui' --exclude '${DISTNAME}/src/network' \
	--exclude '${DISTNAME}/src/opengl' --exclude '${DISTNAME}/src/qt3support' \
	--exclude '${DISTNAME}/src/sql' --exclude '${DISTNAME}/src/plugins' \
	--exclude '${DISTNAME}/src/3rdparty' --exclude '${DISTNAME}/src/xml' \
	--exclude '${DISTNAME}/src/tools/rcc' --exclude '${DISTNAME}/src/tools/moc'\
	--exclude '${DISTNAME}/src/tools/uic' --exclude '${DISTNAME}/src/tools/uic3' \
	--exclude '${DISTNAME}/tools/assistant' --exclude '${DISTNAME}/tools/designer' \
	--exclude '${DISTNAME}/tools/linguist' --exclude '${DISTNAME}/tools/porting' \
	--exclude '${DISTNAME}/tools/qtconfig' --exclude '${DISTNAME}/tools/qvfb'

DOCSDIR=${PREFIX}/share/doc/qt4
do-install:
	${MKDIR} ${DOCSDIR}
	${RM} -f ${WRKSRC}/doc/html/qmake*
	${CP} -Rp ${WRKSRC}/doc/html ${DOCSDIR}

.include <bsd.port.mk>
