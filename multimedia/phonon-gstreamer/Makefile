# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	phonon
PORTVERSION=	4.8.2
PORTREVISION=	1
CATEGORIES=	multimedia kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTNAME}-backend${PKGNAMESUFFIX}/${PORTVERSION}/src
PKGNAMESUFFIX=	-gstreamer
DISTNAME=	${PORTNAME}-backend${PKGNAMESUFFIX}-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	GStreamer backend for Phonon

LICENSE=	LGPL21

USE_GL=		gl
USE_GNOME=	glib20 libxml2
USE_GSTREAMER1=	yes
USE_KDE4=	automoc4
USE_QT4=	corelib gui opengl phonon \
		qmake_build moc_build rcc_build uic_build
USE_XORG=	x11
USES=		cmake pkgconfig tar:xz

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	GST_PLUGINS
GST_PLUGINS_DESC=	Install GStreamer plugins
GST_PLUGINS_RUN_DEPENDS=	gstreamer1-plugins-all>=0:multimedia/gstreamer1-plugins-all

post-install:
	${MKDIR} ${STAGEDIR}${QT_PLUGINDIR}/phonon_backend
	${LN} -sf ${PREFIX}/lib/kde4/plugins/phonon_backend/phonon_gstreamer.so \
		${STAGEDIR}${QT_PLUGINDIR}/phonon_backend/libphonon_gstreamer.so

.include <bsd.port.mk>
