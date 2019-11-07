# Created by: gpalmer
# $FreeBSD$

PORTNAME=	xdaliclock
PORTVERSION=	2.44
CATEGORIES=	x11-clocks
MASTER_SITES=	http://www.jwz.org/xdaliclock/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rather neat animated clock

WRKSRC=		${WRKDIR}/${DISTNAME}/X11

GNU_CONFIGURE=	yes
USES=		xorg
USE_XORG=	xt sm ice xext x11
PLIST_FILES=	bin/xdaliclock man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
