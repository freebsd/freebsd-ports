# New ports collection makefile for:	sdl_net
# Date created:				20 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sdl_net
PORTVERSION=	1.2.4
CATEGORIES=	net
MASTER_SITES=	http://www.libsdl.org/projects/SDL_net/release/
DISTNAME=	SDL_net-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	SDL-1.1.4:${PORTSDIR}/devel/sdl12 \
		GUI.0:${PORTSDIR}/graphics/guilib

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_LIBTOOL=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}"

post-extract:
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|-release \$$\(LT_RELEASE\)||g'

post-configure:
	@${PERL} -pi -e 's|^deplibs_check_method=.*|deplibs_check_method=pass_all|' \
		${WRKSRC}/libtool

.include <bsd.port.mk>
