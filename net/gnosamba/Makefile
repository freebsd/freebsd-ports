# New ports collection makefile for:	gtksamba
# Date created:				4 November 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	gtksamba
PORTVERSION=	0.3.2.1
CATEGORIES=	net
MASTER_SITES=	http://www.open-systems.com/gtksamba/
DISTNAME=	${PORTNAME}-0.3.2pl1

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnomeui.3:${PORTSDIR}/x11/gnomelibs

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

.include <bsd.port.mk>
