# Ports collection makefile for:	swfdec-plugin
# Date created:				Jun 14, 2005
# Whom:					anholt
#
# $FreeBSD$
#

PORTNAME=	swfdec-plugin
PORTVERSION=	0.6.0
CATEGORIES=	www
MASTER_SITES=	http://swfdec.freedesktop.org/download/swfdec-mozilla/0.6/
DISTNAME=	swfdec-mozilla-${PORTVERSION}

MAINTAINER=	alexbl@FreeBSD.org
COMMENT=	Flash rendering plugin

LIB_DEPENDS=	swfdec-0.6:${PORTSDIR}/graphics/swfdec

USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS=	--with-plugin-dir="${PREFIX}/lib/browser_plugins"

USE_LDCONFIG=	yes

.include <bsd.port.mk>
