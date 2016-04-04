# Created by: Helko Glathe <glathe.helko@googlemail.com>
# $FreeBSD$

PORTNAME=	clamz
PORTVERSION=	0.5
PORTREVISION=	4
CATEGORIES=	net audio
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	glathe.helko@googlemail.com
COMMENT=	Command-line program to download MP3 files from Amazon's music store

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libgcrypt.so:security/libgcrypt

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GNU_CONFIGURE=	yes
USES=		pkgconfig

.include <bsd.port.mk>
