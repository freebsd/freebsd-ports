# ex:ts=8
# New ports collection makefile for:	enjoympeg
# Date created:			Jun 3, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	enjoympeg
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://people.freenet.de/for_Ki/

MAINTAINER=	ijliao@FreeBSD.org
COMMENT=	An MPEG-1 video player

LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12 \
		smpeg:${PORTSDIR}/multimedia/smpeg

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDL_CONFIG=${SDL_CONFIG}

.include <bsd.port.mk>
