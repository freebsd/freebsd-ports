# New ports collection makefile for:	Aileron
# Date created:				3 Sep 2002
# Whom:			Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	aileron
PORTVERSION=	0.1.3
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://ucsu.colorado.edu/~nwanua/Aileron/
DISTNAME=	Aileron-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WINGs mail client

LIB_DEPENDS=	c-client4.8:${PORTSDIR}/mail/cclient
BUILD_DEPENDS=	${X11BASE}/bin/get-wings-flags:${PORTSDIR}/x11-wm/windowmaker

USE_X_PREFIX=	yes
USE_XPM=	yes

.include <bsd.port.mk>
