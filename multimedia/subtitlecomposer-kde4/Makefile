# New ports collection makefile for:	subtitlecomposer
# Date created:		2008-01-08
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	subtitlecomposer
PORTVERSION=	0.4.2
CATEGORIES=	multimedia
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=subcomposer

MAINTAINER=	makc@issp.ac.ru
COMMENT=	Subtitle editor for KDE

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool:15
USE_KDELIBS_VER=3
USE_XORG=	xext
GNU_CONFIGURE=	yes
WANT_GSTREAMER=	yes
INSTALLS_ICONS=	yes

OPTIONS=	MPLAYER "Enable MPlayer backend (recommended)" on \
		XINE "Enable Xine backend" off \
		GSTREAMER "Enable GStreamer backend" off

.include <bsd.port.pre.mk>

.if defined(WITH_MPLAYER)
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
.endif

.if defined(WITH_XINE)

. if exists(${LOCALBASE}/bin/xine-config)
XINE_PLUGINDIR!=	${LOCALBASE}/bin/xine-config --plugindir
. endif

. if defined(XINE_PLUGINDIR) && !exists(${XINE_PLUGINDIR}/xineplug_vo_out_xcbxv.so)
IGNORE=		needs XCB support in libxine
. endif

LIB_DEPENDS+=	xine.1:${PORTSDIR}/multimedia/libxine \
		xcb.1:${PORTSDIR}/x11/libxcb
.else
CONFIGURE_ARGS+=--without-xine --without-xcb
.endif

.if defined(WITH_GSTREAMER)
USE_GSTREAMER+=	yes
.else
CONFIGURE_ARGS=	--without-gstreamer
.endif

.include <bsd.port.post.mk>
