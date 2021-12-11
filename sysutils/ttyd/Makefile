PORTNAME=	ttyd
DISTVERSION=	1.6.3
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Program to share your terminal over the web

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	xxd:editors/vim
LIB_DEPENDS=	libjson-c.so:devel/json-c \
		libuv.so:devel/libuv \
		libwebsockets.so:net/libwebsockets

USES=		cmake pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	tsl0922

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/ttyd.1.gz

.include <bsd.port.mk>
