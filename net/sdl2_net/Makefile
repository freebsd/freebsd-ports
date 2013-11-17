# $FreeBSD$

PORTNAME=	sdl2_net
PORTVERSION=	2.0.0
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.libsdl.org/projects/SDL_net/release/
DISTNAME=	SDL2_net-${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	A small sample cross-platform networking library

LICENSE=	ZLIB

USE_AUTOTOOLS=	libtool
USE_SDL=	sdl2
USES=		pathfix pkgconfig:build gmake
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS+=--disable-gui

.include <bsd.port.mk>
