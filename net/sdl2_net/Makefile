# $FreeBSD$

PORTNAME=	sdl2_net
PORTVERSION=	2.0.1
CATEGORIES=	net
MASTER_SITES=	https://www.libsdl.org/projects/SDL_net/release/
DISTNAME=	SDL2_net-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Small sample cross-platform networking library

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USE_SDL=	sdl2
USES=		gmake libtool pathfix pkgconfig:build sdl
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--disable-gui

.include <bsd.port.mk>
