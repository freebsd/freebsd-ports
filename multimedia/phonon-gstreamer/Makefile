# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	phonon
PORTVERSION=	4.7.0
CATEGORIES=	multimedia kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${PHONON_BRANCH}/${PORTNAME}/${PORTNAME}-backend${PKGNAMESUFFIX}/${PORTVERSION}/src
PKGNAMESUFFIX=	-gstreamer
DISTNAME=	${PORTNAME}-backend${PKGNAMESUFFIX}-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	GStreamer backend for Phonon

# Required in order to avoid conflicts with multimedia/phonon's OPTIONS.
LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}

CONFLICTS=	qt4-phonon-gst-4*

PHONON_BRANCH=	stable

USE_GL=		gl
USE_GNOME=	glib20 libxml2
USE_GSTREAMER=	yes
USE_KDE4=	kdehier kdeprefix automoc4
USE_QT4=	corelib gui opengl phonon \
		qmake_build moc_build rcc_build uic_build
USE_XORG=	x11
USE_XZ=		yes
USES=		cmake pkgconfig

PLIST_SUB+=	QT_PREFIX=${QT_PREFIX}

OPTIONS_DEFINE=	GST_PLUGINS

GST_PLUGINS_DESC=	Install GStreamer plugins

OPTIONS_DEFAULT=

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGST_PLUGINS}
RUN_DEPENDS+=	gstreamer-plugins-all>=0:${PORTSDIR}/multimedia/gstreamer-plugins-all
.else
SUB_FILES=	pkg-message
.endif

post-install:
	${MKDIR} ${STAGEDIR}${QT_PLUGINDIR}/phonon_backend
	${LN} -sf ${PREFIX}/lib/kde4/plugins/phonon_backend/phonon_gstreamer.so \
		${STAGEDIR}${QT_PLUGINDIR}/phonon_backend/libphonon_gstreamer.so

.include <bsd.port.mk>
