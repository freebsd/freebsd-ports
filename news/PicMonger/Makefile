# New ports collection makefile for:	PicMonger
# Date created:			23 July 2000
# Whom:				Donald Burr <dburr@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	PicMonger
PORTVERSION=	0.9.6
CATEGORIES=	news graphics
MASTER_SITES=	http://download.sourceforge.net/PicMonger/

MAINTAINER=	dburr@FreeBSD.ORG

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		gtkmm-1.2:${PORTSDIR}/x11-toolkits/gtk--
RUN_DEPENDS=	mpack:${PORTSDIR}/converters/mpack

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

.include <bsd.port.mk>
