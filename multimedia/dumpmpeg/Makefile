PORTNAME=	dumpmpeg
PORTVERSION=	0.6
PORTREVISION=	11
CATEGORIES=	multimedia graphics
MASTER_SITES=	SF

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Dump frames from mpeg movies

LIB_DEPENDS=	libsmpeg.so:multimedia/smpeg

USES=		sdl
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USE_SDL=	sdl

PLIST_FILES=	bin/dumpmpeg \
		share/man/man1/dumpmpeg.1.gz

.include <bsd.port.mk>
