# Created by: Max Brazhnikov <makc@issp.ac.ru>
# $FreeBSD$

PORTNAME=	subtitlecomposer
PORTVERSION=	0.4.3
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	SF/subcomposer/subcomposer/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Subtitle editor for KDE

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
USE_KDELIBS_VER=3
USE_XORG=	xext
GNU_CONFIGURE=	yes
WANT_GSTREAMER=	yes
INSTALLS_ICONS=	yes

PORTSCOUT=	limit:^0\.4\.

OPTIONS_DEFINE=	MPLAYER XINE GSTREAMER
OPTIONS_DEFAULT=	MPLAYER

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMPLAYER}
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
.endif

.if ${PORT_OPTIONS:MXINE}
LIB_DEPENDS+=	xine.2:${PORTSDIR}/multimedia/libxine
.else
CONFIGURE_ARGS+=--without-xine --without-xcb
.endif

.if ${PORT_OPTIONS:MGSTREAMER}
USE_GSTREAMER+=	yes
.else
CONFIGURE_ARGS+=--without-gstreamer
.endif

.include <bsd.port.mk>
