PORTNAME=	root-tail
DISTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://dist.schmorp.de/${PORTNAME}/

MAINTAINER=	drtr0jan@yandex.ru
COMMENT=	Print text directly to X11 root window
WWW=		http://software.schmorp.de/pkg/root-tail.html

LICENSE=	GPLv2+

LIB_DEPENDS=	libXfixes.so:x11/libXfixes

USES=		imake xorg
USE_XORG=	x11 xext

PLIST_FILES=	bin/root-tail \
		share/man/man1/root-tail.1.gz

.include <bsd.port.mk>
