# Created by: ijliao
# $FreeBSD$

PORTNAME=	dumpmpeg
PORTVERSION=	0.6
PORTREVISION=	8
CATEGORIES=	multimedia graphics
MASTER_SITES=	SF

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Dump frames from mpeg movies

LIB_DEPENDS=	libsmpeg.so:${PORTSDIR}/multimedia/smpeg

GNU_CONFIGURE=	yes
USE_SDL=	sdl

PLIST_FILES=	bin/dumpmpeg \
		man/man1/dumpmpeg.1.gz

.include <bsd.port.mk>
