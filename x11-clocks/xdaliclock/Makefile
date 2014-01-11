# Created by: gpalmer
# $FreeBSD$

PORTNAME=	xdaliclock
PORTVERSION=	2.40
CATEGORIES=	x11-clocks
MASTER_SITES=	http://www.jwz.org/xdaliclock/
MASTER_SITE_SUBDIR=	applications

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	A rather neat animated clock

WRKSRC=		${WRKDIR}/${DISTNAME}/X11

GNU_CONFIGURE=	yes
USE_XORG=	xt sm ice xext x11
PLIST_FILES=	bin/xdaliclock man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
