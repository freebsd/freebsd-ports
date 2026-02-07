PORTNAME=	xdaliclock
PORTVERSION=	2.44
PORTREVISION=	1
CATEGORIES=	x11-clocks
MASTER_SITES=	https://www.jwz.org/xdaliclock/
PKGNAMESUFFIX=	-classic

MAINTAINER=	glebius@FreeBSD.org
COMMENT=	Rather neat animated clock (Xlib version)
WWW=		https://www.jwz.org/xdaliclock/

USES=		xorg
USE_XORG=	ice sm x11 xext xt

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
PORTSCOUT=	limit:^2\.44
CONFLICTS=	xdaliclock
WRKSRC=		${WRKDIR}/${DISTNAME}/X11

PLIST_FILES=	bin/xdaliclock \
		share/man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
