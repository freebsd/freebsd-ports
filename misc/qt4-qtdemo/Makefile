# -*-mode: makefile-*-
# New ports collection makefile for:	qt40
# Date created:				Wed Jun 29 11:49:42 CEST 2005
# Whom:					lofi@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	qtdemo
PORTVERSION=	4.2.2
PORTREVISION=	2
CATEGORIES?=	misc
MASTER_SITES=	${MASTER_SITE_QT}
PKGNAMEPREFIX=	qt4-
DISTNAME=	qt-x11-opensource-src-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt demonstration and example programs

BUILD_DEPENDS=	moc4:${PORTSDIR}/devel/qt4-moc \
		qmake-qt4:${PORTSDIR}/devel/qmake4 \
		rcc:${PORTSDIR}/devel/qt4-rcc \
		uic4:${PORTSDIR}/devel/qt4-uic
LIB_DEPENDS=	QtAssistantClient:${PORTSDIR}/devel/qt4-libqtassistantclient \
		QtCore:${PORTSDIR}/devel/qt4-corelib \
		QtDBus:${PORTSDIR}/devel/dbus-qt4 \
		QtDesigner:${PORTSDIR}/devel/qt4-designer \
		QtGui:${PORTSDIR}/x11-toolkits/qt4-gui \
		QtNetwork:${PORTSDIR}/net/qt4-network \
		QtOpenGL:${PORTSDIR}/x11/qt4-opengl \
		QtSql:${PORTSDIR}/databases/qt4-sql \
		QtSvg:${PORTSDIR}/graphics/qt4-svg \
		QtTest:${PORTSDIR}/devel/qt4-qtestlib \
		QtXml:${PORTSDIR}/textproc/qt4-xml
RUN_DEPENDS=	qt4-imageformats>=4.2.2:${PORTSDIR}/graphics/qt4-imageformats

CONFLICTS=	linguist-0.* qt-2.* qt-3.0.* \
		qt-3.1.* qt-3.2.* qt-designer-2.* xfmail-1.5.[0-5] \
		xfmail-1.5.5_[1-2]

HAS_CONFIGURE=	yes

CONFIGURE_ARGS=	-fast -no-exceptions \
		-platform ${LOCALBASE}/share/qt4/mkspecs/freebsd-g++ \
		-qt-gif -release -system-libjpeg -system-libpng \
		-system-zlib -no-nas-sound -prefix ${PREFIX} -no-sm \
		-plugindir ${PREFIX}/lib/plugins -bindir ${PREFIX}/bin \
		-confirm-license

ALL_TARGET=	first
CONFIGURE_ENV?=	QTDIR=${WRKSRC} PATH=${WRKSRC}/bin:$$PATH
MAKE_ENV?=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib \
		PATH=${WRKSRC}/bin:$$PATH
WRKSRC=		${WRKDIR}/${DISTNAME}/demos
CONFIGURE_WRKSRC=${WRKSRC}/../

pre-configure:
	${CP} ${.CURDIR}/../../devel/qt4/files/configure ${CONFIGURE_WRKSRC}
	${MKDIR} ${WRKSRC}/../mkspecs
	${LN} -sf ${LOCALBASE}/bin/qmake-qt4 ${WRKSRC}/../bin/qmake
	${LN} -sf ${LOCALBASE}/bin/moc4 ${WRKSRC}/../bin/moc
	${LN} -sf ${LOCALBASE}/bin/uic4 ${WRKSRC}/../bin/uic
	${LN} -sf ${LOCALBASE}/bin/rcc ${WRKSRC}/../bin/rcc

post-build:
	cd ${WRKSRC}/../examples && ${MAKE} -f Makefile first

post-install:
	cd ${WRKSRC}/../examples && ${MAKE} -f Makefile install

.include <bsd.port.mk>
