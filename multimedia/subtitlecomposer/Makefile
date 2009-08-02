# New ports collection makefile for:	subtitlecomposer
# Date created:		2008-01-08
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	subtitlecomposer
PORTVERSION=	0.4.3
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=subcomposer

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Subtitle editor for KDE

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool:22
USE_KDELIBS_VER=3
USE_XORG=	xext
GNU_CONFIGURE=	yes
WANT_GSTREAMER=	yes
INSTALLS_ICONS=	yes

PORTSCOUT=	limit:^0\.4\.

OPTIONS=	MPLAYER "Enable MPlayer backend (recommended)" on \
		XINE "Enable Xine backend" off \
		GSTREAMER "Enable GStreamer backend" off

.include <bsd.port.pre.mk>

.if defined(WITH_MPLAYER)
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
.endif

.if defined(WITH_XINE)
LIB_DEPENDS+=	xine.1:${PORTSDIR}/multimedia/libxine
.else
CONFIGURE_ARGS+=--without-xine --without-xcb
.endif

.if defined(WITH_GSTREAMER)
USE_GSTREAMER+=	yes
.else
CONFIGURE_ARGS+=--without-gstreamer
.endif

.include <bsd.port.post.mk>
