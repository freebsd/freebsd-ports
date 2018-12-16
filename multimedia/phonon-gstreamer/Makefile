# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	phonon
PORTVERSION=	4.9.0
PORTREVISION=	3
CATEGORIES=	multimedia kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTNAME}-backend-${PHONON_PLUGIN}/${DISTVERSION}
DISTNAME=	${PORTNAME}-backend-${PHONON_PLUGIN}-${DISTVERSION}
DIST_SUBDIR=	KDE/phonon

MAINTAINER=	kde@FreeBSD.org
COMMENT=	GStreamer backend for Phonon

LICENSE=	LGPL21

FLAVORS=	qt5 qt4
FLAVOR?=	${FLAVORS:[1]}

qt4_PKGNAMESUFFIX=	-${PHONON_PLUGIN}-qt4
qt5_PKGNAMESUFFIX=	-${PHONON_PLUGIN}-qt5
qt4_PLIST=	${.CURDIR}/pkg-plist.qt4
qt5_PLIST=	${.CURDIR}/pkg-plist.qt5

USES=		cmake pkgconfig tar:xz
USE_GL=		gl
USE_GNOME=	glib20 libxml2
USE_GSTREAMER1=	yes
USE_XORG=	x11

.  if ${FLAVOR} == qt4
DEPRECATED=	Qt4 has been EOL since december 2015
EXPIRATION_DATE=2019-03-15
USES+=		kde:4 qt:4
USE_KDE=	automoc4
USE_QT=		corelib gui opengl phonon \
		qmake_build moc_build rcc_build uic_build
.  else
USES+=		kde:5 qt:5
USE_KDE=	ecm
USE_QT=		core gui opengl phonon4 widgets x11extras \
		buildtools_build qmake_build
CMAKE_ON=	PHONON_BUILD_PHONON4QT5
.  endif
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	GST_PLUGINS
GST_PLUGINS_DESC=	Install GStreamer plugins
GST_PLUGINS_RUN_DEPENDS=	gstreamer1-plugins-all>=0:multimedia/gstreamer1-plugins-all

PHONON_PLUGIN=	gstreamer
WRKSRC=		${WRKDIR}/${PORTNAME}-${PHONON_PLUGIN}-${DISTVERSION}

.  if ${FLAVOR} == qt4
post-install:
	${MKDIR} ${STAGEDIR}${QT_PLUGINDIR}/phonon_backend
	${RLN} ${STAGEDIR}${PREFIX}/lib/kde4/plugins/phonon_backend/phonon_gstreamer.so \
		${STAGEDIR}${QT_PLUGINDIR}/phonon_backend/libphonon_gstreamer.so
.  endif

.include <bsd.port.mk>
