# New ports collection makefile for:	xanim
# Date created:         Sat Nov 5 11:43:03 PST 1994
# Whom:                 Rod Taylor
#
# $FreeBSD$
#

PORTNAME=	gxanim
PORTVERSION=	0.50
CATEGORIES=	graphics
MASTER_SITES=	http://www.iag.net/~aleris/ \
		http://www.zort.on.ca/software/

MAINTAINER=	rbt@zort.on.ca

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12
RUN_DEPENDS=	xanim:${PORTSDIR}/graphics/xanim

GTK_CONFIG= 	${X11BASE}/bin/gtk12-config

USE_XLIB=	yes

USE_BZIP2=	yes
MAKE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

.include <bsd.port.mk>
