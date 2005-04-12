# New ports collection makefile for:	xdaliclock
# Date created:				10th February 1995
# Whom:					gpalmer
#
# $FreeBSD$
#

PORTNAME=	xdaliclock
PORTVERSION=	2.20
CATEGORIES=	x11-clocks
MASTER_SITES=	http://www.jwz.org/xdaliclock/ \
		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A rather neat animated clock

WRKSRC=		${WRKDIR}/${DISTNAME}/X11

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
MAN1=		xdaliclock.1
PLIST_FILES=	bin/xdaliclock

.include <bsd.port.mk>
