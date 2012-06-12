# New ports collection makefile for:	gupnp-ui
# Date created:		2009-12-26
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gupnp-ui
PORTVERSION=	0.1.1
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Framework for UPnP devices

LICENSE=	LGPL20

BUILD_DEPENDS=	gupnp>=0.3:${PORTSDIR}/net/gupnp
LIB_DEPENDS=	gupnp-1.0:${PORTSDIR}/net/gupnp \
		soup-2.4:${PORTSDIR}/devel/libsoup
RUN_DEPENDS=	gupnp>=0.3:${PORTSDIR}/net/gupnp

GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack gtk20
USE_LDCONFIG=	yes
USE_PYTHON=	yes

.include <bsd.port.mk>
