# New ports collection makefile for:	xdaliclock
# Date created:				10th February 1995
# Whom:					gpalmer
#
# $FreeBSD$
#

PORTNAME=	xdaliclock
PORTVERSION=	2.18
CATEGORIES=	x11-clocks
MASTER_SITES=	http://www.jwz.org/xdaliclock/ \
		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications

MAINTAINER=	gpalmer@FreeBSD.org

MAN1=		xdaliclock.1

WRKSRC=		${WRKDIR}/${DISTNAME}/X11

CONFIGURE_ARGS+=	--prefix=${X11BASE}
HAS_CONFIGURE=	YES
USE_X_PREFIX=	YES

.include <bsd.port.mk>
