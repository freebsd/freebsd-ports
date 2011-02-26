# New ports collection makefile for:	gupnp-av
# Date created:		2009-12-26
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gupnp-av
PORTVERSION=	0.5.4
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.gupnp.org/sources/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Helpers for audio/video applications using GUPnP

LIB_DEPENDS=	gupnp-1.0:${PORTSDIR}/net/gupnp

GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack intlhack glib20
USE_LDCONFIG=	yes

.include <bsd.port.mk>
