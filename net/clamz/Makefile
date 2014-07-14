# Created by: Helko Glathe <glathe.helko@googlemail.com>
# $FreeBSD$

PORTNAME=	clamz
PORTVERSION=	0.5
PORTREVISION=	2
CATEGORIES=	net audio
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	glathe.helko@googlemail.com
COMMENT=	Command-line program to download MP3 files from Amazon's music store

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GNU_CONFIGURE=	yes
USES=		pkgconfig

.include <bsd.port.mk>
