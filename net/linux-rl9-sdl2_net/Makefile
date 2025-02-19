PORTNAME=	sdl2_net
PORTVERSION=	2.2.0
DISTVERSIONSUFFIX=	-3.el9
CATEGORIES=	net linux
MASTER_SITES=	EPEL9
DISTNAME=	SDL2_net-${DISTVERSIONFULL}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Small sample cross-platform networking library (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://github.com/libsdl-org/SDL_net

LICENSE=	ZLIB

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	sdl20
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/SDL2_net

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
