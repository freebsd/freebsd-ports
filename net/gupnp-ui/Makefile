# New ports collection makefile for:	gupnp-ui
# Date created:		2009-12-26
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gupnp-ui
PORTVERSION=	0.1.1
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.gupnp.org/sources/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Framework for UPnP devices

LIB_DEPENDS=	soup-2.4.1:${PORTSDIR}/devel/libsoup \
		gupnp-1.0:${PORTSDIR}/net/gupnp

USE_PYTHON=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack intlhack libglade2 gtk20
USE_LDCONFIG=	yes

.include <bsd.port.mk>
