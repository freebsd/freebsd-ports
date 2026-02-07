PORTNAME=	unclutter
PORTVERSION=	8
PORTREVISION=	4
CATEGORIES=	misc
MASTER_SITES=	XCONTRIB/utilities

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Remove idle cursor image from screen

WRKSRC=		${WRKDIR}/unclutter
USES=		imake tar:Z xorg
USE_XORG=	x11 xext

PLIST_FILES=	bin/unclutter \
		share/man/man1/unclutter.1.gz

.include <bsd.port.mk>
