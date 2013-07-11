# New ports collection makefile for:	castget
# Date created:		16 February 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	castget
PORTVERSION=	1.0.1
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	SAVANNAH CENKES

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line podcast downloader

LIB_DEPENDS=	id3-3.8.3:${PORTSDIR}/audio/id3lib \
		curl:${PORTSDIR}/ftp/curl

USE_LDCONFIG=	yes
USE_GNOME=	glib20 libxml2
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-static
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/castget include/libcastget.h lib/libcastget.la lib/libcastget.so lib/libcastget.so.0
MAN1=	castget.1
MAN5=	castgetrc.5

.include <bsd.port.mk>
