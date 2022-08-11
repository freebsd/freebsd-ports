PORTNAME=	phonon
DISTVERSION=	4.10.0
PORTREVISION=	4
CATEGORIES=	multimedia kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTNAME}-backend-${PHONON_PLUGIN}/${DISTVERSION}
DISTNAME=	${PORTNAME}-backend-${PHONON_PLUGIN}-${DISTVERSION}
DIST_SUBDIR=	KDE/phonon
PKGNAMESUFFIX=	-${PHONON_PLUGIN}-qt5

MAINTAINER=	kde@FreeBSD.org
COMMENT=	GStreamer backend for Phonon

LICENSE=	LGPL21

USES=		cmake compiler:c++11-lang gl gnome gstreamer kde:5 pkgconfig qt:5 tar:xz xorg
USE_GL=		gl
USE_GNOME=	glib20 libxml2
USE_KDE=	ecm
USE_QT=		core gui opengl phonon4 widgets x11extras \
		buildtools_build qmake_build
USE_XORG=	x11

CMAKE_ON=	PHONON_BUILD_PHONON4QT5

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	GST_PLUGINS
GST_PLUGINS_DESC=	Install GStreamer plugins
GST_PLUGINS_USE=	GSTREAMER=bad,good,ugly

PHONON_PLUGIN=	gstreamer
WRKSRC=		${WRKDIR}/${PORTNAME}-backend-${PHONON_PLUGIN}-${DISTVERSION}

.include <bsd.port.mk>
