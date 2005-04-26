# New ports collection makefile for:	sdl_net
# Date created:				20 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sdl_net
PORTVERSION=	1.2.5
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.libsdl.org/projects/SDL_net/release/
DISTNAME=	SDL_net-${PORTVERSION}

MAINTAINER=	krion@FreeBSD.org
COMMENT=	A small sample cross-platform networking library

LIB_DEPENDS=	GUI.0:${PORTSDIR}/graphics/guilib

USE_SDL=	sdl
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_INC_LIBTOOL_VER=13
LIBTOOLFLAGS=	--disable-ltlibs --release-ignore
INSTALLS_SHLIB=	yes

post-configure:
	@${REINPLACE_CMD} -e \
		's|^deplibs_check_method=.*|deplibs_check_method=pass_all|' \
			${WRKSRC}/libtool

.include <bsd.port.mk>
