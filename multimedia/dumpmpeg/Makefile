# ex:ts=8
# New ports collection makefile for:	dumpmpeg
# Date created:			Jun 3, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	dumpmpeg
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	multimedia graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ijliao@FreeBSD.org
COMMENT=	Dump frames from mpeg movies

LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12 \
		smpeg:${PORTSDIR}/multimedia/smpeg

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDL_CONFIG=${SDL_CONFIG}

MAN1=		dumpmpeg.1
PLIST_FILES=	bin/dumpmpeg

.include <bsd.port.mk>
