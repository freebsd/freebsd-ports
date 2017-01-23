# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sdl_net
PORTVERSION=	1.2.8
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://www.libsdl.org/projects/SDL_net/release/
DISTNAME=	SDL_net-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small sample cross-platform networking library

LICENSE=	ZLIB

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gmake libtool pathfix pkgconfig
USE_LDCONFIG=	yes
USE_SDL=	sdl

CONFIGURE_ARGS=	--disable-gui

.include <bsd.port.mk>
