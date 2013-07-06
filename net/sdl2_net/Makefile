# $FreeBSD$

PORTNAME=	sdl2_net
PORTVERSION=	2.0.p2
CATEGORIES=	net
MASTER_SITES=	http://www.libsdl.org/tmp/SDL_net/release/
DISTNAME=	SDL2_net-2.0.0

MAINTAINER=	mva@FreeBSD.org
COMMENT=	A small sample cross-platform networking library

USE_AUTOTOOLS=	libtool
USE_SDL=	sdl2
USES=		pathfix pkgconfig:build
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS+=--disable-gui

.include <bsd.port.mk>
