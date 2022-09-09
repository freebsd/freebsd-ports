PORTNAME=	sdl2_net
DISTVERSIONPREFIX=	release-
DISTVERSION=	2.2.0
CATEGORIES=	net

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Small sample cross-platform networking library
WWW=		https://github.com/libsdl-org/SDL_net

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake sdl
USE_GITHUB=	yes
GH_ACCOUNT=	libsdl-org
GH_PROJECT=	SDL_net
USE_SDL=	sdl2
USE_LDCONFIG=	yes
CMAKE_OFF=	SDL2NET_SAMPLES
CMAKE_ARGS=	-DSDL2NET_DEBUG_POSTFIX:STRING=

.include <bsd.port.mk>
