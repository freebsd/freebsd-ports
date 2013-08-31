# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sdl_net
PORTVERSION=	1.2.8
CATEGORIES=	net
MASTER_SITES=	http://www.libsdl.org/projects/SDL_net/release/
DISTNAME=	SDL_net-${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	A small sample cross-platform networking library

USE_AUTOTOOLS=	libtool
USE_SDL=	sdl
USES=		gmake pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS+=--disable-gui

post-configure:
	@${REINPLACE_CMD} -e \
		's|^deplibs_check_method=.*|deplibs_check_method=pass_all|' \
			${WRKSRC}/libtool

.include <bsd.port.mk>
