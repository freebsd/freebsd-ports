# ex:ts=8
# Ports collection makefile for:	xtheater
# Date created:			Jun 7, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xtheater
PORTVERSION=	1.0.0p1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	Xtheater-${PORTVERSION:S/p/-pre/}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	SDL-1.1:${PORTSDIR}/devel/sdl12 \
		smpeg:${PORTSDIR}/graphics/smpeg \
		aviplay-0.7:${PORTSDIR}/graphics/avifile

USE_BZIP2=	yes
USE_XLIB=	yes
USE_GTK=	yes
USE_MESA=	yes
SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" \
		CPPFLAGS="${CXXFLAGS} -I${LOCALBASE} ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE} ${PTHREAD_LIBS}"
USE_GMAKE=	yes

.include <bsd.port.mk>
