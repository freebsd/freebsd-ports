PORTNAME=	ttyd
DISTVERSION=	1.7.3
CATEGORIES=	sysutils

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Program to share your terminal over the web
WWW=		https://github.com/tsl0922/ttyd

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
		share/man/man1/ttyd.1.gz

.include <bsd.port.mk>
