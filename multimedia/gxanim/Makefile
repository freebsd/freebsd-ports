# New ports collection makefile for:	xanim
# Version required:     0.45
# Date created:         Sat Nov 5 11:43:03 PST 1994
# Whom:                 Rod Taylor
#
# $FreeBSD$
#

DISTNAME=	gxanim-0.45
CATEGORIES=	graphics
MASTER_SITES=	http://www.iag.net/~aleris/

MAINTAINER=	rod@idiotswitch.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12
RUN_DEPENDS=	xanim:${PORTSDIR}/graphics/xanim

GTK_CONFIG= 	${X11BASE}/bin/gtk12-config

USE_XLIB=	yes

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/gxanim
MAKE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

.include <bsd.port.mk>
