PORTNAME=	sdl3_net
DISTVERSIONPREFIX=	release-
DISTVERSION=	3.2.0
CATEGORIES=	net

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Simple, cross-platform wrapper over TCP/IP sockets
WWW=		https://github.com/libsdl-org/SDL_net

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake sdl
USE_GITHUB=	yes
GH_ACCOUNT=	libsdl-org
GH_PROJECT=	SDL_net
USE_SDL=	sdl3
USE_LDCONFIG=	yes
CMAKE_OFF=	SDLNET_SAMPLES

PLIST_SUB=	LIBVERSION=${DISTVERSION:C/[0-9]+/0/1}

.include <bsd.port.mk>
