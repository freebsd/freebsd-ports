# New ports collection makefile for:    totem
# Date created:         17 Oct 2002
# Whom:                 Hendrik Scholz <hendrik@scholz.net>
#
# $FreeBSD$
#

PORTNAME=	totem
PORTVERSION=	0.10.0
CATEGORIES=	graphics gnome
MASTER_SITES=	http://www.hadess.net/files/software/totem/

MAINTAINER=	hendrik@scholz.net

LIB_DEPENDS=	xine.2:${PORTSDIR}/graphics/libxine \
		gnomeui-2.0:${PORTSDIR}/x11-toolkits/libgnomeui

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
