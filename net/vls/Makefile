# New ports collection makefile for:	vls
# Date created:		3rd August 2001
# Whom:			Gleb Smirnoff <glebius@cell.sick.ru>
#
# $FreeBSD$
#

PORTNAME=	vls
PORTVERSION=	0.5.0
CATEGORIES=	net
MASTER_SITES=	http://www.videolan.org/pub/videolan/vls/${PORTVERSION}/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	An X11 video streaming client/server solution

LIB_DEPENDS=	dvdcss.2:${PORTSDIR}/multimedia/libdvdcss \
		dvbpsi.1:${PORTSDIR}/multimedia/libdvbpsi \
		dvdread.3:${PORTSDIR}/multimedia/libdvdread

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-dvdcss=${LOCALBASE} \
		--with-dvbpsi=${LOCALBASE} \
		--with-dvdread=${LOCALBASE}

INSTALLS_SHLIB=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>
