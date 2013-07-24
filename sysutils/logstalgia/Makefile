# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	logstalgia
PORTVERSION=	1.0.3
PORTREVISION=	5
CATEGORIES=	sysutils www
MASTER_SITES=	GOOGLE_CODE CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Website access log visualization tool

LICENSE=	GPLv3

LIB_DEPENDS=	ftgl:${PORTSDIR}/graphics/ftgl \
		png15:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		pcre.3:${PORTSDIR}/devel/pcre

GNU_CONFIGURE=	yes
USES=		pkgconfig
USE_SDL=	sdl image

CFLAGS+=	-L/usr/local/lib -I/usr/local/include

MANCOMPRESSED=	yes

MAN1=		logstalgia.1

.include <bsd.port.mk>
