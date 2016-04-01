# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	logstalgia
PORTVERSION=	1.0.3
PORTREVISION=	8
CATEGORIES=	sysutils www
MASTER_SITES=	GOOGLE_CODE LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Website access log visualization tool

LICENSE=	GPLv3

LIB_DEPENDS=	libftgl.so:graphics/ftgl \
		libpng.so:graphics/png \
		libpcre.so:devel/pcre

GNU_CONFIGURE=	yes
USES=		jpeg pkgconfig
USE_SDL=	sdl image

CFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
