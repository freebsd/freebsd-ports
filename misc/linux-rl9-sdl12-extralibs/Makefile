PORTNAME=	sdl12-extralibs
PORTVERSION=	1
CATEGORIES=	misc linux
MASTER_SITES=	EPEL9
DISTNAME=

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Additional SDL 1.2 libraries (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.libsdl.org/

LICENSE=	LGPL20+

USES=		linux:rl9
USE_LINUX=	imageformats-libs sdl12
USE_LINUX_RPM=	yes

BIN_DISTNAMES=	SDL_image-1.2.12-31.el9

LIB_DISTNAMES=	SDL_gfx-2.0.27-3.el9 \
		SDL_image-1.2.12-31.el9 \
		SDL_net-1.2.8-27.el9 \
		SDL_sound-1.0.3-37.el9 \
		SDL_ttf-2.0.11-29.el9

SRC_DISTFILES=	SDL_gfx-2.0.27-3.el9${SRC_SUFX}:SOURCE \
		SDL_image-1.2.12-31.el9${SRC_SUFX}:SOURCE \
		SDL_net-1.2.8-27.el9${SRC_SUFX}:SOURCE \
		SDL_sound-1.0.3-37.el9${SRC_SUFX}:SOURCE \
		SDL_ttf-2.0.11-29.el9${SRC_SUFX}:SOURCE

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
