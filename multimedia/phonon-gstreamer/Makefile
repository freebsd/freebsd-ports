# New ports collection Makefile for:	phonon
# Date created:				2008-01-30
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	phonon
PORTVERSION=	4.6.2
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
USE_QT4=	gui phonon xml \
		qmake_build moc_build rcc_build uic_build
USE_XORG=	x11
USE_XZ=		yes
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes

PLIST_SUB+=	QT_PREFIX=${QT_PREFIX}

.if defined(WITH_QT_PHONON)
IGNORE=		conflicts with Qt 4 Phonon. Please, deinstall qt4-phonon-gst and unset WITH_QT_PHONON to continue
.endif

OPTIONS_DEFINE=	PLUGINS
PLUGINS_DESC=	Install GStreamer plugins

OPTIONS_DEFAULT=

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPLUGINS}
RUN_DEPENDS+=	gstreamer-plugins-all>=0:${PORTSDIR}/multimedia/gstreamer-plugins-all
.else
SUB_FILES=	pkg-message
.endif

pre-su-install:
	${MKDIR} ${QT_PLUGINDIR}/phonon_backend

post-install:
	${LN} -sf ${PREFIX}/lib/kde4/plugins/phonon_backend/phonon_gstreamer.so \
		${QT_PLUGINDIR}/phonon_backend/libphonon_gstreamer.so
.if empty(PORT_OPTIONS:MPLUGINS)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
