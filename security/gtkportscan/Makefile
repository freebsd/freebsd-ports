# New ports collection makefile for:	gtkportscan
# Date created:		11 March 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtkportscan
PORTVERSION=	1.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	cpiazza

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG?=   ${X11BASE}/bin/gtk12-config

WRKSRC=                ${WRKDIR}/${PORTNAME}
MAKE_ENV=      GTK_CONFIG="${GTK_CONFIG}"

.include <bsd.port.mk>
