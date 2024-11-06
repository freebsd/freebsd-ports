PORTNAME=	recmpeg
PORTVERSION=	1.0.5
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	SF/fame/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple video encoder
WWW=		https://fame.sourceforge.net/

DEPRECATED=	Depends on deprecated and obsolete library libfame, consider migrating to multimedia/ffmpeg
EXPIRATION_DATE=2024-12-31

LIB_DEPENDS=	libfame.so:multimedia/libfame

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/recmpeg \
		share/man/man1/recmpeg.1.gz

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
