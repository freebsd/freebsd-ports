PORTNAME=	unclutter
DISTVERSION=	8
PORTREVISION=	5
CATEGORIES=	misc
MASTER_SITES=	XCONTRIB/utilities

MAINTAINER=	mce@FreeBSD.org
COMMENT=	Remove idle cursor image from screen

LICENSE=	PD

USES=		imake tar:Z xorg
USE_XORG=	x11 xext xorgproto

CONFLICTS_INSTALL=	unclutter-xfixes

WRKSRC=		${WRKDIR}/unclutter

PLIST_FILES=	bin/unclutter \
		share/man/man1/unclutter.1.gz

.include <bsd.port.mk>
