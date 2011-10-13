# New ports collection makefile for:	logstalgia
# Date created:				13 Oct 2011
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	logstalgia
PORTVERSION=	1.0.3
CATEGORIES=	sysutils www
MASTER_SITES=	GOOGLE_CODE CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A website access log visualization tool

LICENSE=	GPLv3

LIB_DEPENDS=	ftgl:${PORTSDIR}/graphics/ftgl \
		png.6:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		pcre.0:${PORTSDIR}/devel/pcre

GNU_CONFIGURE=	yes
USE_SDL=	sdl image

MANCOMPRESSED=	yes

MAKE_JOBS_SAFE=	yes

MAN1=		logstalgia.1

.include <bsd.port.mk>
