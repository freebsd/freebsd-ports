# New ports collection makefile for:	xenophilia
# Date Created:				1 June 2000
# Whom:				 	Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xenophilia
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_THEMES}
MASTER_SITE_SUBDIR=	xenophilia
DISTNAME=	xenophilia-1.2.x

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Xenophilia theme module to make GTK+ look nicer

WRKSRC=		${WRKDIR}/Xenophilia-0.7

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
ALL_TARGET=	# empty
MAKE_ENV=	GTK-CONFIG="${GTK_CONFIG}"

.include <bsd.port.mk>
