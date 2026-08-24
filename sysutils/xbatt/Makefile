PORTNAME=	xbatt
PORTVERSION=	1.3
CATEGORIES=	sysutils

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Laptop battery status display for X11

USE_GITHUB=	yes
GH_ACCOUNT=	plutonull
GH_TAGNAME=	1.3final2

ONLY_FOR_ARCHS=	amd64 i386

USES=		imake:noman xorg
USE_XORG=	ice sm x11 xaw xext xmu xpm xt
PLIST_FILES=	"@(,operator,2755) bin/xbatt"

.include <bsd.port.mk>
