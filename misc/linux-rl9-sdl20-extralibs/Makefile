PORTNAME=	sdl20-extralibs
PORTVERSION=	1
CATEGORIES=	misc linux
MASTER_SITES=	EPEL9
DISTNAME=

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Additional SDL 2.0 libraries (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.libsdl.org/

LICENSE=	LGPL20+

USES=		linux:rl9
USE_LINUX=	imageformats-libs sdl20
USE_LINUX_RPM=	yes

BIN_DISTNAMES=	SDL2_image-2.8.2-1.el9

LIB_DISTNAMES=	SDL2_gfx-1.0.4-10.el9 \
		SDL2_image-2.8.2-1.el9 \
		SDL2_net-2.2.0-3.el9 \
		SDL2_mixer-2.8.1-1.el9 \
		SDL2_ttf-2.20.2-1.el9

SRC_DISTFILES=	SDL2_gfx-1.0.4-10.el9${SRC_SUFX}:SOURCE \
		SDL2_image-2.8.2-1.el9${SRC_SUFX}:SOURCE \
		SDL2_net-2.2.0-3.el9${SRC_SUFX}:SOURCE \
		SDL2_mixer-2.8.1-1.el9${SRC_SUFX}:SOURCE \
		SDL2_ttf-2.20.2-1.el9${SRC_SUFX}:SOURCE

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
