# ex:ts=8
# Ports collection makefile for:	gambit
# Date created:			Feb 8, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gambit
PORTVERSION=	0.97.0.5
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library of tools for doing computation in game theory

LIB_DEPENDS=	wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk2

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	WX_CONFIG=${X11BASE}/bin/wxgtk2-2.4-config
MAKE_ENV=	WX_CONFIG=${X11BASE}/bin/wxgtk2-2.4-config

.include <bsd.port.mk>
