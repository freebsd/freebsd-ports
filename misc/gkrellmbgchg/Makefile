# New ports collection makefile for:	gkrellmbgchg
# Date Created:			8 Aug 2002
# Whom:				Chris Stuart <firewolf@lightningfire.net>
#
# $FreeBSD$
#

PORTNAME=	gkrellmbgchg
PORTVERSION=	0.0.3
CATEGORIES=	misc
MASTER_SITES=	http://www.personal.uni-jena.de/~p6best/comp/sources/

MAINTAINER=	firewolf@lightningfire.net

BUILD_DEPENDS=	${X11BASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm

WRKSRC=		${WRKDIR}/gkrellmbgchg-${PORTVERSION}
USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	imlib

.include <bsd.port.mk>
