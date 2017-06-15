# Created by: Helko Glathe <glathe.helko@googlemail.com>
# $FreeBSD$

PORTNAME=	clamz
PORTVERSION=	0.5
PORTREVISION=	4
CATEGORIES=	net audio
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line program to download MP3 files from Amazon's music store

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libgcrypt.so:security/libgcrypt

BROKEN=		Unfetchable (google code has gone away)
DEPRECATED=	Unfetchable for more than six months (google code has gone away)
EXPIRATION_DATE=	2017-04-30

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GNU_CONFIGURE=	yes
USES=		pkgconfig

.include <bsd.port.mk>
