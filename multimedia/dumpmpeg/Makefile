# ex:ts=8
# New ports collection makefile for:	dumpmpeg
# Date created:			Jun 3, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	dumpmpeg
PORTVERSION=	0.6
PORTREVISION=	5
CATEGORIES=	multimedia graphics
MASTER_SITES=	SF

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Dump frames from mpeg movies

LIB_DEPENDS=	smpeg:${PORTSDIR}/multimedia/smpeg

GNU_CONFIGURE=	yes
USE_SDL=	sdl

MAN1=		dumpmpeg.1
PLIST_FILES=	bin/dumpmpeg

.include <bsd.port.mk>
