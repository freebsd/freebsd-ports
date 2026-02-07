PORTNAME=	sdl12-extralibs
PORTVERSION=	1
CATEGORIES=	misc linux
MASTER_SITES=	EPEL7/s
DISTNAME=

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Additional SDL 1.2 libraries (Linux CentOS ${LINUX_DIST_VER})
WWW=		https://www.libsdl.org/

LICENSE=	LGPL20+

ONLY_FOR_ARCHS=	aarch64 amd64

USES=		linux:c7
USE_LINUX=	sdl12
USE_LINUX_RPM=	yes

.for arch in ${ONLY_FOR_ARCHS}
DISTFILES_${arch}=	SDL_image-1.2.12-11.el7${EXTRACT_SUFX_${arch}}:${arch} \
			SDL_mixer-1.2.12-4.el7${EXTRACT_SUFX_${arch}}:${arch} \
			SDL_ttf-2.0.11-6.el7${EXTRACT_SUFX_${arch}}:${arch}
.endfor

SRC_DISTFILES=	SDL_image-1.2.12-11.el7${SRC_SUFX}:SOURCE \
		SDL_mixer-1.2.12-4.el7${SRC_SUFX}:SOURCE \
		SDL_ttf-2.0.11-6.el7${SRC_SUFX}:SOURCE

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
