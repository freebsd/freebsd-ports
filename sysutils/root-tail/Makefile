PORTNAME=	root-tail
DISTVERSION=	1.3
CATEGORIES=	sysutils
MASTER_SITES=	http://dist.schmorp.de/${PORTNAME}/

MAINTAINER=	drtr0jan@yandex.ru
COMMENT=	Print text directly to X11 root window

LICENSE=	GPLv2+

LIB_DEPENDS=	libXfixes.so:x11/libXfixes

USES=		imake xorg
USE_XORG=	x11 xext

PLIST_FILES=	bin/root-tail \
		man/man1/root-tail.1.gz

.include <bsd.port.mk>
